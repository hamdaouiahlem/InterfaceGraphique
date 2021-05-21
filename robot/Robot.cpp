#include <iostream>
#include "Robot.h"
#include <string.h>
#include <algorithm>

using namespace std;
//Définition du constructeur avec paramètres:
Robot::Robot(int i, int j)
{

    arrivi = arrivj = 0;
    depi = i;
    depj = j;
    posi = i;
    posj = j;
}
//Définition du destructeur:
Robot::~Robot() {}
//Définition de la méthode setValeurs:
void Robot::setValeurs()
{
    int l, c, v, d, o, n;
    int a(1000), b(1000), e(1000), f(1000), min1, min2, min;
    c = zone.getc();
    l = zone.getl();
    o = l * c * 3;
    d = l * c * 2;
    /*cout << depi << endl;
    cout << arrivi << endl;*/

    {
        for (int i = arrivi; i >= 2; i--)
        {
            if (((zone.getVal(i - 1, arrivj)) != o) && ((zone.getVal(i - 1, arrivj)) != d) && ((zone.getVal(i - 1, arrivj)) != 0))

            {
                v = zone.getVal(i, arrivj);
                zone.setVal(i - 1, arrivj, v + 1);
            }

            // i:ligne d'arrive - 1
            for (int j = arrivj; j > 1; j--)
            {
                if (((zone.getVal(i - 1, j - 1)) != o) && ((zone.getVal(i - 1, j - 1)) != d) && ((zone.getVal(i - 1, j - 1)) != 0))

                {
                    v = zone.getVal(i - 1, j);
                    zone.setVal(i - 1, j - 1, v + 1);
                }



            }
        }
        //pour la ligne d'arriver
        for (int j = arrivj - 1; j > 0; j--)
        {
            if (((zone.getVal(arrivi, j)) != o) && ((zone.getVal(arrivi, j)) != d) && ((zone.getVal(arrivi, j)) != 0))

            {
                v = zone.getVal(arrivi, j + 1);
                zone.setVal(arrivi, j, v + 1);
            }



        }
        for (int i = arrivi + 1; i <= l; i++)
        {
            if (((zone.getVal(i, arrivj)) != o) && ((zone.getVal(i, arrivj)) != d) && ((zone.getVal(i, arrivj)) != 0))

            {
                v = zone.getVal(i - 1, arrivj);
                zone.setVal(i, arrivj, v + 1);
            }

            //i:arriv i +1
            for (int j = arrivj - 1; j > 0; j--)
            {
                if (((zone.getVal(i - 1, j)) != o) && ((zone.getVal(i - 1, j)) != d) && ((zone.getVal(i - 1, j)) != 0))


                {
                    v = zone.getVal(i - 1, j + 1);
                    zone.setVal(i - 1, j, v + 1);
                }



            }

        }
        //pour la derniere ligne
        for (int j = arrivj - 1; j > 0; j--)
        {
            if (((zone.getVal(l, j)) != o) && ((zone.getVal(l, j)) != d) && ((zone.getVal(l, j)) != 0))

            {
                v = zone.getVal(l, j + 1);
                zone.setVal(l, j, v + 1);
            }



        }
        for (int i = 1; i <= l; i++)
        {
            for (int j = arrivj + 1; j <= c; j++)
            {
                if (((zone.getVal(i, j)) != o) && ((zone.getVal(i, j)) != d) && ((zone.getVal(i, j)) != 0))

                {
                    v = zone.getVal(i, j - 1);
                    zone.setVal(i, j, v + 1);
                }



            }


        }
        //zone.afficherValZoneGeographique();
        //cout << "ecrire un chiffre pour continuer" << endl;
        //cin >> n;
        //********************************************************************************************
        //********************************************************************************************
        for (int k = 0; k < l; k++)
        {
            for (int i = arrivi; i >= 2; i--)
            {

                if (i - 2 > 0)
                {
                    a = zone.getVal(i - 2, arrivj);
                }

                if (arrivj - 1 > 0)
                {
                    b = zone.getVal(i - 1, arrivj - 1);
                }
                if (arrivj + 1 <= c)
                {
                    e = zone.getVal(i - 1, arrivj + 1);
                }
                if (i <= l)
                    f = zone.getVal(i, arrivj);
                min1 = std::min(a, b);
                min2 = std::min(e, f);
                min = std::min(min1, min2);

                if (((zone.getVal(i - 1, arrivj)) != o) && ((zone.getVal(i - 1, arrivj)) != d) && ((zone.getVal(i - 1, arrivj)) != 0))

                {
                    zone.setVal(i - 1, arrivj, min + 1);
                }

                // i:ligne d'arrive - 1
                for (int j = arrivj - 1; j >= 1; j--)
                {
                    if (i - 2 > 0)
                        a = zone.getVal(i - 2, j);
                    if (j - 1 > 0)
                        b = zone.getVal(i - 1, j - 1);


                    e = zone.getVal(i - 1, j + 1);
                    f = zone.getVal(i, j);
                    min1 = std::min(a, b);
                    min2 = std::min(e, f);
                    min = std::min(min1, min2);
                    if (((zone.getVal(i - 1, j)) != o) && ((zone.getVal(i - 1, j)) != d) && ((zone.getVal(i - 1, j)) != 0))

                    {
                        zone.setVal(i - 1, j, min + 1);
                    }


                }
            }
            //pour la ligne d'arriver
            for (int j = arrivj - 1; j >= 1; j--)
            {
                if (arrivi - 1 > 0)
                    a = zone.getVal(arrivi - 1, j);
                if (arrivi + 1 <= l)
                    b = zone.getVal(arrivi + 1, j);
                if (j + 1 <= c)
                    e = zone.getVal(arrivi, j + 1);
                if (j - 1 > 0)
                    f = zone.getVal(arrivi, j - 1);
                min1 = std::min(a, b);
                min2 = std::min(e, f);
                min = std::min(min1, min2);
                if (((zone.getVal(arrivi, j)) != o) && ((zone.getVal(arrivi, j)) != d) && ((zone.getVal(arrivi, j)) != 0))

                {
                    zone.setVal(arrivi, j, min + 1);
                }



            }
            for (int i = arrivi + 1; i <= l; i++)
            {
                if (i + 1 <= l)
                    a = zone.getVal(i + 1, arrivj);
                if (i - 1 > 0)
                    b = zone.getVal(i - 1, arrivj);
                if (arrivj + 1 <= c)
                    e = zone.getVal(i, arrivj + 1);
                if (arrivj - 1 > 0)
                    f = zone.getVal(i, arrivj - 1);
                min1 = std::min(a, b);
                min2 = std::min(e, f);
                min = std::min(min1, min2);
                if (((zone.getVal(i, arrivj)) != o) && ((zone.getVal(i, arrivj)) != d) && ((zone.getVal(i, arrivj)) != 0))

                {
                    zone.setVal(i, arrivj, min + 1);
                }

                //i:arriv i +1
                for (int j = arrivj - 1; j >= 1; j--)
                {
                    if (i - 2 > 0)
                        a = zone.getVal(i - 2, j);
                    if (j - 1 > 0)
                        b = zone.getVal(i - 1, j - 1);
                    if (i - 1 > 0)
                        e = zone.getVal(i - 1, j + 1);
                    if (i > 0)
                        f = zone.getVal(i, j);
                    min1 = std::min(a, b);
                    min2 = std::min(e, f);
                    min = std::min(min1, min2);
                    if (((zone.getVal(i - 1, j)) != o) && ((zone.getVal(i - 1, j)) != d) && ((zone.getVal(i - 1, j)) != 0))

                    {
                        zone.setVal(i - 1, j, min + 1);
                    }



                }

            }
            //pour la derniere ligne
            for (int j = arrivj - 1; j >= 1; j--)
            {
                a = zone.getVal(l - 1, j);

                e = zone.getVal(l, j + 1);
                if (j - 1 > 0)
                    f = zone.getVal(l, j - 1);
                min1 = std::min(a, b);
                min2 = std::min(e, f);
                min = std::min(min1, min2);
                if (((zone.getVal(l, j)) != o) && ((zone.getVal(l, j)) != d) && ((zone.getVal(l, j)) != 0))

                {
                    zone.setVal(l, j, min + 1);
                }



            }
            for (int i = 1; i <= l; i++)
            {
                for (int j = arrivj + 1; j <= c; j++)
                {
                    if (i + 1 <= l)
                        a = zone.getVal(i + 1, j);
                    if (i - 1 > 0)
                        b = zone.getVal(i - 1, j);
                    if (j + 1 <= c)
                        e = zone.getVal(i, j + 1);
                    if (j - 1 > 0)
                        f = zone.getVal(i, j - 1);
                    min1 = std::min(a, b);
                    min2 = std::min(e, f);
                    min = std::min(min1, min2);
                    if (((zone.getVal(i, j)) != o) && ((zone.getVal(i, j)) != d) && ((zone.getVal(i, j)) != 0))

                    {
                        zone.setVal(i, j, min + 1);
                    }
                }

            }
        }
        /*zone.afficherValZoneGeographique();
        cout << "ecrire un chiffre pour continuer" << endl;
        cin >> a;
        zone.afficherNatZoneGeographique();*/
    }

}
//Définition de la méthode arriv:
void Robot::arriv(int l, int k)
{
    arrivi = l;
    arrivj = k;
}
//Définition de la méthode getposi:
int Robot::getposi()const
{
    return posi;
}
//Définition de la méthode getposj:
int Robot::getposj()const
{
    return posj;
}
//Définition de la méthode setposi:
void Robot::setposi(int i)
{
    posi = i;
}
//Définition de la méthode setposj:
void Robot::setposj(int j)
{
    posj = j;
}
//Déclaration de la méthode choisir:
void Robot::choisir()
{
    int x, y, obstacles, n, m, i, j, l, k;
    cout << "donner le nombre de ligne de la zone : ";
    cin >> n;
    cout << "donner le nombre de colone de la zone : ";
    cin >> m;
    i = j = l = k = 1000;
    zone.setlc(n, m);

    //zone.afficherValZoneGeographique();
    while (i > m)
    {
        cout << "donner la position du depart suivant les lignes : ";
        cin >> i;

    }depi = i;

    while (j > n)
    {
        cout << "donner la position du depart suivant les colones : ";
        cin >> j;

    }depj = j;
    while (l > n)
    {
        cout << "donner la position d'arrive suivant les lignes : ";
        cin >> l;

    }arrivi = l;
    while (k > m)
    {
        cout << "donner la position d'arrive suivant les colonnes : ";
        cin >> k;

    } arrivj = k;

    Robot R(Robot(i, j));
    zone.setVal(i, j, n * m * 2);
    zone.setNat(i, j, 'd');
    zone.setVal(l, k, 0);
    zone.setNat(l, k, 'a');

    //zone.afficherValZoneGeographique();
    obstacles = n * m;
    while (obstacles > (n * m) - 2)
    {
        cout << "donner le nombre d'obstacles : ";
        cin >> obstacles;
    }
    for (int t(0); t < obstacles; t++)
    {
        int x(1000), y(1000);
        while (x > n)
        {
            cout << "ligne d'obs N° " << t + 1 << " : ";
            cin >> x;

            while (y > m)
            {
                while (true)
                {
                    cout << "colonne d'obs N° " << t + 1 << " : ";
                    cin >> y;
                    if (((x != i) || (y != j)) && ((x != l) || (y != k)))
                    {
                        break;
                    }
                }
            }
        }
        zone.setVal(x, y, n * m * 3);
        zone.setNat(x, y, 'o');
        //zone.afficherValZoneGeographique();
        //cout << zone.getVal(1, 1);
    }
}
//Définition de la méthode parcours:
void Robot::parcours()

{
    int l, x, y, c, v, d, o, n;
    int a(1000), b(1000), e(1000), f(1000), min1, min2;
    c = zone.getc();
    l = zone.getl();
    o = l * c * 3;
    d = l * c * 2;
    x = depi;
    y = depj;
    if (depi + 1 <= l)
        a = zone.getVal(depi + 1, depj);
    if (depi - 1 > 0)
        b = zone.getVal(depi - 1, depj);
    if (depj + 1 <= c)
        e = zone.getVal(depi, depj + 1);
    if (depj - 1 > 0)
        f = zone.getVal(depi, depj - 1);
    min1 = std::min(a, b);
    min2 = std::min(e, f);
    v = std::min(min1, min2);
    //cout << "ecrire un chiffre pour continuer" << endl;
    //cin >> n;
    while (v != 0)
    {
        if (x + 1 <= l)
            a = zone.getVal(x + 1, y);
        if (x - 1 > 0)
            b = zone.getVal(x - 1, y);
        if (y + 1 <= c)
            e = zone.getVal(x, y + 1);
        if (y - 1 > 0)
            f = zone.getVal(x, y - 1);

        if (a == v)
        {
            x = x + 1;
            v--;

        }
        else if (b == v)
        {
            x = x - 1;
            v--;
        }
        else if (e == v)
        {
            y = y + 1;
            v--;

        }
        else
        {
            y = y - 1;
            v--;

        }
        zone.setVal(x, y, 500);
        zone.setNat(x, y, 'c');
    }
    /*zone.afficherValZoneGeographique();
    cout << "ecrire un chiffre pour continuer" << endl;
    cin >> n;*/

    //zone.afficherNatZoneGeographique();

}
ZoneGeographique Robot::getZone() {
    return zone;
}
int Robot::get_arrivi() {
    return arrivi;
}
int Robot::get_arrivj() {
    return arrivj;
}
int Robot::get_depi() {
    return depi;
}
int Robot::get_depj() {
    return depj;
}
