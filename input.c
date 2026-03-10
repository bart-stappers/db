#include "input.h"

#include <stdio.h>
#include <stdlib.h>

Buffer *create_buffer()
{
	Buffer *buffer = malloc(sizeof(Buffer));

	buffer->input_buffer = NULL;
	buffer->buffer_size = 0;
	buffer->input_size = 0;

	return buffer;
}

void read_input(Buffer *buffer)
{
	ssize_t chars_read =
		getline(&buffer->input_buffer, &buffer->buffer_size, stdin);

	if (chars_read <= 0) {
		printf("Error reading input\n");
		exit(EXIT_FAILURE);
	}

	// Required for the close_buffer condition
	buffer->input_size = chars_read - 1;
	buffer->input_buffer[chars_read - 1] = '\0';
}

void close_buffer(Buffer *buffer)
{
	free(buffer->input_buffer);
	free(buffer);
}

