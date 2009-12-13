/*
 * Italie.cpp
 *
 *  Created on: 12 déc. 2009
 *      Author: sof
 */
#include <iostream>
using namespace std;

#include "Italie.h"

Italie::Italie() {
}

Italie::~Italie() {
}

int Italie::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 2;

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image fond
	sf::Image fond_italie;
	if (!fond_italie.LoadFromFile("le_voyage_de_barbulle/img/italie/italie_fond.png"))
		cerr << "Erreur lors du chargement de l'image.";

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
	sf::Sprite fond(fond_italie);
	fond.SetPosition(0.f, 0.f);
	fond.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;

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

		fenetre.Draw(fond);
		fenetre.Display();

	}
	return  ecranSuivant;

}
