/*
 * TrajetANZ.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#include "TrajetANZ.h"
#include "DefineEcrans.h"

#include "Person2D.h"
#include "Bouton.h"
#include "Page.h"
#include "Musique.h"
#include "effetSurTexte.h"


TrajetANZ::TrajetANZ() {
	// TODO Auto-generated constructor stub

}

TrajetANZ::~TrajetANZ() {
	// TODO Auto-generated destructor stub
}


int TrajetANZ::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = TRAJET_ANZ;
	Page modelePage;

	sf::Clock clock;
	clock.Reset();

	// LISTE musique ////////////////////
	vector<Musique *> tabMusic;
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/australie/aust1.ogg"));


	// IMAGE DE FONT ////////////////////
	sf::Sprite background;
	background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/bgBateau.png"));
	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	// BATEAU ////////////////////
	sf::Sprite bateau;
	bateau.SetColor(sf::Color(255,255,255,255));
	bateau.SetPosition(fenetre.GetWidth()-600, 400);
	bateau.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/bateau_translate.png"));

	// VUE ///////////////////////
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Event event;
	int alpha = 255;

	while (fenetre.IsOpened() && (ecranSuivant == TRAJET_ANZ) )
	{
		// EVENEMENTS ///////////////////////
		while (fenetre.GetEvent(event))
		{
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type == sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
				fenetre.Close();
		}

		 if( (bateau.GetPosition().x < fenetre.GetWidth() )
		 &&  (bateau.GetPosition().y > 0)
		 && (clock.GetElapsedTime()*1000 > 50) ){
			 bateau.SetPosition(bateau.GetPosition().x + 6, bateau.GetPosition().y - 4);
			 bateau.Scale(0.99, 0.99);
			 if(alpha>0)
			 {
				 alpha -= 2;
				 bateau.SetColor(sf::Color(255,255,255,alpha));
			 }

			 clock.Reset();
		 }

		// PAUSE/PLAY instruction ///////////
		if(!modelePage.getPlaying() ) {
			if(tabMusic[0]->GetStatus() == sf::Music::Paused) {
				tabMusic[0]->Lecture();
			}
		} else {
			 if(tabMusic[0]->GetStatus() == sf::Music::Playing) {
				tabMusic[0]->Pause();
			 }
		}

		// REPETER instruction ///////////////
		if(modelePage.getRepeterClique(fenetre) ) {
				tabMusic[0]->Stop();
				tabMusic[0]->Lecture();
		}

		// MUTE instruction //////////////////
		if(!modelePage.getMuting())
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(0);
		else
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(100);

		// DESSINS  //////////////////////////
		fenetre.Draw(background);
		fenetre.Draw(bateau);
		modelePage.dessinerPage(fenetre);


		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
			ecranSuivant = modelePage.changerEcran(fenetre, TRAJET_ANZ, NZ_INTRO, AUSTRALIE_PRESENT) ;

		fenetre.Display();
	}

	return ecranSuivant;
}
