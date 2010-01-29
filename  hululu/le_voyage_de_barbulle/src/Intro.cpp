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
#include "Person2D.h"

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
	sf::Sprite background;

	switch (etape) {
		case 0:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro1.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page1.ogg"));
			break;
		case 1:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro2.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/intro2.ogg"));
			break;
		case 2:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro3.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page3.ogg"));
			break;
		case 3:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro4.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page4.ogg"));
			break;
		case 4:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro5.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page5.ogg"));
			break;
		case 5:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro6.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/page6.ogg"));
			break;
		case 6:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro7.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/ouipage7.ogg"));
			break;
		case 7:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/intro/intro8.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/intro/intro8.ogg"));
			break;
	}



	background.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));
	background.SetPosition(0.f,0.f);

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);


	tabMusic[0]->Lecture();
	if(etape < 3)
	{
		tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/nz/nuit.ogg"));
		tabMusic[1]->Lecture();
	}
	// # Sprite animées
	Person2D garcon_sp(100.f, 200.f, fenetre.GetWidth()/15, 6, 4);	garcon_sp.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/sprite/sprite_g_walk_petit.png")); // la taille du personnage dépend de la fenêtre
	garcon_sp.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/sprite/sprite_g_walk_v04.png")); // la taille du personnage dépend de la fenêtre
	garcon_sp.initClip();
	garcon_sp.SetPosition(-100.f, fenetre.GetHeight()*0.6);

	Person2D barbule_sp(100.f, 200.f, fenetre.GetWidth()/15, 6, 4);
	barbule_sp.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/sprite/sprite_monstre_v01.png"));
	barbule_sp.initClip();
	barbule_sp.SetPosition(fenetre.GetWidth(), garcon_sp.GetPosition().y);

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


		//Dessin
		fenetre.Clear(sf::Color(255, 255, 255));
		fenetre.Draw(background);

		switch (etape) {
		case 0:
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

			// anime barbule et le garcon
			 if( ( garcon_sp.GetPosition().x < 50.f) and not garcon_sp.inMoveTo(Person2D::RIGHT) )
					garcon_sp.walk(Person2D::RIGHT, 450);
			 else if(garcon_sp.inMoveTo(Person2D::RIGHT))
					garcon_sp.walk(Person2D::RIGHT, 450);

			 if( ( barbule_sp.GetPosition().x > fenetre.GetWidth()-300.f) and not barbule_sp.inMoveTo(Person2D::RIGHT) )
					barbule_sp.walk(Person2D::LEFT, 450);
			 else if(barbule_sp.inMoveTo(Person2D::RIGHT))
					barbule_sp.walk(Person2D::LEFT, 450);

			fenetre.Draw(garcon_sp);
			fenetre.Draw(barbule_sp);

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


			garcon_sp.SetX(85);
			fenetre.Draw(garcon_sp);

			barbule_sp.SetX(fenetre.GetWidth()-300.f);
			barbule_sp.SetY(garcon_sp.GetPosition().y+10);
			barbule_sp.setDirection(Person2D::LEFT);
			fenetre.Draw(barbule_sp);

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

		modelePage.dessinerPage(fenetre);
		fenetre.Display();
	}

	// INTERUPTION de toutes les musiques
	for(unsigned int i = 0; i < tabMusic.size(); i++)
		tabMusic[i]->Stop();
	return ecranSuivant;
}
