#include "vm.h"

#include <stdio.h>

static ExecuteResult execute_insert(Statement *statement, Table *table);
static ExecuteResult execute_select(Statement *statement, Table *table);

ExecuteResult execute_statement(Statement *statement, Table *table)
{
	switch (statement->type) {
	case (STATEMENT_INSERT):
		return execute_insert(statement, table);
	case (STATEMENT_SELECT):
		return execute_select(statement, table);
	default:
		return EXECUTE_UNKNOWN_STATEMENT;
	}
}

ExecuteResult execute_insert(Statement *statement, Table *table)
{
	if (table->n_rows >= TABLE_MAX_ROWS) {
		return EXECUTE_TABLE_FULL;
	}

	Row *row_to_insert = &(statement->row_to_insert);
	serialize_row(row_slot(table, table->n_rows), row_to_insert);
	table->n_rows += 1;

	return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement *statement, Table *table)
{
	(void)statement;
	Row row;

	for (uint32_t i = 0; i < table->n_rows; i++) {
		deserialize_row(&row, row_slot(table, i));
		print_row(&row);
	}

	return EXECUTE_SUCCESS;
}
