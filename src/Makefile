CC = gcc -g 
CFLAGS = #-Wall -Werror -Wextra 
TEST_FLAGS = $(shell pkg-config --libs --cflags check) 
COVFLAGS = -fprofile-arcs -ftest-coverage
TEST_DIRS = tests 
TEST_SRC_FILES = $(foreach D, $(TEST_DIRS), $(wildcard $(D)/*.c))
TEST_OBJ_FILES = $(patsubst %.c, %.o, $(TEST_SRC_FILES))
KERN = $(shell uname -s)
OPENCOMMAND = 

ifeq ($(KERN), Linux)
	CFALGS += -lm
	OPENCOMMAND += xdg-open
else
	OPENCOMMAND += open
endif


all: install tests

install:
	mkdir ../build
	cmake -S . ../build
	# cmake --build ../build

uninstall:
	rm -rf ../build

dvi:
	$(OPENCOMMAND) ./html/annotated.html

gcov_report:
	$(CC) $(CFLAGS) backend.c $(TEST_SRC_FILES) -I. -Itests -o run_tests_for_coverage $(TEST_FLAGS) $(COVFLAGS)
	./run_tests_for_coverage
	@lcov -t "test_cov" -o report.info -c -d .
	@genhtml -o report report.info
	@rm *.gcno *.gcda run_tests_for_coverage
	open report/index.html

test:
	echo "$(TEST_SRC_FILES)"
	$(CC) backend.c $(TEST_SRC_FILES) -I. -Itests -o run_tests $(TEST_FLAGS) 
	./run_tests

clean:
	rm -rf *a.out *.o
	rm -rf *.dSYM run_tests
	# rm -rf html latex
	@rm *.gcno *.gcda run_tests_for_coverage
	@rm -rf *report

