CC = gcc
FLAGS = -Wall -g

all: isort txtfind

isort: mainSort.o inSort.o
	$(CC) $(FLAGS) -o isort mainSort.o inSort.o
	
mainSort.o: mainSort.c 
	$(CC) $(FLAGS) -c mainSort.c

inSort.o: inSort.c
	$(CC) $(FLAGS) -c inSort.c

txtfind: mainFind.o textFind.o
	$(CC) $(FLAGS) -o txtfind mainFind.o textFind.o

mainFind.o: mainFind.c
	$(CC) $(FLAGS) -c mainFind.c

textFind.o: textFind.c textFind.h
	$(CC) $(FLAGS) -c textFind.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind
