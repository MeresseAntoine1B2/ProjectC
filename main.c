#include <stdio.h>
#include <stdlib.h>
#include "mecaniques.h"
#include "affichage.h"

int main ()
{
	printf("test 0");
	Monde monde;
	printf("test 1");
	initializerMonde(&monde);
	printf("test 2");
	printWorld(monde.plateau);
}