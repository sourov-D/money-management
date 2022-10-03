CC=gcc
CFLAGS=-c -g
LFLAGS= -o
BIN=main
OBJ=*.o
CFILES=*.c

all:
	$(CC) $(CFLAGS) $(CFILES)
	$(CC) $(LFLAGS) $(BIN) $(OBJ)
	
clean:
	rm -f $(OBJ)
	rm -f $(BIN)


