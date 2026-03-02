#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer *new_input_buffer() {
   InputBuffer *input_buffer = malloc(sizeof(InputBuffer));
   
   input_buffer->buffer = NULL;
   input_buffer->buffer_length = 0;
   input_buffer->input_length = 0;

   return input_buffer;
}

void print_prompt() {
    printf("db > ");
}

int main(int argc, char *argv[]) {
    InputBuffer *input_buffer = new_input_buffer();

    while (true) {
        print_prompt();
    }

    return 0;
}
