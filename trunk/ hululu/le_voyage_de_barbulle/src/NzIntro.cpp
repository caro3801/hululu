/*
 * NzIntro.cpp
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

#include "NzIntro.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Page.h"
#include "Musique.h"
#include "effetSurTexte.h"

NzIntro::NzIntro() {
	// TODO Auto-generated constructor stub

}

NzIntro::~NzIntro() {
	// TODO Auto-generated destructor stub
}

int NzIntro::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = NZ_INTRO;
	Page modelePage;

	// LISTE musique ////////////////////
	vector<Musique *> tabMusic;
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/australie/aust1.ogg"));


	// IMAGE DE FONT ////////////////////
	sf::Sprite background;
	background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/nz/paysage.jpg"));
	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());


	// VUE ///////////////////////
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Event event;

	while (fenetre.IsOpened() && (ecranSuivant == NZ_INTRO) )
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
		modelePage.dessinerPage(fenetre);


		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
			ecranSuivant = modelePage.changerEcran(fenetre, NZ_INTRO, -1,TRAGET_ANZ) ;

		fenetre.Display();
	}

	return ecranSuivant;
}
