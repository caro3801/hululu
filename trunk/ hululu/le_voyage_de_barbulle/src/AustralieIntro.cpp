/*
 * AutralieIntro.cpp
 *
 *  Created on: 24 janv. 2010
 *      Author: pirhoo
 */

#include "AustralieIntro.h"
#include "DefineEcrans.h"

#include <iostream>
using namespace std;

AustralieIntro::AustralieIntro() {
	// TODO Auto-generated constructor stub

}

AustralieIntro::~AustralieIntro() {
	// TODO Auto-generated destructor stub
}

int AustralieIntro::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = AUSTRALIE_INTRO;

	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();

	// IMAGE DE FONT ////////////////////
	sf::Sprite backgroundKangoo;
	backgroundKangoo.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/kangou.jpg"));
	backgroundKangoo.SetPosition(0.f, 0.f);
	backgroundKangoo.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;
	while (fenetre.IsOpened())
	{

		// EVENEMENTS ///////////////////////
		while (fenetre.GetEvent(event))
		{
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type == sf::Event::KeyReleased && event.Key.Code
					== sf::Key::Escape)
				fenetre.Close();
		}


		// DESSINS  //////////////////////////
		fenetre.Clear(sf::Color(255, 255, 255));
		fenetre.Draw(backgroundKangoo);
		fenetre.Display();
	}

	return ecranSuivant;
}
