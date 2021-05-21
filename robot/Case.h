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
	//Déclaration du constructeur par défaut:
	Case();
	//Définition du constructeur avec paramètres:
	Case(char, int, int, int);
	//définition du destructeur:
	~Case();
	//Déclaration de la méthode d'accés à la nature de la case:
	char getNature();
	//Déclaration de la méthode qui permet de modifier la nature de la case:
	void setNature(char);
	//Déclaration de la méthode d'accés à la valeur de la case:
	int getValeur();
	//Déclaration de la méthode qui permet de modifier la valeur de la case:
	void setValeur(int);
	//Déclaration de la méthode qui permet de modifier les cordonnées de la case:
	void setCord(int, int);


};
