CC = cc
CFLAGS = -lm -Wall -Wextra -pedantic -std=c11 -lm

all: todgred

debug: CFLAGS += -Ddebug -g
debug: todgred

objects = draw.o input.o menu.o todgred.o

todgred: $(objects)
		 $(CC) $(CFLAGS) $(objects) -o todgred

draw.o: draw.c
		$(CC) $(CFLAGS) -c -o draw.o draw.c
input.o: input.c
		$(CC) $(CFLAGS) -c -o input.o input.c
menu.o: menu.c
		$(CC) $(CFLAGS) -c -o menu.o menu.c
todgred.o: todgred.c
		$(CC) $(CFLAGS) -c -o todgred.o todgred.c

clean:
	rm $(objects) todgred
