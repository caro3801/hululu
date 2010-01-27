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
	this->etape = 0;
	// TODO Auto-generated constructor stub

}

ItaliePresent::~ItaliePresent() {
	// TODO Auto-generated destructor stub
}
int ItaliePresent::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = ITALIEPRESENT;

	Page pays;

	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();

	// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	// ecran de présentation numero 1
	sf::Sprite present1;
	present1.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/present1.png"));
	present1.SetPosition(0.f, 0.f);
	present1.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// ecran de présentation numero 2
	sf::Sprite present2;
	present2.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/present2.png"));
	present2.SetPosition(0.f, 0.f);
	present2.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// ecran de présentation numero 3
	sf::Sprite present3;
	present3.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/present3.png"));
	present3.SetPosition(0.f, 0.f);
	present3.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()));
	fenetre.SetView(vue);
	// # Pour que le programme ne se termine pas :)
	sf::Event event;

	int etapeInitiale = etape;

	while (fenetre.IsOpened() && (ecranSuivant == ITALIEPRESENT) && (etapeInitiale == etape) ) {

		while (fenetre.GetEvent(event)) {
			// # Instanciation de tous les éc fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type == sf::Event::KeyReleased && event.Key.Code
					== sf::Key::Escape)
				fenetre.Close();
		}


		switch (etape) {
		case 0:
			fenetre.Draw(present1);
			pays.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre)) {
				if (pays.getGoClique(fenetre)) {
					pays.getGo().resetTimer();
					etape++;
					ecranSuivant = ITALIEPRESENT;

				} else if (pays.getBackClique(fenetre)) {
					pays.getBack().resetTimer();
					ecranSuivant = ITALIE;
				} else
					ecranSuivant = MAPPEMONDE;
			}
			break;

		case 1:
			fenetre.Draw(present2);
			pays.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre)) {
				if (pays.getGoClique(fenetre)) {
					pays.getGo().resetTimer();
					etape++;
					ecranSuivant = ITALIEPRESENT;
				} else if (pays.getBackClique(fenetre)) {
					pays.getBack().resetTimer();
					etape--;
					ecranSuivant = ITALIEPRESENT;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;
		case 2:
			fenetre.Draw(present3);
			pays.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre)) {
				if (pays.getGoClique(fenetre)) {
					pays.getGo().resetTimer();
					etape = 0;
					ecranSuivant = ITALIEMUSEE;
				} else if (pays.getBackClique(fenetre)) {
					pays.getBack().resetTimer();
					etape--;
					ecranSuivant = ITALIEPRESENT;
				} else
					ecranSuivant = MAPPEMONDE;
			}
			break;
		}
	}

	return ecranSuivant;
}
