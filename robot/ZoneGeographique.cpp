#include "ZoneGeographique.h"
#include "Case.h"
#include<windows.h>


//D�finition du constructeur par d�faut:
ZoneGeographique::ZoneGeographique() {}
//D�finition du constructeur: 
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

//D�finition du destructeur :
ZoneGeographique :: ~ZoneGeographique()
{
    for (int i = 0; i < l; i++)
    {
        zone.pop_back();
    }
}


//D�finition de getVal:
int ZoneGeographique::getVal(int i, int j)
{
    return zone[i - 1][j - 1].getValeur();
}
//D�finition de setVal:
void ZoneGeographique::setVal(int i, int j, int v)
{
    zone[i - 1][j - 1].setValeur(v);
}
//recherche du plus court chemin: 

void recherche(int depi, int depj, int arri, int arrj, int obs)
{

}
//D�finition de la m�thode afficherValZoneGeographique:
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
//D�finition de la m�thode afficherNatZoneGeographique:
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
//D�finition de la m�thode setlc:
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
//D�finition de la m�thode getNat:
char ZoneGeographique::getNat(int i, int j) {
    return zone[i - 1][j - 1].getNature();
}
//D�finition de la m�thode setNat:
void ZoneGeographique::setNat(int i, int j, char c) {
    zone[i - 1][j - 1].setNature(c);
}
//D�finition de la m�thode getl:
int ZoneGeographique::getl()
{
    return l;
}
//D�finition de la m�thode getc:
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