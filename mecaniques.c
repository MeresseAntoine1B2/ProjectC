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
  monde->Unite==NULL;
  monde->tour=0;
}

/* fonction creerUnite */
int creerUnite(char type, LUnite *unite)
{
  /* j'ai pas encore compris faut relire un million de fois */
}