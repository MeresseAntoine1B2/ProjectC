all : exec
exec: main.o affichage.o mecaniques.o
	gcc main.o affichage.o mecaniques.o
main.o: main.c affichage.h mecaniques.h
	gcc -c main.c
affichage.o: affichage.c
	gcc -c affichage.c
mecaniques.o: mecaniques.c
	gcc -c mecaniques.c