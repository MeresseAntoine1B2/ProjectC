CC = gcc
CFLAGS = -std=c99 -Wall -g -D GRAPHIQUE=1 `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-l MLV`
 
SRC = $(wildcard */*.c) $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = main

all : $(AOUT)

main : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean :
	@rm *.o */*.o
cleaner : clean
	@rm $(AOUT)

