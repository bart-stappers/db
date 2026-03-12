#include "meta.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MetaCommandResult do_meta_command(Buffer *buffer)
{
	if (strcmp(buffer->input_buffer, ".exit") == 0) {
		close_buffer(buffer);
		exit(EXIT_SUCCESS);
	} else {
		return META_COMMAND_UNKNOWN_COMMAND;
	}
}

