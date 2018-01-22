all : exec
exec: main.o affichage.o mecaniques.o
	gcc main.o affichage.o mecaniques.o
main.o: main.c affichage.h mecaniques.h
	gcc -std=c99 -c main.c
affichage.o: affichage.c
	gcc -std=c99 -c affichage.c
mecaniques.o: mecaniques.c
	gcc -std=c99 -c mecaniques.c
