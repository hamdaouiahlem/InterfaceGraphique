#include "ZoneGeographique.h"
#include "Case.h"
#include<windows.h>


//Définition du constructeur par défaut:
ZoneGeographique::ZoneGeographique() {}
//Définition du constructeur: 
ZoneGeographique::ZoneGeographique(int N = 0, int M = 0) : c(N), l(M)
{
    for (int i = 0; i < l; i++)
    {
        zone.push_back(vector<Case>(c));
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            zone[i][j].setCord(i, j);
            zone[i][j].setValeur(1000);
            zone[i][j].setNature('v');

        }
    }
}

//Définition du destructeur :
ZoneGeographique :: ~ZoneGeographique()
{
    for (int i = 0; i < l; i++)
    {
        zone.pop_back();
    }
}


//Définition de getVal:
int ZoneGeographique::getVal(int i, int j)
{
    return zone[i - 1][j - 1].getValeur();
}
//Définition de setVal:
void ZoneGeographique::setVal(int i, int j, int v)
{
    zone[i - 1][j - 1].setValeur(v);
}
//recherche du plus court chemin: 

void recherche(int depi, int depj, int arri, int arrj, int obs)
{

}
//Définition de la méthode afficherValZoneGeographique:
void ZoneGeographique::afficherValZoneGeographique()
{
    system("cls");
    cout << " ";
    cout << endl;
    cout << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "\t" << zone[i][j].getValeur() << "\t";
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

    }
}
//Définition de la méthode afficherNatZoneGeographique:
void ZoneGeographique::afficherNatZoneGeographique()
{
    system("cls");
    cout << " ";
    cout << endl;
    cout << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "\t" << zone[i][j].getNature() << "\t";
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

    }
}
//Définition de la méthode setlc:
void ZoneGeographique::setlc(int i, int j)
{
    l = i;
    c = j;
    for (int i = 0; i < l; i++)
    {
        zone.push_back(vector<Case>(c));
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            zone[i][j].setCord(i, j);
            zone[i][j].setValeur(1000);
        }
    }
}
//Définition de la méthode getNat:
char ZoneGeographique::getNat(int i, int j) {
    return zone[i - 1][j - 1].getNature();
}
//Définition de la méthode setNat:
void ZoneGeographique::setNat(int i, int j, char c) {
    zone[i - 1][j - 1].setNature(c);
}
//Définition de la méthode getl:
int ZoneGeographique::getl()
{
    return l;
}
//Définition de la méthode getc:
int ZoneGeographique::getc()
{
    return c;
}

vector<vector<Case> > ZoneGeographique::get_zone() {
    return zone;
}

int ZoneGeographique::get_nbo() {
    int nb = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char nat = zone[i][j].getNature();
            if (nat == 'o') {
                nb++;
            }
        }
    }
    return nb;
}