#include "Case.h"


//D�finition du constructeur par d�faut :
Case::Case() {}
//D�finition du constructeur avec param�tres:
Case::Case(char nature = 'v', int abs = 0, int ord = 0, int val = 1000) : natureCase(nature), abs(abs), ord(ord), valeur(val)
{
}
//D�finition du destructeur:
Case::~Case() {}
//D�finition de la m�thode getNature:
char Case::getNature()
{
	return natureCase;
}
//D�finition de la m�thode setNature:
void Case::setNature(char nature)
{
	natureCase = nature;
}
//D�finition de la m�thode getValeur:
int Case::getValeur()
{
	return valeur;
}
//D�finition de la m�thode setValeur:
void Case::setValeur(int val)
{
	valeur = val;
}
//D�finition de la m�thode setCord:
void Case::setCord(int i, int j)
{
	ord = i;
	abs = j;
}
