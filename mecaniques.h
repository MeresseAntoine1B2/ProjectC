#ifndef H_MECA
#define H_MECA

typedef struct unite
{
  int posX, posY;
  char couleur;
  char genre;
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
int creerUnite(char type, char couleur, LUnite *unite);

#endif
	