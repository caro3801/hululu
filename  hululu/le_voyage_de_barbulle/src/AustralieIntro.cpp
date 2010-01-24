/*
 * AutralieIntro.cpp
 *
 *  Created on: 24 janv. 2010
 *      Author: pirhoo
 */

#include "AustralieIntro.h"
#include "DefineEcrans.h"

AustralieIntro::AustralieIntro() {
	// TODO Auto-generated constructor stub

}

AustralieIntro::~AustralieIntro() {
	// TODO Auto-generated destructor stub
}

int AustralieIntro::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = MAPPEMONDE;
	sf::Clock Clock; //Horloge
	Clock.Reset();

	sf::Event event;
	while (fenetre.IsOpened())

	{

		// EVENEMENTS //////////////////////////////////////////
		while (fenetre.GetEvent(event))
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type == sf::Event::KeyReleased && event.Key.Code
					== sf::Key::Escape)
				fenetre.Close();
	}

	return ecranSuivant;
}
