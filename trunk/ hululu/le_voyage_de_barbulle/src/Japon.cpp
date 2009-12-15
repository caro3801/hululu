/*
 * Japon.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: pollet
 */
#include <iostream>
using namespace std;
#include "Japon.h"

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// WIKI SFML //////////////////////////
#include "Japon.h"
#include "Bouton.h"

Japon::Japon() {
	// TODO Auto-generated constructor stub

}

Japon::~Japon() {
	// TODO Auto-generated destructor stub
}

int Japon::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 1;

	//IMAGES////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //SPRITES///////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
		sf::Sprite fond ;
		fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/japon_fond.png"));
		fond.SetPosition(0.f, 0.f);
		fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

		sf::Sprite back_icon ;
		back_icon.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/back_icon.png"));
		back_icon.SetPosition((fenetre.GetWidth()-100),(fenetre.GetHeight()-100));
		back_icon.Resize(30,30);

		// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		sf::String texte("日本へようこそ Bienvenue au Japon");
		texte.SetColor(sf::Color::Red);
		texte.SetSize(25.f);
		texte.SetPosition((fenetre.GetWidth()/3), (fenetre.GetHeight()/3));

		sf::Event event;

		// # création d'une vue sur la fenêtre
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
				fenetre.Draw(texte);
				fenetre.Draw(back_icon);
				fenetre.Display();
				if ((fenetre.GetInput().IsKeyDown(sf::Key::Space)))
					return (ecranSuivant=1);
			}

			return ecranSuivant;

		}


