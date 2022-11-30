CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic 

all: dev

dev:
	gcc -g -lm dev.c backend.c -fsanitize=address

clean: 
	rm -rf *.out
	rm -rf *.dSYM

