#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include "string.h"
#include<MLV/MLV_all.h>

#define LONG 12
#define LARG 18
#define ROUGE 'R'
#define BLEU 'B'
#define SERF 's'
#define GUERRIER 'g'


void grille(int width, int height) 
{
	int i,j;
   	for (i=0;i<width;i=i+60)
    	{
    		for(j=0;j<height;j=j+60)
      		{
      			MLV_draw_rectangle(i,j,60,60,MLV_COLOR_RED1);
     		}
    	}
	MLV_actualise_window();
}

void coordonnee( int *x, int *y)
{
	int mouseX, mouseY;
	MLV_wait_mouse(&mouseX, &mouseY);
		*y=mouseX/60;
		*x=mouseY/60;
}

int f(int x)
{
	return (x/60)*60;
}

int fpix(int x)
{
	return (x*60);
}
void afficheIcone(Monde monde)
{
	int width = 1080;
	int height = 720;

	MLV_Image *image;
	MLV_Image *imageGB;
	MLV_Image *imageGR;
 	MLV_Image *imageSB;
  	MLV_Image *imageSR;

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

	for (int i = 0; i < LONG; i++)
	{
		for (int j = 0; j < LARG; j++)
		{
			if (monde.plateau[i][j] != NULL)
			{
				if (monde.plateau[i][j]->couleur == BLEU)
				{
					if (monde.plateau[i][j]->type == GUERRIER)
					{
						MLV_draw_image(imageGB,fpix(j),fpix(i));
						MLV_actualise_window();
					}
					else if (monde.plateau[i][j]->type == SERF)
					{
						MLV_draw_image(imageSB,fpix(j),fpix(i));
						MLV_actualise_window();
					}
				}
				else if (monde.plateau[i][j]->couleur == ROUGE)
				{
					if (monde.plateau[i][j]->type == GUERRIER)
					{
						MLV_draw_image(imageGR,fpix(j),fpix(i));
						MLV_actualise_window();
					}
					else if (monde.plateau[i][j]->type == SERF)
					{
						MLV_draw_image(imageSR,fpix(j),fpix(i));
						MLV_actualise_window();
					}
				}
			}
		}
	}
}
