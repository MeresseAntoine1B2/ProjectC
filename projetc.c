#include<stdio.h>
#include<stdlib.h>
#define LONG 12
#define LARG 18
#define ROUGE 'R'
#define BLEU 'B'
#define SERF 's'
#define GUERRIER 'g'

typedef struct unite
{
  int posX, posY;
  char couleur;
  char genre;
  struct unite *suiv;
}Unite;

typedef Unite *Uliste;

typedef struct monde
{
  Unite *plateau[LONG][LARG];
  int tour;
  Uliste rouge, bleu;
}Monde;

int main ()
{
  Monde jeu1;
  initializerMonde(jeu1);




}

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
