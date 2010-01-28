/*
 * PerouPresent.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pollet
 */

#include "PerouPresent.h"

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "HistoireJapon.h"
#include "Person2D.h"
#include "Mapmonde.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "Page.h"
#include "DefineEcrans.h"
#include "Page.h"
#include "Musique.h"
#include "effetSurTexte.h"



PerouPresent::PerouPresent() {
	// TODO Auto-generated constructor stub
	_etape = 0;
}

PerouPresent::~PerouPresent() {
	// TODO Auto-generated destructor stub
}

int PerouPresent::run(sf::RenderWindow &fenetre){

	//Déclaration
	int ecranSuivant = PEROUPRESENT;
	sf::Clock Clock;
	Clock.Reset();
	Page pays;

	vector<Musique *> tabMusic;

	// DEF de la police ////////////////
		sf::Font cursiveFont;
		if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
			cerr << "Erreur lors du chargement de la police" << endl;

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # titre
		sf::String txtTitre(L"Pérou");
		txtTitre.SetSize(40.f);
		txtTitre.SetFont(cursiveFont);
		txtTitre.SetColor(sf::Color(40,90,80));
		txtTitre.SetPosition(fenetre.GetWidth()/7,0);

    // # titre OMBRE
		sf::String txtTitreOMBRE;
		ombreTexte(txtTitre, txtTitreOMBRE, sf::Color(70, 40, 0), 2, 2);

		// IMAGE DE FONT ////////////////////

			sf::Sprite background;
			switch (_etape) {
				case 0:
					background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/presPerou1.png"));
					tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/perou/per2.ogg"));
					break;

				case 1:
					background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/presPerou2.png"));
					tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/perou/per3.ogg"));
					break;
			}

			background.SetPosition(0.f, 0.f);
			background.Resize(fenetre.GetWidth(), fenetre.GetHeight());


			sf::Event event;

			// # création d'une vue sur la fenêtre
			sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
			fenetre.SetView(vue);

			///AFFICHAGE FENETRE////////////////////////////////

				tabMusic[0]->Lecture();

				unsigned int etapeInitiale = _etape;

					while(fenetre.IsOpened()&&(ecranSuivant == PEROUPRESENT) && (etapeInitiale == _etape))
						{
							while (fenetre.GetEvent(event)) {
									    // # Instanciation de tous les écrans fermeture de la fenetre
										// si echap ou fermeture manuelle
										if (event.Type == sf::Event::Closed)
											fenetre.Close();
										else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
											fenetre.Close();

									}
							// on surveille l'avancement de la lecture
									if(tabMusic[0]->GetStatus() == sf::Music::Stopped && (_etape < 1) )
											_etape++;

									switch(_etape) {
										case 0:
											if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre)) {
												if (pays.getGoClique(fenetre)) {
													pays.getGo().resetTimer();
													_etape++;
													ecranSuivant = PEROUPRESENT;
												} else if (pays.getBackClique(fenetre)) {
													pays.getBack().resetTimer();
													ecranSuivant = PEROU;
												} else
													ecranSuivant = MAPPEMONDE;
											}
											break;


										case 1:
											if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre)) {
												if (pays.getGoClique(fenetre)) {
													pays.getGo().resetTimer();
													_etape=0;
													ecranSuivant = JEU_PEROU;
												} else if (pays.getBackClique(fenetre)) {
													pays.getBack().resetTimer();
													_etape--;
													ecranSuivant = PEROUPRESENT;
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




							fenetre.Clear(sf::Color(255, 255, 255));
							fenetre.Draw(background);
							fenetre.Draw(txtTitreOMBRE);
							fenetre.Draw(txtTitre);
							pays.dessinerPage(fenetre);
							fenetre.Display();


						}
					// INTERUPTION de toutes les musiques
					for(unsigned int i = 0; i < tabMusic.size(); i++)
								tabMusic[i]->Stop();

	return ecranSuivant;
}
