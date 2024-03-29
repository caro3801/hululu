/*
 * main.cpp
 *
 *  Created on: 10 déc. 2009
 *      Author: nous
 */


#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// MANIPULATEURS/////////////////////////////
// homemade ;)
#include "Person2D.h"
#include "Bouton.h"
#include "Ecran.h"

// ECRANS/////////////////////////////
// à chaque écran un numéro (à respecter tout au long du programme)
#include "Menu_0.h"		// numéro 0
#include "Mapmonde.h"	// numéro 1
#include "JeuPerou.h"		// numéro 2

// PROCEDURE PRINCIPALE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	// # Vecteur contenant les adresses des variables-écran
	vector<Ecran*> tabEcrans;
    int ecran = 1; // ecran en cours (naturellement, on commence par le premier)

    // # création de la fenêtre
    sf::RenderWindow fenetre(sf::VideoMode::GetMode(0), "Le voyage de Barbule", sf::Style::Fullscreen);
	fenetre.SetFramerateLimit(60); //limite la génération d'images a 60/s

    // # Instenciation de tous les écrans
	// Le menu principal
    Menu_0 ecran0;
    tabEcrans.push_back (&ecran0);
    Mapmonde ecran1;
    tabEcrans.push_back (&ecran1);

    // # boucle principale, c'est ici que tt commence...
    while ( ecran >= 0 and fenetre.IsOpened() ) // -1 provoque l'arrêt du programme
        ecran = tabEcrans[ecran]->run(fenetre);


    return 0;
}
