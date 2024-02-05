AR = ar 
GC = gcc 
FLAGS = -Wall

all: main matlib

mymat: libmymat.a

main: main.o mymat
	$(GC) $(FLAGS) -o main main.o libmymat.a

libmymat.a: my_mat.o 
	$(AR) rcs libmymat.a my_mat.o ranlib libmymat.a

main.o: main.c
	$(GC) $(FLAGS) -c main.c

my_mat.o: my_mat.c
	$(GC) $(FLAGS) -c my_mat.c

clean:
	rm *.so *.a *.o main