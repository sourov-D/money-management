cc=gcc
cflags=-c -g
lflags= -o
bin=main
obj=*.o
cfiles=*.c

all:
	$(cc) $(cflags) $(cfiles)
	$(cc) $(lflags) $(bin) $(obj)
	
clean:
	rm -f $(obj)
	rm -f $(bin)