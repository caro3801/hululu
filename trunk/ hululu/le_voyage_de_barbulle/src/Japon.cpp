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



Japon::Japon() {
	// TODO Auto-generated constructor stub

}

Japon::~Japon() {
	// TODO Auto-generated destructor stub
}


int Japon::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 3;
	sf::Clock Clock;
	Clock.Reset();

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;
	AccueilPays japon;
	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//japon.InfosPays(fenetre,"Bienvenue au Japon","日本へようこそ");

		sf::Event event;

		sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
		fenetre.SetView(vue);

		////////////////////////////////

			while(fenetre.IsOpened())
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
				//japon.dessiner(fenetre,"le_voyage_de_barbulle/img/accueil/japon.png");
				pays.dessinerPage(fenetre);
				fenetre.Display();

				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
					return ecranSuivant=pays.changerEcran(fenetre,3,5,1) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
																		   //ecranPrecedent = Mapmonde (1)
				if (fenetre.GetInput().IsKeyDown(sf::Key::O))
								return ecranSuivant=5;
			}

			return ecranSuivant;
}
