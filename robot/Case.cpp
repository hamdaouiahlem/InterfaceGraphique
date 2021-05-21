#include "Case.h"


//Définition du constructeur par défaut :
Case::Case() {}
//Définition du constructeur avec paramètres:
Case::Case(char nature = 'v', int abs = 0, int ord = 0, int val = 1000) : natureCase(nature), abs(abs), ord(ord), valeur(val)
{
}
//Définition du destructeur:
Case::~Case() {}
//Définition de la méthode getNature:
char Case::getNature()
{
	return natureCase;
}
//Définition de la méthode setNature:
void Case::setNature(char nature)
{
	natureCase = nature;
}
//Définition de la méthode getValeur:
int Case::getValeur()
{
	return valeur;
}
//Définition de la méthode setValeur:
void Case::setValeur(int val)
{
	valeur = val;
}
//Définition de la méthode setCord:
void Case::setCord(int i, int j)
{
	ord = i;
	abs = j;
}
