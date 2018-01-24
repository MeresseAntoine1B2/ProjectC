#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include<MLV/MLV_all.h>

#define LONG 12
#define LARG 18
#define ROUGE 'R'
#define BLEU 'B'
#define SERF 's'
#define GUERRIER 'g'


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

void grille(int width, int height) 
{
	int i,j;
   	for (i=0;i<width;i=i+60)
    	{
    		for(j=0;j<height;j=j+60)
      		{
      			MLV_draw_rectangle(i,j,60,60,MLV_COLOR_YELLOW1);
     		}
    }
}

