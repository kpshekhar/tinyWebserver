CC = gcc
CFLAGS = -O2 -Wall -I .

# This flag includes the Pthreads library on a Linux box.
# Others systems will probably require something different.
LIB = -pthread

all: tiny cgi

tiny: tiny.c csapp.o spin_delay.o
	$(CC) $(CFLAGS) -o tiny tiny.c csapp.o spin_delay.o $(LIB)

csapp.o:
	$(CC) $(CFLAGS) -c csapp.c

spin_delay.o:
	$(CC) $(CFLAGS) -c spin_delay.c $(LIB)

cgi:
	(cd cgi-bin; make)

clean:
	rm -f *.o tiny *~
	(cd cgi-bin; make clean)

