#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include "affichage.h"
#include<MLV/MLV_all.h>

int main ()
{
	/*int x,y;*/
	Monde monde;

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
	  MLV_create_window("fenetre","icone fenetre",width,height);
	  image = MLV_load_image("pirate.jpg");
	  MLV_resize_image_with_proportions(image,width,height);
	  MLV_draw_image(image,0,0);
	  MLV_actualise_window();
	   MLV_wait_seconds(10);
 
}
