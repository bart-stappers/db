#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char *input_buffer;
	size_t buffer_size;
	ssize_t input_size;
} Buffer;

typedef enum {
	META_COMMAND_SUCCESS,
	META_COMMAND_UNKNOWN_COMMAND
} MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNKNOWN_STATEMENT } PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
	StatementType type;
} Statement;

Buffer *create_buffer()
{
	Buffer *buffer = malloc(sizeof(Buffer));

	buffer->input_buffer = NULL;
	buffer->buffer_size = 0;
	buffer->input_size = 0;

	return buffer;
}

void print_prompt()
{
	printf("db > ");
}

void read_input(Buffer *buffer)
{
	ssize_t chars_read =
		getline(&buffer->input_buffer, &buffer->buffer_size, stdin);

	if (chars_read <= 0) {
		printf("Error reading input\n");
		exit(EXIT_FAILURE);
	}

	// Required for the close_buffer condition
	buffer->input_size = chars_read - 1;
	buffer->input_buffer[chars_read - 1] = '\0';
}

void close_buffer(Buffer *buffer)
{
	free(buffer->input_buffer);
	free(buffer);
}

// Wrapper for existing functionality
MetaCommandResult do_meta_command(Buffer *buffer)
{
	if (strcmp(buffer->input_buffer, ".exit") == 0) {
		close_buffer(buffer);
		exit(EXIT_SUCCESS);
	} else {
		return META_COMMAND_UNKNOWN_COMMAND;
	}
}

// Simplistic version of SQL compiler:
// It takes text input and converts it into an internal representation
// (Statement) that the virtual machine can execute.

PrepareResult prepare_statement(Buffer *buffer, Statement *statement)
{
	if (strncmp(buffer->input_buffer, "insert", 6) == 0) {
		statement->type = STATEMENT_INSERT;
		return PREPARE_SUCCESS;
	}
	if (strcmp(buffer->input_buffer, "select") == 0) {
		statement->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}
	return PREPARE_UNKNOWN_STATEMENT;
}

// This is the virtual machine part
void execute_statement(Statement *statement)
{
	switch (statement->type) {
	case (STATEMENT_INSERT):
		printf("This is where we would do and INSERT.\n");
		break;
	case (STATEMENT_SELECT):
		printf("This is where we would do a SELECT.\n");
		break;
	}
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	Buffer *buffer = create_buffer();

	while (true) {
		print_prompt();
		read_input(buffer);

		// Dispatch meta-commands
		if (buffer->input_buffer[0] == '.') {
			switch (do_meta_command(buffer)) {
			case (META_COMMAND_SUCCESS):
				continue;
			case (META_COMMAND_UNKNOWN_COMMAND):
				printf("Unknown command '%s'\n",
				       buffer->input_buffer);
				continue;
			}
		}

		// Dispatch SQL statements
		Statement statement;
		switch (prepare_statement(buffer, &statement)) {
		case (PREPARE_SUCCESS):
			break;
		case (PREPARE_UNKNOWN_STATEMENT):
			printf("Unknown keyword at the start of '%s'.\n",
			       buffer->input_buffer);
			continue;
		}

		execute_statement(&statement);
		printf("Executed.\n");
	}
}
