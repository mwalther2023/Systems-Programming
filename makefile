all: node head

node: libduSocket.a node.o
	gcc node.o -L. -lduSocket -o node
head: libduSocket.a head.o
	gcc head.o -L. -lduSocket -o head
libduSocket.a: duSocket.o
	ar -cvq libduSocket.a duSocket.o
node.o:	node.c
	gcc node.c -c
head.o: head.c
	gcc head.c -fopenmp -c
duSocket.o: duSocket.c duSocket.h
	gcc duSocket.c -c