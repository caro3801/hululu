/*
 * Japon.cpp
 *
 *  Created on: 24 déc. 2009
 *      Author: pollet
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// WIKI SFML //////////////////////////
#include "Japon.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "Page.h"
#include "DefineEcrans.h"



Japon::Japon() {
	// TODO Auto-generated constructor stub

}

Japon::~Japon() {
	// TODO Auto-generated destructor stub
}


int Japon::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = JAPON;
	sf::Clock Clock;
	Clock.Reset();

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;

	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;


	AccueilPays japon(fenetre,"le_voyage_de_barbulle/img/accueil/japon.png", "le_voyage_de_barbulle/img/japon/japon.jpg", "Bienvenue au Japon","日本へようこそ", sf::Color::White,sf::Color::White);
	japon.mettrePolice(cursiveFont, 40,30);
	japon.initAccueil(fenetre);
	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		sf::Event event;

		sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
		fenetre.SetView(vue);

		////////////////////////////////

			while(fenetre.IsOpened() && (ecranSuivant == JAPON))
			{
				while (fenetre.GetEvent(event)) {
					// # Instanciation de tous les éc fermeture de la fenetre
					// si echap ou fermeture manuelle
					if (event.Type == sf::Event::Closed)
						fenetre.Close();
					else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
						fenetre.Close();
				}

				fenetre.Clear(sf::Color(255, 255, 255));
				japon.dessinerAccueil(fenetre);
				pays.dessinerPage(fenetre);
				fenetre.Display();

				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
					ecranSuivant=pays.changerEcran(fenetre,JAPON,HISTOIREJAPON,MAPPEMONDE) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
																		   //ecranPrecedent = Mapmonde (1)
				if (fenetre.GetInput().IsKeyDown(sf::Key::O))
					ecranSuivant=HISTOIREJAPON;

			}

			return ecranSuivant;
}
