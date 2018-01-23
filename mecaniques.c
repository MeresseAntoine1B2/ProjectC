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

void attaquer(Monde *monde, char c, int destX, int destY)
{
	if (c == 'R')
	{
		if(monde->rouge->posX == destX && monde->rouge->posY == destY)
			monde->rouge = supprDebutChaine(monde->rouge);
		else
			monde->rouge = supprDansChaine(monde->rouge, destX, destY);
	}
	else if (c == 'B')
	{
		if(monde->bleu->posX == destX && monde->bleu->posY == destY)
			monde->bleu = supprDebutChaine(monde->bleu);
		else
			monde->bleu = supprDansChaine(monde->bleu, destX, destY);
	}
}

LUnite supprDebutChaine(LUnite liste)
{
	if (liste != NULL)
	{
		Unite *suivante = liste->suiv;
		free(liste);
		return suivante;
	}
	else
		return NULL;
}

LUnite supprDansChaine(LUnite liste, int x, int y)
{
	if(liste == NULL)
        	return NULL;
    	if(liste->suiv == NULL)
	{
        	free(liste);
		return NULL;
	}

	Unite *tmp = liste;
	Unite *precedTmp = liste;

	while(tmp->suiv->posX != x && tmp->suiv->posY != y && tmp->suiv != NULL)
	{
		precedTmp = tmp;
		tmp = tmp->suiv;
	}
	precedTmp->suiv = tmp->suiv;
	free(tmp);
	return liste;
}

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY)
{
	if (unite->posX != destX || unite->posY != destY)
	{
		if ((unite->posX - destX) <= 1 && (unite->posX - destX) >= -1 && (unite->posY - destY) <= 1 && (unite->posY - destY) >= -1 )
		{
			if(monde->plateau[destX][destY] != NULL)
			{
				if (monde->plateau[destX][destY]->couleur != unite->couleur)
				{					
					attaquer(monde, monde->plateau[destX][destY]->couleur, destX, destY);
					monde->plateau[destX][destY] = monde->plateau[unite->posX][unite->posY];
					monde->plateau[unite->posX][unite->posY] = NULL;
					unite->posX = destX;
					unite->posY = destY;
					printf("Unité déplacée!\n");
				}
				else
					printf("le tir ami n'est pas toléré camarade, tu perds ton tour !\n");
			}
			else
			{
				monde->plateau[destX][destY] = monde->plateau[unite->posX][unite->posY];
				monde->plateau[unite->posX][unite->posY] = NULL;
				unite->posX = destX;
				unite->posY = destY;
				printf("Unité déplacée!\n");
			}
		}
		else
			printf("Si les devs étaient gentils, ils te laisseraient retenter car ton placement est invalide a l'aide d'une petite boucle. Mais les devs sont méchants. \n");
	}
	else
		printf("Tu ne veux pas bouger ? Tant pis pour toi !\n");
}

