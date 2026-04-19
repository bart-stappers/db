#include "compiler.h"

#include <string.h>
#include <stdio.h>

PrepareResult prepare_statement(Buffer *buffer, Statement *statement)
{
	if (strncmp(buffer->input_buffer, "insert", 6) == 0) {
		statement->type = STATEMENT_INSERT;
		int args_assigned = sscanf(buffer->input_buffer,
					   "insert %d %s %s",
					   &(statement->row_to_insert.id),
					   statement->row_to_insert.username,
					   statement->row_to_insert.email);
		if (args_assigned < 3) {
			return PREPARE_SYNTAX_ERROR;
		}
		return PREPARE_SUCCESS;
	}
	if (strcmp(buffer->input_buffer, "select") == 0) {
		statement->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}
	return PREPARE_UNKNOWN_STATEMENT;
}
