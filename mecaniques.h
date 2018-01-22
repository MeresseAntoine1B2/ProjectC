#ifndef H_MECA
#define H_MECA

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
  char type;
  struct unite *suiv;
}Unite;

typedef Unite *LUnite;

typedef struct monde
{
  Unite *plateau[LONG][LARG];
  int tour;
  LUnite rouge, bleu;
}Monde;

// Mettre les prototypes des fonctions ci-dessous

void initializerMonde(Monde *monde);
LUnite creerUnite(char type, char couleur, LUnite liste);
int placerAuMonde(Unite *unite, Monde *monde, int posX, int posY);
void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY);

#endif
	
