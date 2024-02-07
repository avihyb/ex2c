AR = ar 
CC = gcc 
FLAGS = -Wall

all: my_graph my_Knapsack libmymat.a 

my_graph: my_graph.o libmymat.a
	$(CC) $(FLAGS) -o my_graph my_graph.o -L. -lmymat

my_Knapsack: my_Knapsack.o libmymat.a
	$(CC) $(FLAGS) -o my_Knapsack my_Knapsack.o -L. -lmymat

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c

libmymat.a: my_mat.o 
	$(AR) rcs libmymat.a my_mat.o

my_graph.o: my_graph.c
	$(CC) $(FLAGS) -c my_graph.c

my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

clean:
	rm -f *.a *.o my_graph my_Knapsack
