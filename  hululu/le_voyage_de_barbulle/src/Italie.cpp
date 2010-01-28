/*
 * Italie.cpp
 *
 *  Created on: 12 déc. 2009
 *      Author: sof
 */
#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>#include <SFML/Audio.hpp>

// WIKI SFML //////////////////////////
#include "Italie.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "Page.h"
#include "DefineEcrans.h"
#include "Musique.h"


ImageManager Ecran::MonManager; //a ne definir qu'une seule fois dans tout le programme

Italie::Italie() {
}

Italie::~Italie() {
}

int Italie::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = ITALIE;
	sf::Clock Clock;
	Clock.Reset();

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;

	vector<Musique *> tabMusic;

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Font cursiveFont;
		if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
					cerr << "Erreur lors du chargement de la police" << endl;

	AccueilPays italie(fenetre,"le_voyage_de_barbulle/img/accueil/italie.png","le_voyage_de_barbulle/img/italie/italie_fond.png","Europe et Italie","L'art de l'entourloupe",sf::Color::Green,sf::Color::Red);
		italie.mettrePolice(cursiveFont, 40,30);
		italie.initAccueil(fenetre);
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/italie/itbienv.ogg"));
	sf::Event event;

	// # création d'une vue sur la fenêtre - !! Puisqu'une vue a été créee sur l'ecran précédent (Mapemonde) obligé de recréer une vue
	//pour toutes les fenetres suivantes, ou images et sprites ne s'affichent pas!
	//a voir pour trouver une autre solution : suppression vue ? re-definition de la vue par defaut ?
	//ou on crée une autre vue a chaque fois.


	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);
	////////////////////////////////
	tabMusic[0]->Lecture();

	while(fenetre.IsOpened() && (ecranSuivant == ITALIE))
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
		italie.dessinerAccueil(fenetre);
		pays.dessinerPage(fenetre);
		fenetre.Display();
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			ecranSuivant=pays.changerEcran(fenetre,ITALIE,ITALIEPRESENT,MAPPEMONDE) ; //ecranSuivant = jeuItalie (4), ecranCourant = Italie (2),
																   //ecranPrecedent = Mapmonde (1)

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

	}
	// INTERUPTION de toutes les musiques
	for(unsigned int i = 0; i < tabMusic.size(); i++)
		tabMusic[i]->Stop();

	return ecranSuivant;

}
