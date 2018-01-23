#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include "affichage.h"

int main ()
{
	int x,y;
	Monde monde;

	//Initialisation du monde
	initializerMonde(&monde);
	monde.rouge = creerUnite(GUERRIER, ROUGE, monde.rouge);
	monde.rouge = creerUnite(SERF, ROUGE, monde.rouge);
	monde.bleu = creerUnite(GUERRIER, BLEU, monde.bleu);
	monde.bleu = creerUnite(SERF, BLEU, monde.bleu);
	AskPosition(&monde, monde.rouge);
	AskPosition(&monde, monde.bleu);
	printWorld(monde.plateau);

	//Debut du jeu
	LUnite tourJoueur;
	while(monde.rouge != NULL && monde.bleu!=NULL)
	{
		tourJoueur = monde.rouge;
		printf("C'est le tour des rouges !! \n");
		while (tourJoueur != NULL)
		{
			printf("On commence par ' %c ', [%d , %d]\n", tourJoueur->type, tourJoueur->posX, tourJoueur->posY);
			printf("Entrez la coordonnée X où vous voulez aller (Attention, on ne peut avancer que de 1 !)\n");
			scanf("%d", &x);
			printf("Entrez la coordonnée Y où vous voulez aller (Attention, on ne peut avancer que de 1 !)\n");
			scanf("%d", &y);
			deplacerUnite(tourJoueur, &monde, x, y);
			printWorld(monde.plateau);
			tourJoueur = tourJoueur->suiv;
		}
		if (monde.rouge == NULL)
		{
			monde.tour++;
			break;
		}


		tourJoueur = monde.bleu;
		printf("C'est le tour des bleus !! \n");
		while (tourJoueur != NULL)
		{
			printf("On commence par ' %c ', [%d , %d]\n", tourJoueur->type, tourJoueur->posX, tourJoueur->posY);
			printf("Entrez la coordonnée X où vous voulez aller (Attention, on ne peut avancer que de 1 !)\n");
			scanf("%d", &x);
			printf("Entrez la coordonnée Y où vous voulez aller (Attention, on ne peut avancer que de 1 !)\n");
			scanf("%d", &y);
			deplacerUnite(tourJoueur, &monde, x, y);
			printWorld(monde.plateau);
			tourJoueur = tourJoueur->suiv;
		}
		monde.tour++;
	}
	printf("GAME OVER !\n");
	if (monde.rouge == NULL)
		printf("Victoire des BLEUS en %d tours !\n", monde.tour);
	else
		printf("Victoire des ROUGES en %d tours !\n", monde.tour);
}
