AR = ar 
CC = gcc 
FLAGS = -Wall

all: my_graph libmymat.a

my_graph: my_graph.o libmymat.a
	$(CC) $(FLAGS) -o my_graph my_graph.o -L. -lmymat

libmymat.a: my_mat.o 
	$(AR) rcs libmymat.a my_mat.o

my_graph.o: my_graph.c
	$(CC) $(FLAGS) -c my_graph.c

my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

clean:
	rm -f *.a *.o my_graph
