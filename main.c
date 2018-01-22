#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include "affichage.h"

int main ()
{
	int x,y;
	Monde monde;
	initializerMonde(&monde);
	monde.rouge = creerUnite(GUERRIER, ROUGE, monde.rouge);
	monde.rouge = creerUnite(SERF, ROUGE, monde.rouge);
	monde.bleu = creerUnite(GUERRIER, BLEU, monde.bleu);
	monde.bleu = creerUnite(SERF, BLEU, monde.bleu);
	AskPosition(&monde, monde.rouge);
	AskPosition(&monde, monde.bleu);
	printWorld(monde.plateau);
}
