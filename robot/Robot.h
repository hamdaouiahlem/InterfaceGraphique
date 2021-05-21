
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
	
	//Déclaration d'un constructeur avec paramètres:
	Robot(int, int);
	//Déclaration d'un destructeur:
	~Robot();
	//Déclaration de la méthode parcours:permet d'afficher le plus court chemin:
	void parcours();
	//Déclaration de la méthode arriv:permet de donner la position de l'arrivée :
	void arriv(int, int);
	//Déclaration de la méthode d'accés la ligne de la position du robot :
	int getposi() const;
	//Déclaration de la méthode d'accés la colonne de la position du robot :
	int getposj() const;
	//Déclaration de la méthode qui permet de modifier la ligne de la position du robot:
	void setposi(int);
	//Déclaration de la méthode qui permet de modifier la colonne de la position du robot:
	void setposj(int);
	//Déclaration de la méthode permet de modifier la valeur de la case:
	void setValeurs();
	//Déclaration de la méthode parcourt:
	bool testFinParcours();
	//Déclaration de la méthode choisir qui permet de choisir les positions de départ , d'arrivées et de les obstacles:
	void choisir();
	int get_arrivi();
	int get_arrivj();
	int get_depi();
	int get_depj();
	ZoneGeographique getZone();


	//changement choisir


};