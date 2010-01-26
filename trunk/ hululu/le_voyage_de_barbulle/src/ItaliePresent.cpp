/*
 * ItaliePresent.cpp
 *
 *  Created on: 26 janv. 2010
 *      Author: anthony
 */
#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ItaliePresent.h"
#include "Page.h"
#include "DefineEcrans.h"

ItaliePresent::ItaliePresent() {
	// TODO Auto-generated constructor stub

}

ItaliePresent::~ItaliePresent() {
	// TODO Auto-generated destructor stub
}
int ItaliePresent::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = ITALIE_PRESENT;



	Page pays;

	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();




// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile(
			"le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	// ecran de présentation numero 1
	sf::Sprite present1;
	present1.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/present1.png"));
			present1.SetPosition(0.f, 0.f);
			present1.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));


	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()));
	fenetre.SetView(vue);
	// # Pour que le programme ne se termine pas :)
	sf::Event event;
	while (fenetre.IsOpened() && ecranSuivant == JEU_ITALIE) {
		while (fenetre.GetEvent(event)) {

			// # Instanciation de tous les éc fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type == sf::Event::KeyReleased && event.Key.Code
					== sf::Key::Escape)
				fenetre.Close();
		}
		fenetre.Draw(present1);
		fenetre.Display();
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
					return ecranSuivant=pays.changerEcran(fenetre,ITALIE_PRESENT,JEU_ITALIE,ITALIE) ;
	}
	return ecranSuivant;
}
