CC = gcc
CFLAGS = -ansi -pedantic
LIBS = -lgraph

TARGET = serpent
SRCS = src/main.c src/serpent.c src/timer.c src/terrain.c src/pastilles.c src/jeu.c src/menu.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJS) $(TARGET) 