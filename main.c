#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "input.h"
#include "meta.h"
#include "compiler.h"
#include "vm.h"
#include "table.h"

void print_prompt()
{
	printf("db > ");
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	Table *table = new_table();
	Buffer *buffer = create_buffer();

	while (true) {
		print_prompt();
		read_input(buffer);

		// Dispatch meta-commands
		if (buffer->input_buffer[0] == '.') {
			switch (do_meta_command(buffer, table)) {
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
		case (PREPARE_SYNTAX_ERROR):
			printf("Syntax error. Could not parse statement.\n");
			continue;
		case (PREPARE_UNKNOWN_STATEMENT):
			printf("Unknown keyword at the start of '%s'.\n",
			       buffer->input_buffer);
			continue;
		}

		switch (execute_statement(&statement, table)) {
		case (EXECUTE_SUCCESS):
			printf("Executed.\n");
			break;
		case (EXECUTE_TABLE_FULL):
			printf("Error: Table full.\n");
			break;
		case (EXECUTE_UNKNOWN_STATEMENT):
			printf("Error: Unknown statement type.\n");
			break;
		}
	}
}
