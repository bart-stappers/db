db: db.c
	gcc -Wall -Wextra -Werror db.c -o db

format: *.c
	clang-format -i *.c
