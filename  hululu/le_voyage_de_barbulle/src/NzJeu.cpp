/*
 * NzJeu.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */
// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "NzJeu.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Page.h"
#include "Musique.h"
#include "effetSurTexte.h"

#include <iostream>
using namespace std;

NzJeu::NzJeu() {
	// TODO Auto-generated constructor stub

}

NzJeu::~NzJeu() {
	// TODO Auto-generated destructor stub
}

int NzJeu::run(sf::RenderWindow &fenetre) {
	int ecranSuivant = NZ_JEU;
	Page modelePage;

		// DEF de la police ////////////////
		sf::Font cursiveFont;
		if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
			cerr << "Erreur lors du chargement de la police" << endl;

		// LISTE musique ////////////////////
		vector<Musique *> tabMusic;
		tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/nz/splif.ogg"));


		// ELEMENTS /////////////////////////

		// -- titre
		sf::String txtTitre("La chasse aux wetas!");
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
			fenetre.Clear(sf::Color(0,10,35));
			fenetre.Draw(txtTitreOMBRE);
			fenetre.Draw(txtTitre);
			modelePage.dessinerPage(fenetre);


			// CTRL changement d'écran ////////////
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
				ecranSuivant = modelePage.changerEcran(fenetre, NZ_JEU, -1,NZ_PRESENT) ;

			fenetre.Display();
		}

		return ecranSuivant;
}
