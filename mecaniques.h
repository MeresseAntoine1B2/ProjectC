#ifndef H_MECA
#define H_MECA

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

// Mettre les prototypes des fonctions ci-dessous

void initializerMonde(Monde *monde);
int creerUnite(char type, LUnite *unite);

#endif
	