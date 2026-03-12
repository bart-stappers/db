CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = db.c input.c meta.c compiler.c

db: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o db

format:
	clang-format -i *.c *.h

clean:
	rm -f db
