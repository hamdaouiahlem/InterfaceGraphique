#pragma once

#include <iostream>
#include "Case.h"
#include<vector>



class ZoneGeographique
{
private:
    int l;
    int c;
    vector<vector<Case> > zone;
public:

    //Déclaration d'un constructeur par défaut:
    ZoneGeographique();
    //Déclaration d'un constructeur avec paramètres:
    ZoneGeographique(int, int);
    //Déclaration d'un déstructeur:
    ~ZoneGeographique();
    // Méthode d'accès à une valeur de la matrice:
    int getVal(int i, int j);
    // Méthode pour modifier une valeur de la matrice :
    void setVal(int, int, int);
    //Méthode pour afficher les valeurs de la zone:
    void afficherValZoneGeographique();
    //Méthode pour afficher les natures de la zone:
    void afficherNatZoneGeographique();

    //Méthode pour rechercher le  plus court  chemin: 
    void recherche(int, int, int, int, int);
    //Méthode pour modifier le nombre de lignes ou de colonnes:
    void setlc(int, int);
    //Méthode d'accés à la nature des cases:
    char getNat(int, int);
    //Méthode pour modifier la nature des cases:
    void setNat(int, int, char);
    //Méthode d'accés à le nombre des lignes :
    int getl();
    //Méthode d'accés à le nombre des colonnes:
    int getc();
    vector<vector<Case> > get_zone();
    int get_nbo();
};