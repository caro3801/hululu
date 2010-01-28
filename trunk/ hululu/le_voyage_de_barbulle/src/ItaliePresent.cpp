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
#include <SFML/Audio.hpp>

#include "ItaliePresent.h"
#include "Page.h"
#include "Musique.h"
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

	vector<Musique *> tabMusic;

	// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	sf::Sprite background;
	switch (etape) {
			case 0:
				background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/present1.png"));
				tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/italie/it1.ogg"));
				break;
			case 1:
				background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/present2.png"));
				tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/italie/it2.ogg"));
				break;
			case 2:
				background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/present3.png"));
				tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/italie/it3.ogg"));
				break;
		}
	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()));
	fenetre.SetView(vue);
	// # Pour que le programme ne se termine pas :)
	sf::Event event;

	tabMusic[0]->Lecture();

	unsigned int etapeInitiale = etape;

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
		// on surveille l'avancement de la lecture
		if(tabMusic[0]->GetStatus() == sf::Music::Stopped && (etape < 2) )
				etape++;

		switch (etape) {
		case 0:
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

		// PAUSE/PLAY instruction ///////////
		if(!pays.getPlaying() ) {
			if(tabMusic[0]->GetStatus() == sf::Music::Paused) {
				tabMusic[0]->Lecture();
			}
		} else {
			 if(tabMusic[0]->GetStatus() == sf::Music::Playing) {
				tabMusic[0]->Pause();
			 }
		}

		// REPETER instruction ///////////////
		if(pays.getRepeterClique(fenetre) ) {
				tabMusic[0]->Stop();
				tabMusic[0]->Lecture();
		}

		// MUTE instruction //////////////////
		if(!pays.getMuting())
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(0);
		else
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(100);

		// DESSINS  //////////////////////////
		fenetre.Draw(background);
		pays.dessinerPage(fenetre);

		fenetre.Display();
	}
	// INTERUPTION de toutes les musiques
	for(unsigned int i = 0; i < tabMusic.size(); i++)
		tabMusic[i]->Stop();

	if(ecranSuivant != ITALIEPRESENT)
		etape = 0;


	// on éteint
	return ecranSuivant;
}
