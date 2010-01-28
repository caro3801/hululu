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

	sf::Clock clock, clockSuivant;
	clock.Reset(); clockSuivant.Reset();

	// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;


	// -- texte
	sf::String txt(L"Embarque vite sur le bateau pour \ndécouvrir un nouveau pays:\nLa Nouvelle-Zélande !");
	txt.SetSize(50.f);
	txt.SetFont(cursiveFont);
	txt.SetColor(sf::Color(73, 5,92, 255));
	txt.SetPosition(100, 200);

	// -- texte OMBRE
	sf::String txtOmbre;
	ombreTexte(txt, txtOmbre, sf::Color(51, 0, 51), 1, 1);

	// LISTE musique ////////////////////
	vector<Musique *> tabMusic;
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/australie/austBoat.ogg"));

	// IMAGE DE FONT ////////////////////
	sf::Sprite background;
	background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/bgBateau.png"));
	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	// BATEAU ////////////////////
	sf::Sprite bateau;
	bateau.SetColor(sf::Color(255,255,255,255));
	bateau.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/bateau_translate.png"));
	bateau.SetPosition(0, fenetre.GetHeight()-bateau.GetSize().y);

	// VUE ///////////////////////
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Event event;
	int alpha = 255;

	tabMusic[0]->Lecture();

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


		if(clockSuivant.GetElapsedTime() > 10)
			ecranSuivant = NZ_INTRO;


		 if( (bateau.GetPosition().x < fenetre.GetWidth() )
		 &&  (bateau.GetPosition().y > 0)
		 && (clock.GetElapsedTime()*1000 > 80) ){
			 bateau.SetPosition(bateau.GetPosition().x + 7, bateau.GetPosition().y - 4);
			 bateau.Scale(0.99, 0.99);
			 if(alpha>=2)
			 {
				 alpha -= 2;
				 bateau.SetColor(sf::Color(255,255,255,alpha));
			 }

			 clock.Reset();
		 }



		// PAUSE/PLAY instruction ///////////
		if(!modelePage.getPlaying() && ( tabMusic.size() > 0 ) ) {
			if(tabMusic[0]->GetStatus() == sf::Music::Paused) {
				tabMusic[0]->Lecture();
			}
		} else if (tabMusic.size() > 0) {
			 if(tabMusic[0]->GetStatus() == sf::Music::Playing) {
				tabMusic[0]->Pause();
			 }
		}

		// REPETER instruction ///////////////
		if(modelePage.getRepeterClique(fenetre)  && (tabMusic.size() > 0) ) {
				tabMusic[0]->Stop();
				tabMusic[0]->Lecture();
		}

		// MUTE instruction //////////////////
		if(!modelePage.getMuting() )
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(0);
		else if (tabMusic.size() > 0)
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(100);


		// DESSINS  //////////////////////////
		fenetre.Draw(background);
		fenetre.Draw(bateau);
		fenetre.Draw(txtOmbre);
		fenetre.Draw(txt);
		modelePage.dessinerPage(fenetre);

		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
			ecranSuivant = modelePage.changerEcran(fenetre, TRAJET_ANZ, NZ_INTRO, AUSTRALIE_PRESENT) ;

		fenetre.Display();
	}
	// INTERUPTION de toutes les musiques
	for(unsigned int i = 0; i < tabMusic.size(); i++)
		tabMusic[i]->Stop();

	// on éteint
	return ecranSuivant;
}
