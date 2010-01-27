/*
 * ItalieMusee.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: caroline
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ItalieMusee.h"
#include "Page.h"
#include "DefineEcrans.h"
ItalieMusee::ItalieMusee() {
	// TODO Auto-generated constructor stub

}

ItalieMusee::~ItalieMusee() {
	// TODO Auto-generated destructor stub
}
int ItalieMusee::run(sf::RenderWindow &fenetre) {
	int ecranSuivant = ITALIEMUSEE;
	Page pays;
	sf::Sprite fond;
	fond.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/italieMusee.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()));
	fenetre.SetView(vue);

	///AFFICHAGE FENETRE///////////////////////////////

	while (fenetre.IsOpened() && (ecranSuivant == ITALIEMUSEE) ) {

			while (fenetre.GetEvent(event)) {
				// # Instanciation de tous les éc fermeture de la fenetre
				// si echap ou fermeture manuelle
				if (event.Type == sf::Event::Closed)
					fenetre.Close();
				else if (event.Type == sf::Event::KeyReleased && event.Key.Code
						== sf::Key::Escape)
					fenetre.Close();
			}
		fenetre.Clear();
		fenetre.Draw(fond);
		pays.dessinerPage(fenetre);


		fenetre.Display();

		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left)	&& pays.menuActif(fenetre))
			ecranSuivant = pays.changerEcran(fenetre, ITALIEMUSEE, JEU_ITALIE,
					ITALIEPRESENT);
	}
	return ecranSuivant;

}
