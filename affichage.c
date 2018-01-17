#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"

#define LONG 12
#define LARG 18
#define ROUGE 'R'
#define BLEU 'B'
#define SERF 's'
#define GUERRIER 'g'

/* J'ai modifié la fonction printWorld pour la réadapter à ce qui est demandé au projet */

void printWorld(Unite *plateau[LONG][LARG])
{
	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (plateau[i][j] == NULL)
				printf("|   ");
			else
				printf("|%c %c|", plateau[i][j]->couleur, plateau[i][j]->type);
		}
		printf("|\n");
		printf("-------------------------------------------------------------------------\n");
	}
}

/* j'ai gcc affichage.c seulement afin de tester l'affichage du Plateau 

void initializerMonde(Monde *monde)
{
	for (int i = 0; i < LONG; i++)
		for (int j = 0; j < LARG; j++)
			monde->plateau[i][j] = NULL;
	monde->rouge = NULL;
	monde->bleu = NULL;
	monde->tour=0;
} 

int main ()
{
	printf("--------------\n");
	Monde monde;
	printf("test 1\n");
	initializerMonde(&monde);
	printf("test 2\n");
	printWorld(monde.plateau);
}*/