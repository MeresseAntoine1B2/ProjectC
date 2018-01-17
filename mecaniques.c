#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include "affichage.h"

#define LONG 12
#define LARG 18
#define ROUGE 'R'
#define BLEU 'B'
#define SERF 's'
#define GUERRIER 'g'

/* fonction initializerMonde */
void initializerMonde(Monde *monde)
{
	for (int i = 0; i < LONG; i++)
		for (int j = 0; j < LARG; j++)
			monde->plateau[i][j] = NULL;
	monde->rouge = NULL;
	monde->bleu = NULL;
	monde->tour=0;
}

/* fonction creerUnite */

int creerUnite(char type, char couleur, LUnite *unite)
{
	Unite *nouvelle = malloc(sizeof(Unite));
	if (nouvelle == NULL)
		return 1; //Erreur de l'allocation
	nouvelle->couleur = couleur;
	nouvelle->type = type;
	unite->nouvelle; /*** je crois que ça devrais être unite = nouvelle ***/
	return 0;
}

/*
int placerAuMonde(Unite *unite, Monde *monde, int posX, int posY, char couleur)
{
	if (monde->plateau[posX][posY] != NULL)
	{
		return 1; /* case non vide on ne peut pas placer l'unité ici */
	}
	unite->posX = posX;
	unite->posY = posY;
	unite->couleur = couleur;

}*/

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY)
{
	if (unite->posX != destX || unite->posY != destY)
	{
		if ((unite->posX - destX) <= -1 && (unite->posX - destX) >= 1 && (unite->posY - destY) <= -1 && (unite->posY - destY) >= 1 )
		{
			unite->posX = destX;
			unite->posY = destY;
		}
	}
}