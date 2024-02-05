CC=gcc
AR=ar
OBJECT_MAIN=main_mat.o
OBJECT_MAIND=maind.o
OBJECT_LIB=my_mat.o
FLAGS= -Wall -g

all: main_mat my_mat.a maind
mat: main_mat my_mat.a
din: maind

main_mat: $(OBJECT_MAIN) my_mat.a
	$(CC) $(FLAGS) -o main_mat $(OBJECT_MAIN) my_mat.a
maind: $(OBJECT_MAIND)
	$(CC) $(FLAGS) -o maind $(OBJECT_MAIND)
my_mat.a: $(OBJECT_LIB)
	$(AR) -rcs my_mat.a $(OBJECT_LIB)


main_mat.o: main_mat.c my_mat.h
	$(CC) $(FLAGS) -c main_mat.c
maind.o: maind.c
	$(CC) $(FLAGS) -c maind.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.a   main_mat maind