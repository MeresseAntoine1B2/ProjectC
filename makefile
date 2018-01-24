#all : exec
#exec: main.o affichage.o mecaniques.o
#	gcc main.o affichage.o mecaniques.o
#main.o: main.c affichage.h mecaniques.h
#	gcc -std=c99 -c main.c
#affichage.o: affichage.c
#	gcc -std=c99 -c affichage.c
#mecaniques.o: mecaniques.c
#	gcc -std=c99 -c mecaniques.c
#CFLAGS = -g -O2 -Wall -Werror `pkg-config --cflags MLV`
#LDLIBS = `pkg-config --libs MLV`

CC = gcc

# Décommenter ces deux lignes pour l'interface texte
# CFLAGS = -Wall -g
# LDFLAGS = 
# Décommenter ces deux lignes pour l'interface graphique MLV
CFLAGS = -Wall -g -D GRAPHIQUE=1 `pkg-config --cflags MLV`
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

