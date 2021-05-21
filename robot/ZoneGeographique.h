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

    //D�claration d'un constructeur par d�faut:
    ZoneGeographique();
    //D�claration d'un constructeur avec param�tres:
    ZoneGeographique(int, int);
    //D�claration d'un d�structeur:
    ~ZoneGeographique();
    // M�thode d'acc�s � une valeur de la matrice:
    int getVal(int i, int j);
    // M�thode pour modifier une valeur de la matrice :
    void setVal(int, int, int);
    //M�thode pour afficher les valeurs de la zone:
    void afficherValZoneGeographique();
    //M�thode pour afficher les natures de la zone:
    void afficherNatZoneGeographique();

    //M�thode pour rechercher le  plus court  chemin: 
    void recherche(int, int, int, int, int);
    //M�thode pour modifier le nombre de lignes ou de colonnes:
    void setlc(int, int);
    //M�thode d'acc�s � la nature des cases:
    char getNat(int, int);
    //M�thode pour modifier la nature des cases:
    void setNat(int, int, char);
    //M�thode d'acc�s � le nombre des lignes :
    int getl();
    //M�thode d'acc�s � le nombre des colonnes:
    int getc();
    vector<vector<Case> > get_zone();
    int get_nbo();
};