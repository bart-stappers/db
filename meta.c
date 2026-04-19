#include "meta.h"

#include <stdlib.h>
#include <string.h>

MetaCommandResult do_meta_command(Buffer *buffer, Table *table)
{
	if (strcmp(buffer->input_buffer, ".exit") == 0) {
		close_buffer(buffer);
		free_table(table);
		exit(EXIT_SUCCESS);
	} else {
		return META_COMMAND_UNKNOWN_COMMAND;
	}
}
