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
#include "DefineEcrans.h"
// à chaque écran un numéro (à respecter tout au long du programme)
#include "Menu_0.h"				// numéro 0
#include "Mapmonde.h"			// numéro 1
#include "Italie.h"				// numero 2
#include "Japon.h"    	 		// numéro 3
#include "JeuItalie.h"			// numéro 4
#include "Perou.h"				// numéro 5
#include "JeuPerou.h"			// numéro 6
#include "AustralieIntro.h"		// numéro 7
#include "PoleSud_Porte.h" 		// numero 8
#include "AustraliePresent.h"	// numero 9
#include "ItaliePresent.h"
#include "JeuJapon.h"
#include "HistoireJapon.h"
#include "JaponGagne.h"
#include "Intro.h"//numero14

// PROCEDURE PRINCIPALE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{

	// # Vecteur contenant les adresses des variables-écran
	vector<Ecran*> tabEcrans;
    int ecran = MENU_0;

    // # création de la fenêtre
    sf::RenderWindow fenetre(sf::VideoMode::GetMode(0), "Le voyage de Barbule", sf::Style::Fullscreen);
	fenetre.SetFramerateLimit(60); //limite la génération d'images a 60/s

    // # Instanciation de tous les écrans
	// Le menu principal
	Menu_0 ecran0;
    tabEcrans.push_back (&ecran0);
    Mapmonde ecran1;
    tabEcrans.push_back (&ecran1);
    Italie ecran2;
    tabEcrans.push_back (&ecran2);
    Japon ecran3;
    tabEcrans.push_back (&ecran3);
    JeuItalie ecran4;
    tabEcrans.push_back(&ecran4);
    Perou ecran5;
    tabEcrans.push_back (&ecran5);
    JeuPerou ecran6;
    tabEcrans.push_back (&ecran6);
    AustralieIntro ecran7;
    tabEcrans.push_back (&ecran7);
    PoleSud_Porte ecran8;
    tabEcrans.push_back (&ecran8);
    AustraliePresent ecran9;
    tabEcrans.push_back (&ecran9);
    HistoireJapon ecran10;
    tabEcrans.push_back (&ecran10);
    JeuJapon ecran11;
    tabEcrans.push_back (&ecran11);

    JaponGagne ecran13;
    tabEcrans.push_back (&ecran13);
    Intro ecran14;
    tabEcrans.push_back (&ecran14);

    // # boucle principale, c'est ici que tt commence...
    while ( ecran >= 0 and fenetre.IsOpened() ) // -1 provoque l'arrêt du programme
        ecran = tabEcrans[ecran]->run(fenetre);

    return 0;
}
