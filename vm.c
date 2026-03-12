#include "vm.h"

#include <stdio.h>

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


