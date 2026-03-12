#ifndef COMPILER_H
#define COMPILER_H

#include "input.h"

typedef enum { PREPARE_SUCCESS, PREPARE_UNKNOWN_STATEMENT } PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
	StatementType type;
} Statement;

PrepareResult prepare_statement(Buffer *buffer, Statement *statement);

#endif
