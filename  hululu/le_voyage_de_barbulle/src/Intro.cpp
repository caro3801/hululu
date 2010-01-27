/*
 * Intro.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: talotte
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Intro.h"
#include "DefineEcrans.h"
#include "Musique.h"

#include "Bouton.h"
#include "Page.h"

#include "effetSurTexte.h"

Intro::Intro() {
	this->etape = 0;

}

Intro::~Intro() {
	// TODO Auto-generated destructor stub
}

int Intro::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = INTRO_G;
	Page modelePage;


	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();

	vector<Musique *> tabMusic;

	// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	// ELEMENTS /////////////////////////

	// -- fond
	sf::Sprite accueil;
	accueil.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/accueil/fondaccueil.png"));
	accueil.SetPosition(0.f, 0.f);
	accueil.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// -- sous-titre

	//ecran1
	sf::String txtSousTitre1("Il etait une fois...");
	txtSousTitre1.SetSize(40.f);
	txtSousTitre1.SetFont(cursiveFont);
	txtSousTitre1.SetColor(sf::Color(48,84,163));
	int position[2];
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre1.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre1.GetRect().GetHeight() );
	txtSousTitre1.SetPosition(position[0],position[1]);

	//ecran2
	sf::String txtSousTitre2("soudain");
	txtSousTitre2.SetSize(40.f);
	txtSousTitre2.SetFont(cursiveFont);
	txtSousTitre2.SetColor(sf::Color(48,84,163));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre2.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre2.GetRect().GetHeight() );
	txtSousTitre2.SetPosition(position[0],position[1]);

	//ecran3
	sf::String txtSousTitre3("ouah");
	txtSousTitre3.SetSize(40.f);
	txtSousTitre3.SetFont(cursiveFont);
	txtSousTitre3.SetColor(sf::Color(48,84,163));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre3.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre3.GetRect().GetHeight() );
	txtSousTitre3.SetPosition(position[0],position[1]);

	//ecran4
	sf::String txtSousTitre4("Tout à coup");
	txtSousTitre4.SetSize(40.f);
	txtSousTitre4.SetFont(cursiveFont);
	txtSousTitre4.SetColor(sf::Color(48,84,163));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre4.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre4.GetRect().GetHeight() );
	txtSousTitre4.SetPosition(position[0],position[1]);

	//ecran5
	sf::String txtSousTitre5("Aaaaaahhhh");
	txtSousTitre5.SetSize(40.f);
	txtSousTitre5.SetFont(cursiveFont);
	txtSousTitre5.SetColor(sf::Color(48,84,163));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre5.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre5.GetRect().GetHeight() );
	txtSousTitre5.SetPosition(position[0],position[1]);

	//ecran6
	sf::String txtSousTitre6("Bonjour");
	txtSousTitre6.SetSize(40.f);
	txtSousTitre6.SetFont(cursiveFont);
	txtSousTitre6.SetColor(sf::Color(48,84,163));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre6.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre6.GetRect().GetHeight() );
	txtSousTitre6.SetPosition(position[0],position[1]);

	//ecran7
	sf::String txtSousTitre7("Je ne peux pas");
	txtSousTitre7.SetSize(40.f);
	txtSousTitre7.SetFont(cursiveFont);
	txtSousTitre7.SetColor(sf::Color(48,84,163));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre7.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre7.GetRect().GetHeight() );
	txtSousTitre7.SetPosition(position[0],position[1]);

	//ecran8
	sf::String txtSousTitre8("Ce passage");
	txtSousTitre8.SetSize(40.f);
	txtSousTitre8.SetFont(cursiveFont);
	txtSousTitre8.SetColor(sf::Color(48,84,163));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre8.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre8.GetRect().GetHeight() );
	txtSousTitre8.SetPosition(position[0],position[1]);

	switch (etape) {
		case 0:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page1.ogg"));
			break;
		case 1:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page2.ogg"));
			break;
		case 2:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page3.ogg"));
			break;
		case 3:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page4.ogg"));
			break;
		case 4:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page5.ogg"));
			break;
		case 5:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page6.ogg"));
			break;
		case 6:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/ouipage7.ogg"));
			break;
		case 7:
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/ouipage8.ogg"));
			break;
	}

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	tabMusic[0]->Lecture();

	// # Pour que le programme ne se termine pas :)
	sf::Event event;
	unsigned int etapeInitiale = etape;

	while (fenetre.IsOpened() && (ecranSuivant == INTRO_G) && (etapeInitiale == etape) )
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

		// on surveille l'avancement de la lecture
		if(tabMusic[0]->GetStatus() == sf::Music::Stopped && (etape < 7) )
			etape++;

		switch (etape) {
		case 0:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre1);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					ecranSuivant = MENU_0;
				} else
					ecranSuivant = MAPPEMONDE;
			}
			break;

		case 1:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre2);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;
		case 2:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre3);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}
			break;

		case 3:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre4);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;
		case 4:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre5);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;
		case 5:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre6);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;
		case 6:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre7);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;

		case 7:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre8);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape=0;
					ecranSuivant = MAPPEMONDE;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;
		}

		// PAUSE/PLAY instruction ///////////
		if(!modelePage.getPlaying() ) {
			if(tabMusic[0]->GetStatus() == sf::Music::Paused) {
				tabMusic[0]->Lecture();
			}
		}
		else {
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
	}

	// INTERUPTION de toutes les musiques
	for(unsigned int i = 0; i < tabMusic.size(); i++)
		tabMusic[i]->Stop();
	return ecranSuivant;
}
