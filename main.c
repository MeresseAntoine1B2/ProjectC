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
	monde.rouge = creerUnite(SERF, ROUGE, monde.rouge);
	monde.bleu = creerUnite(GUERRIER, BLEU, monde.bleu);
	monde.bleu = creerUnite(SERF, BLEU, monde.bleu);
	monde.bleu = creerUnite(SERF, BLEU, monde.bleu);
	

	//Debut du jeu
	MLV_Image *image;
	MLV_Image *imageGB;
	MLV_Image *imageGR;
 	MLV_Image *imageSB;
  	MLV_Image *imageSR;
	int width = 1080;
	int height = 720;
	MLV_create_window("fenetre","icone fenetre",width,height+200);
	image = MLV_load_image("pirate.jpg");
	imageGB = MLV_load_image("guerrierBleu.png");
	imageGR = MLV_load_image("guerrierRouge.png");
 	imageSB = MLV_load_image("serfBleu.png");
  	imageSR = MLV_load_image("serfRouge.png");
	MLV_resize_image_with_proportions(image,width,height);
	MLV_resize_image_with_proportions(imageGB,60,60);
	MLV_resize_image_with_proportions(imageGR,60,60);
  	MLV_resize_image_with_proportions(imageSB,60,60);
  	MLV_resize_image_with_proportions(imageSR,60,60);
	MLV_draw_image(image,0,0);
	MLV_actualise_window();
 	grille(width, height);
	
	//phase de placement
	LUnite chaine = monde.rouge; 
	while(chaine != NULL)
	{
		if (chaine->type == GUERRIER)
			MLV_draw_adapted_text_box(400,760,"Placez le guerrier rouge !" ,taille_interlinge,MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
		else
			MLV_draw_adapted_text_box(400,760,"Placez le serf rouge !" ,taille_interlinge,MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
		MLV_actualise_window();
		do
		{
			coordonnee(&x, &y);
		} while (monde.plateau[x][y] != NULL);
		placerAuMonde(chaine, &monde, x, y);
		chaine = chaine->suiv;
		afficheIcone(monde);
		MLV_draw_filled_rectangle(400,760,230,70,MLV_COLOR_BLACK);
		MLV_actualise_window();
	}
	chaine = monde.bleu;
	while(chaine != NULL)
	{
		if (chaine->type == GUERRIER)
			MLV_draw_adapted_text_box(400,760,"Placez le guerrier bleu !" ,taille_interlinge,MLV_COLOR_BLUE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
		else
			MLV_draw_adapted_text_box(400,760,"Placez le serf bleu !" ,taille_interlinge,MLV_COLOR_BLUE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
		MLV_actualise_window();
		do
		{
			coordonnee(&x, &y);
		} while (monde.plateau[x][y] != NULL);
		placerAuMonde(chaine, &monde, x, y);
		chaine = chaine->suiv;
		afficheIcone(monde);
		MLV_draw_filled_rectangle(400,760,230,70,MLV_COLOR_BLACK);
		MLV_actualise_window();
	}
	//Debut du jeu
	while(monde.rouge != NULL && monde.bleu!=NULL)
	{
		chaine=monde.rouge;
		while (chaine != NULL)
		{
			MLV_draw_adapted_text_box(400,760,"cliquez sur une case ADJACENTE pour déplacer le pion selectionné (Tir AMI non toléré)" ,taille_interlinge,MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
			MLV_draw_rectangle(fpix(chaine->posY), fpix(chaine->posX), 60, 60, MLV_COLOR_GREEN);
			MLV_actualise_window();
			do
			{
				coordonnee(&x, &y);
			} while (deplacerUnite(chaine, &monde, x, y) != 0);
			afficheIcone(monde);
			chaine=chaine->suiv;
			if (monde.rouge == NULL || monde.bleu == NULL)
			{
				monde.tour++;
				break;
			}
		}
		if (monde.rouge == NULL || monde.bleu == NULL)
		{
			monde.tour++;
			break;
		}
		
		chaine=monde.bleu;
		while (chaine != NULL)
		{
			MLV_draw_adapted_text_box(400,760,"cliquez sur une case ADJACENTE pour déplacer le pion selectionné (Tir AMI non toléré)" ,taille_interlinge,MLV_COLOR_BLUE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
			MLV_draw_rectangle(fpix(chaine->posY), fpix(chaine->posX), 60, 60, MLV_COLOR_GREEN);
			MLV_actualise_window();
			do
			{
				coordonnee(&x, &y);
			} while (deplacerUnite(chaine, &monde, x, y) != 0);
			afficheIcone(monde);
			chaine=chaine->suiv;
			if (monde.rouge == NULL || monde.bleu == NULL)
			{
				monde.tour++;
				break;
			}
		}
	monde.tour++;
	}
	//fin jeu
	if (monde.rouge == NULL)
	{
		MLV_draw_filled_rectangle(0,0,width,(height+200),MLV_COLOR_BLACK);
		MLV_draw_adapted_text_box(width/2,(height+200)/2,"VICTOIRE BLEUE" ,taille_interlinge,MLV_COLOR_BLUE, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
	}
	else
	{
		MLV_draw_filled_rectangle(0,0,width,(height+200),MLV_COLOR_BLACK);
		MLV_draw_adapted_text_box(width/2,(height+200)/2,"VICTOIRE ROUGE" ,taille_interlinge,MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
	}
	MLV_actualise_window();

	MLV_wait_seconds(10);

}
