/*
 * PoleSud_Porte.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#include "PoleSud_Porte.h"
#include <iostream>
using namespace std;

// WIKI SFML //////////////////////////
#include "BoutonMove.h"
#include "AccueilPays.h"
#include "Page.h"
#include "Bouton.h"
#include "Objet.h"

PoleSud_Porte::PoleSud_Porte() {

}

PoleSud_Porte::~PoleSud_Porte() {
}

int PoleSud_Porte::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = POLESUD_PORTE;
	sf::Clock Clock;
	Clock.Reset();

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
	sf::Sprite fond ;
	fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_sans_objets.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	sf::Sprite porte_blason ;
	porte_blason.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_blason.png"));
	porte_blason.SetPosition(0.f, 0.f);
	porte_blason.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
		fenetre.Draw(fond);
		pays.dessinerPage(fenetre);
		blason.setNom("blabla");
		cout << blason.getNom() << endl;
//		if(blason_o.getTrouve()==true) {
//			cout <<"ok"<< endl;
//			fenetre.Draw(porte_blason);
//		}
		fenetre.Display();

		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			return ecranSuivant=pays.changerEcran(fenetre,POLESUD_PORTE,POLESUD_PORTE,MAPPEMONDE) ;

	}

	return ecranSuivant;

}
