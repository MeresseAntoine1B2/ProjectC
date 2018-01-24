all : exec
exec: main.o affichage.o mecaniques.o
	gcc main.o affichage.o mecaniques.o
main.o: main.c affichage.h mecaniques.h
	gcc -std=c99 -c main.c
affichage.o: affichage.c
	gcc -std=c99 -c affichage.c
mecaniques.o: mecaniques.c
	gcc -std=c99 -c mecaniques.c
CFLAGS = -g -O2 -Wall -Werror `pkg-config --cflags MLV`
LDLIBS = `pkg-config --libs MLV`
gcc -Wall pkg-config --cflags MLV pkg-config --libs-only-other --libs-only-L MLV main.c pkg-config --libs-only-l MLV -o main