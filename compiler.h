#ifndef COMPILER_H
#define COMPILER_H

#include "input.h"
#include "row.h"

typedef enum {
	PREPARE_SUCCESS,
	PREPARE_SYNTAX_ERROR,
	PREPARE_UNKNOWN_STATEMENT
} PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
	StatementType type;
	Row row_to_insert;
} Statement;

PrepareResult prepare_statement(Buffer *buffer, Statement *statement);

#endif
