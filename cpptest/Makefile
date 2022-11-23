
all: exec
	
exec: ex.o main.o
	g++ ex.o main.o

ex.o: 
	g++ ex.c -c

main.o:
	g++ main.cpp -c 

clean: 
	rm *.o *.out
