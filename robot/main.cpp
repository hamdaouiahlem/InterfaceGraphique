#include <iostream>
#include <ostream>
#include <string>
#include "Case.h"
#include "Robot.h"
#include "ZoneGeographique.h"
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <windows.h>


using namespace std;

int main() {

    Robot r(1, 1);
    r.choisir();
    r.setValeurs();
    r.parcours();

    ZoneGeographique zone = r.getZone();
    vector<vector<Case>> z = zone.get_zone();
    int n = zone.getl();
    int m = zone.getc();

    sf::Texture bg;
    bg.loadFromFile("images/back.jpg");
    sf::Sprite background(bg);

    int a, b, c, d;

    a = r.get_depi();
    b = r.get_depj();
    c = r.get_arrivi();
    d = r.get_arrivj();

    sf::Sprite Grill[25][25];
    sf::Texture box;
    box.loadFromFile("images/box.png");
    int x = 30;
    int y = 30;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Grill[i][j].setTexture(box);
            Grill[i][j].setPosition(sf::Vector2f(x, y));
            x += 73;
        }
        x = 30;
        y += 73;
    }

    sf::Texture rb;
    rb.loadFromFile("images/robot.png");
    sf::Sprite robot(rb);
    sf::Texture ff;
    ff.loadFromFile("images/finish.png");
    sf::Sprite finish(ff);
    sf::Texture chm;
    chm.loadFromFile("images/chemin.png");
    sf::Texture obstacl;
    obstacl.loadFromFile("images/obstacle.png");
    sf::Font font;
    font.loadFromFile("images/Dimbo Regular.ttf");
    sf::Text msg("Voila Le chemin ! ", font);
    msg.setCharacterSize(80);
    msg.setPosition(sf::Vector2f(900, 300));
    msg.setFillColor(sf::Color(13, 17, 55));

    int initx, inity, finx, finy;
    initx = Grill[a-1][b-1].getPosition().x;
    inity = Grill[a-1][b-1].getPosition().y;
    finx = Grill[c-1][d-1].getPosition().x;
    finy = Grill[c-1][d-1].getPosition().y;
    robot.setPosition(sf::Vector2f(initx + 20, inity + 20));
    finish.setPosition(sf::Vector2f(finx + 20, finy + 20));

    sf::RectangleShape rect[25];
    sf::RectangleShape chemin[25];


    int nbo, xoc, yoc;
    nbo = zone.get_nbo();
    int nb = 0;
    int nbc = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char nat = z[i][j].getNature();
            if (nat == 'o') {
                xoc = i;
                yoc = j;
                rect[nb].setTexture(&obstacl);
                rect[nb].setSize(sf::Vector2f(60, 60));
                rect[nb].setPosition(sf::Vector2f(Grill[xoc][yoc].getPosition().x + 20, Grill[xoc][yoc].getPosition().y + 20));
                nb++;
            }
            if (nat == 'c') {
                xoc = i;
                yoc = j;
                chemin[nbc].setSize(sf::Vector2f(60, 60));
                chemin[nbc].setTexture(&chm);
                chemin[nbc].setPosition(sf::Vector2f(Grill[xoc][yoc].getPosition().x + 20, Grill[xoc][yoc].getPosition().y + 20));
                nbc++;
            }
        }
    }
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Plus Court Chemin");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                window.draw(Grill[i][j]);
            }
        }
        for (int i = 0; i < nbo; i++) {
            window.draw(rect[i]);
        }
        for (int i = 0; i < 25; i++) {
            window.draw(chemin[i]);
        }
        window.draw(msg);
        window.draw(robot);
        window.draw(finish);
        window.display();
    }
}