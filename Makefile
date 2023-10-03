# Variables
CC = gcc
CFLAGS = -Wall -Wextra
OBJ_NAME = main

all: $(OBJ_NAME)

$(OBJ_NAME): main.o UnitTestFramework.o
	$(CC) main.o UnitTestFramework.o -o $(OBJ_NAME)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

UnitTestFramework.o: UnitTestFramework.c UnitTestFramework.h
	$(CC) $(CFLAGS) -c UnitTestFramework.c -o UnitTestFramework.o

clean:
	rm -f *.o $(OBJ_NAME)