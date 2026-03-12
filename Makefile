CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c input.c meta.c compiler.c vm.c

db: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o db

format:
	clang-format -i *.c *.h

clean:
	rm -f db
