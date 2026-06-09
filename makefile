CC = cc
CFLAGS = -lm

all: todgred

debug: CFLAGS += -g -Wall -Wextra -pedantic -std=c11 -fsanitize=undefined -DDEBUG
debug: todgred

objects = draw.o menu.o todgred.o

todgred: $(objects)
		 $(CC) $(CFLAGS) $(objects) -o todgred

draw.o: draw.c
		$(CC) $(CFLAGS) -c -o draw.o draw.c
menu.o: menu.c
		$(CC) $(CFLAGS) -c -o menu.o menu.c
todgred.o: todgred.c
		$(CC) $(CFLAGS) -c -o todgred.o todgred.c

clean:
	rm $(objects) todgred
