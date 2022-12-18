CC = gcc -g 
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11
TEST_FLAGS = $(shell pkg-config --libs --cflags check) 

TEST_DIRS = tests 
TEST_SRC_FILES = $(foreach D, $(TEST_DIRS), $(wildcard $(D)/*.c))
TEST_OBJ_FILES = $(patsubst %.c, %.o, $(TEST_SRC_FILES))


all:
	$(CC) dev.c backend.c 

install:
	mkdir ../build
	cmake -S . ../build
	cmake --build ../build

uninstall:

dvi:

gcov_report:

tests:
	echo "$(TEST_SRC_FILES)"
	$(CC) backend.c $(TEST_SRC_FILES) -I. -Itests -o run_tests $(TEST_FLAGS) 
	./run_tests

clean:
	rm -rf *a.out *.o
	rm -rf *.dSYM run_tests
