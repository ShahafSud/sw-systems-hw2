CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_LIB=my_mat.o
FLAGS= -Wall -g

all: main_prog my_mat.a

main_prog: $(OBJECT_MAIN) my_mat.a
	$(CC) $(FLAGS) -o main_prog $(OBJECT_MAIN) my_mat.a
my_mat.a: $(OBJECT_LIB)
	$(AR) -rcs my_mat.a $(OBJECT_LIB)


main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.a   main_prog