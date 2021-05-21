
#include <iostream>
#include "Case.h"

#include "ZoneGeographique.h"
using namespace std;
#pragma once
class Robot
{
protected:
	
	ZoneGeographique zone;
	int  depi, depj, posi, posj, arrivi, arrivj;

public:
	
	//D�claration d'un constructeur avec param�tres:
	Robot(int, int);
	//D�claration d'un destructeur:
	~Robot();
	//D�claration de la m�thode parcours:permet d'afficher le plus court chemin:
	void parcours();
	//D�claration de la m�thode arriv:permet de donner la position de l'arriv�e :
	void arriv(int, int);
	//D�claration de la m�thode d'acc�s la ligne de la position du robot :
	int getposi() const;
	//D�claration de la m�thode d'acc�s la colonne de la position du robot :
	int getposj() const;
	//D�claration de la m�thode qui permet de modifier la ligne de la position du robot:
	void setposi(int);
	//D�claration de la m�thode qui permet de modifier la colonne de la position du robot:
	void setposj(int);
	//D�claration de la m�thode permet de modifier la valeur de la case:
	void setValeurs();
	//D�claration de la m�thode parcourt:
	bool testFinParcours();
	//D�claration de la m�thode choisir qui permet de choisir les positions de d�part , d'arriv�es et de les obstacles:
	void choisir();
	int get_arrivi();
	int get_arrivj();
	int get_depi();
	int get_depj();
	ZoneGeographique getZone();


	//changement choisir


};