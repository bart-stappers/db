#include "table.h"

#include <stdlib.h>

#include "row.h"

Table *new_table()
{
	Table *table = malloc(sizeof(Table));
	table->n_rows = 0;

	for (uint32_t i = 0; i < TABLE_MAX_PAGES; i++) {
		table->pages[i] = NULL;
	}

	return table;
}

void free_table(Table *table)
{
	for (uint32_t i = 0; table->pages[i]; i++) {
		free(table->pages[i]);
	}

	free(table);
}

void *row_slot(Table *table, uint32_t row_num)
{
	uint32_t page_num = row_num / ROWS_PER_PAGE;
	void *page = table->pages[page_num];

	if (page == NULL) {
		page = table->pages[page_num] = malloc(PAGE_SIZE);
	}

	uint32_t row_offset = row_num % ROWS_PER_PAGE;
	uint32_t byte_offset = row_offset * ROW_SIZE;

	return (char *)page + byte_offset;
}
