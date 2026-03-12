#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "input.h"
#include "meta.h"
#include "compiler.h"

void print_prompt()
{
	printf("db > ");
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
