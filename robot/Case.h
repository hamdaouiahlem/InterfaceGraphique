#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Case
{
private:
	char natureCase;
	int abs;
	int ord;
	int valeur;




public:
	//D�claration du constructeur par d�faut:
	Case();
	//D�finition du constructeur avec param�tres:
	Case(char, int, int, int);
	//d�finition du destructeur:
	~Case();
	//D�claration de la m�thode d'acc�s � la nature de la case:
	char getNature();
	//D�claration de la m�thode qui permet de modifier la nature de la case:
	void setNature(char);
	//D�claration de la m�thode d'acc�s � la valeur de la case:
	int getValeur();
	//D�claration de la m�thode qui permet de modifier la valeur de la case:
	void setValeur(int);
	//D�claration de la m�thode qui permet de modifier les cordonn�es de la case:
	void setCord(int, int);


};
