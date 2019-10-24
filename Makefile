CC=gcc
CFLAGS=-I. -Wall
DEPS = list.h path.h tree.h exit.h
OBJ = shell.o list.o path.o tree.o exit.o 

all: $(OBJ) clean

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

shell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o $(objects)