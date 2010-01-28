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
#include <SFML/Audio.hpp>

#include "ItalieMusee.h"
#include "Page.h"
#include "Musique.h"
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

	// LISTE musique ////////////////////
	vector<Musique *> tabMusic;
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/italie/itmusee.ogg"));
	tabMusic[0]->Lecture();


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

	//Dessin //////////////////////
	fenetre.Clear();
	fenetre.Draw(fond);
	pays.dessinerPage(fenetre);
	fenetre.Display();

//		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left)	&& pays.menuActif(fenetre))
//			ecranSuivant = pays.changerEcran(fenetre, ITALIEMUSEE, JEU_ITALIE,
//					ITALIEPRESENT);
	}
	// INTERUPTION de toutes les musiques
		for(unsigned int i = 0; i < tabMusic.size(); i++)
			tabMusic[i]->Stop();

		// on éteint
	return ecranSuivant;

}
