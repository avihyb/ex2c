AR = ar 
CC = gcc 
FLAGS = -Wall

all: main libmymat.a

main: main.o libmymat.a
	$(CC) $(FLAGS) -o main main.o -L. -lmymat

libmymat.a: my_mat.o 
	$(AR) rcs libmymat.a my_mat.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

clean:
	rm -f *.a *.o main
