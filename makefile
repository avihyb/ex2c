AR = ar 
CC = gcc 
FLAGS = -Wall

all: my_graph libmymat.a

my_graph: main.o libmymat.a
	$(CC) $(FLAGS) -o my_graph main.o -L. -lmymat

libmymat.a: my_mat.o 
	$(AR) rcs libmymat.a my_mat.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

clean:
	rm -f *.a *.o my_graph
