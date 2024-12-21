#ifndef PARTIE_H
#define PARTIE_H
#include "plateau.h"
#include <iostream>
class partie
{
	public:
		partie();
		~partie();
		jouer(int);
		menu();
	private:
		plateau p;
		int tour;
};

#endif


