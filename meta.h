#ifndef META_H
#define META_H

#include "input.h"

typedef enum {
	META_COMMAND_SUCCESS,
	META_COMMAND_UNKNOWN_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(Buffer *buffer);

#endif
