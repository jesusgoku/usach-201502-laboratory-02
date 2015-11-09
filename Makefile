CC=gcc
CFLAGS=-I./libs -std=c99
DEPS = libs/board.h libs/colors.h libs/utilities.h
OBJ = main.o libs/board.o libs/colors.o libs/utilities.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

.PHONY: clean start

start:
	./main

clean:
	rm -f main.o libs/*.o main
