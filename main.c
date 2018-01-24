#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include "affichage.h"
#include<MLV/MLV_all.h>

int main ()
{
	int x,y;
	Monde monde;
	int taille_interlinge = 9;

	//Initialisation du monde
	initializerMonde(&monde);
	monde.rouge = creerUnite(GUERRIER, ROUGE, monde.rouge);
	monde.rouge = creerUnite(SERF, ROUGE, monde.rouge);
	monde.bleu = creerUnite(GUERRIER, BLEU, monde.bleu);
	monde.bleu = creerUnite(SERF, BLEU, monde.bleu);
	

	//Debut du jeu
	MLV_Image *image;
	int width = 1080;
	int height = 720;
	MLV_create_window("fenetre","icone fenetre",width,height+200);
	image = MLV_load_image("pirate.jpg");
	MLV_resize_image_with_proportions(image,width,height);
	MLV_draw_image(image,0,0);
	MLV_actualise_window();
 	grille(width, height);
	
	LUnite chaine = monde.rouge;
	while(chaine != NULL)
	{
		MLV_draw_adapted_text_box(400,760,"Placez le bonhomme rouge !",taille_interlinge,MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
		MLV_actualise_window();
		do
		{
			coordonnee(&x, &y);
		} while (monde.plateau[x][y] != NULL);
		placerAuMonde(chaine, &monde, x, y);
		chaine = chaine->suiv;
	}
	chaine = monde.bleu;
	while(chaine != NULL)
	{
		MLV_draw_adapted_text_box(400,760,"Placez le bonhomme bleu !",taille_interlinge,MLV_COLOR_BLUE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
		MLV_actualise_window();
		do
		{
			coordonnee(&x, &y);
		} while (monde.plateau[x][y] != NULL);
		placerAuMonde(chaine, &monde, x, y);
		chaine = chaine->suiv;
	}
	MLV_wait_seconds(10);

}
