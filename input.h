#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>
#include <sys/types.h>

typedef struct {
	char *input_buffer;
	size_t buffer_size;
	ssize_t input_size;
} Buffer;

Buffer *create_buffer(void);
void read_input(Buffer *buffer);
void close_buffer(Buffer *buffer);

#endif
