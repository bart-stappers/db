#include "compiler.h"

#include <string.h>

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

