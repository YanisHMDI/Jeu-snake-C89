CC = gcc
CFLAGS = -ansi -pedantic
LIBS = -lgraph

TARGET = serpent
SRCS = main.c serpent.c timer.c terrain.c pastilles.c jeu.c menu.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJS) $(TARGET)
