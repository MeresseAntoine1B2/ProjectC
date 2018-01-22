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

/* Fonctions de gestion des listes chainées */

/* fonction creerUnite 

int creerUnite(char type, char couleur, LUnite *unite)
{
	// Création d'une unité
	Unite *nouvelle = malloc(sizeof(Unite));
	if (nouvelle == NULL)
		return 1; //Erreur de l'allocation
	
	// On assigne les valeurs
	nouvelle->couleur = couleur;
	nouvelle->type = type;
	nouvelle->suiv = NULL;

	if(unite == NULL)
		unite = &nouvelle;
	else
	{
		LUnite tmp = unite;
		while(tmp->suiv != NULL)
			tmp = tmp->suiv;
		tmp->suiv = &nouvelle;
	}
	return 0;
}*/

LUnite creerUnite(char type, char couleur, LUnite liste)
{
	// Création d'une unité
	Unite *nouvelle = malloc(sizeof(Unite));
	if (nouvelle == NULL)
		exit(EXIT_FAILURE); //Erreur de l'allocation
	
	// On assigne les valeurs
	nouvelle->couleur = couleur;
	nouvelle->type = type;
	nouvelle->suiv = NULL;

	if (liste == NULL)
		return nouvelle;
	else
	{
		Unite *tmp = liste;
		while (tmp->suiv != NULL)
			tmp = tmp->suiv;
		tmp->suiv=nouvelle;
		return liste;
	}
}


int placerAuMonde(Unite *unite, Monde *monde, int posX, int posY)
{
	if (monde->plateau[posX][posY] != NULL)
	{
		return 1; /* case non vide on ne peut pas placer l'unité ici */
	}
	unite->posX = posX;
	unite->posY = posY;
	monde->plateau[posX][posY]=unite;
	return 0;
}

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
