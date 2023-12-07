

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c89
LDFLAGS = -lgraph

all: jeu.out

jeu.out: main.o jeu.o
    $(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

main.o: main.c jeu.h
    $(CC) $(CFLAGS) -c main.c

jeu.o: jeu.c jeu.h
    $(CC) $(CFLAGS) -c jeu.c

clean:
    rm -f jeu.out *.o
