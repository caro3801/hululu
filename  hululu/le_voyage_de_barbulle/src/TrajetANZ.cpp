/*
 * TrajetANZ.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#include "TrajetANZ.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Page.h"
#include "Musique.h"
#include "effetSurTexte.h"

TrajetANZ::TrajetANZ() {
	// TODO Auto-generated constructor stub

}

TrajetANZ::~TrajetANZ() {
	// TODO Auto-generated destructor stub
}


int TrajetANZ::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = TRAGET_ANZ;
	Page modelePage;

	// IMAGE DE FONT ////////////////////
	sf::Sprite background;
	background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/uluru.jpg"));
	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	while (fenetre.IsOpened() && (ecranSuivant == TRAGET_ANZ) )
	{
		fenetre.Draw(background);
		fenetre.Display();
	}

	return ecranSuivant;
}
