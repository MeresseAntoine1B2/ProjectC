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
	printf("------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (plateau[i][j] == NULL)
				printf("|   |");
			else
				printf("|%c %c|", plateau[i][j]->couleur, plateau[i][j]->type);
		}
		printf("\n");
		printf("------------------------------------------------------------------------------------------\n");
	}
}

void AskPosition(Monde *monde, LUnite liste)
{
	int x, y;
	Unite *tmp = liste;
	while (tmp != NULL)
	{
		do
		{
			printf("Où souhaitez vous placer le %c %c ?\n", tmp->type, tmp->couleur);
			printf("Entrez la coordonnée X (entre 0 et %d)\n", LONG);
			scanf("%d", &x);
			printf("Entrez la coordonnée Y (entre 0 et %d)\n", LARG);
			scanf("%d", &y);
		} while ((x > LONG || x < 0) && (y > LARG || y < 0) && (monde->plateau[x][y] != NULL));
		placerAuMonde(tmp, monde, x, y);
		tmp = tmp->suiv;
	}
}
