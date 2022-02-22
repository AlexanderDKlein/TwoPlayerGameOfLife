all : conway.c board.c board.h
	gcc -g -Wall -o conway.out conway.c board.c

clean:
	rm *.out
