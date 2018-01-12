#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"

#define LONG 12
#define LARG 18
#define ROUGE 'R'
#define BLEU 'B'
#define SERF 's'
#define GUERRIER 'g'

void printWorld(Unite *plateau[][])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (plateau[i][j] == null)
				printf("|---|");
			else
				printf("|%c %c|", plateau[i][j]->couleur, plateau[i][j]->genre);
		}
	}
}