CC = gcc -g 
TEST_FLAGS = $(shell pkg-config --libs --cflags check) 

TEST_DIRS = tests 
TEST_SRC_FILES = $(foreach D, $(TEST_DIRS), $(wildcard $(D)/*.c))
TEST_OBJ_FILES = $(patsubst %.c, %.o, $(TEST_SRC_FILES))


all:
	$(CC) dev.c backend.c 


test:
	echo "$(TEST_SRC_FILES)"
	$(CC) $(TEST_FLAGS) backend.c $(TEST_SRC_FILES) -I. -Itests -o run_tests

backend.o:
	$(CC) backend.c -c




clean:
	rm -rf *a.out *.o
	rm -rf *.dSYM run_tests
