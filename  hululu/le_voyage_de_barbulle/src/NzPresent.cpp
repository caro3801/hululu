/*
 * NzPresent.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */
// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "NzPresent.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Page.h"
#include "Musique.h"
#include "effetSurTexte.h"

#include <iostream>
using namespace std;

NzPresent::NzPresent() {
	_etape = 0;
}

NzPresent::~NzPresent() {
	// TODO Auto-generated destructor stub
}


int NzPresent::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = NZ_PRESENT;


	// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	Page modelePage;


	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();



	vector<Musique *> tabMusic;

	// ELEMENTS /////////////////////////

	// -- titre
	sf::String txtTitre(L"Nouvelle-Zélande");
	txtTitre.SetSize(40.f);
	txtTitre.SetFont(cursiveFont);
	txtTitre.SetColor(sf::Color::White);

	int position[2];
	position[0] = 180;
	position[1] = 15; // sur y, ici il est centré
	txtTitre.SetPosition(position[0],position[1]);

	// -- titre OMBRE
	sf::String txtTitreOMBRE;
	ombreTexte(txtTitre, txtTitreOMBRE, sf::Color::Black, 2, 2);

	// IMAGE DE FONT ////////////////////
	sf::Sprite background;
	switch (_etape) {
		case 0:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/nz/presentation1.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/nz/nz1.ogg"));
			break;

		case 1:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/nz/presentation2.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/nz/nz2.ogg"));
			break;

		case 2:
			background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/nz/presentation3.png"));
			tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/nz/nz3.ogg"));
			break;
	}

	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);


	tabMusic[0]->Lecture();

	signed int etapeInitiale = _etape;

	while (fenetre.IsOpened() && (ecranSuivant == NZ_PRESENT) && (etapeInitiale == _etape) )
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
		if(tabMusic[0]->GetStatus() == sf::Music::Stopped && (_etape < 2) )
				_etape++;

		switch(_etape) {
			case 0:
				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
					if (modelePage.getGoClique(fenetre)) {
						modelePage.getGo().resetTimer();
						_etape++;
						ecranSuivant = NZ_PRESENT;
					} else if (modelePage.getBackClique(fenetre)) {
						modelePage.getBack().resetTimer();
						ecranSuivant = NZ_INTRO;
					} else
						ecranSuivant = MAPPEMONDE;
				}
				break;


			case 1:
				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
					if (modelePage.getGoClique(fenetre)) {
						modelePage.getGo().resetTimer();
						_etape++;
						ecranSuivant = NZ_PRESENT;
					} else if (modelePage.getBackClique(fenetre)) {
						modelePage.getBack().resetTimer();
						_etape--;
						ecranSuivant = NZ_PRESENT;
					} else
						ecranSuivant = MAPPEMONDE;
				}
				break;

			case 2:
				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
					if (modelePage.getGoClique(fenetre)) {
						modelePage.getGo().resetTimer();
						_etape=0;
						ecranSuivant = NZ_JEU;
					} else if (modelePage.getBackClique(fenetre)) {
						modelePage.getBack().resetTimer();
						_etape--;
						ecranSuivant = NZ_PRESENT;
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
		} else {
			 if(tabMusic[0]->GetStatus() == sf::Music::Playing) {
				tabMusic[0]->Pause();
			 }
		}
// 232, 532, 111



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
		fenetre.Draw(txtTitreOMBRE);
		fenetre.Draw(txtTitre);
		modelePage.dessinerPage(fenetre);

		fenetre.Display();
	}

	// INTERUPTION de toutes les musiques
	for(unsigned int i = 0; i < tabMusic.size(); i++)
		tabMusic[i]->Stop();

	// on éteint

	return ecranSuivant;
}
