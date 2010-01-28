/*
 * GagneJeu.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pollet
 */

#include "GagneJeu.h"

// WIKI SFML //////////////////////////
#include "Bouton.h"
#include "AccueilPays.h"
#include "Page.h"
#include "PoleSud_Porte.h"
#include "DefineEcrans.h"
#include "Musique.h"

GagneJeu::GagneJeu() {
	etape = 0;

}

GagneJeu::~GagneJeu() {
	// TODO Auto-generated destructor stub
}

int GagneJeu::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = GAGNE_JEU;
	sf::Clock Clock;
	Clock.Reset();

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Font cursiveFont;
		if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50.f))
					cerr << "Erreur lors du chargement de la police" << endl;

	sf::String text("Bravo, tu as ajoute tous les objets ! \n Je vais pouvoir rentrer chez moi ! \n Merci !");
	text.Move(fenetre.GetWidth()/10,fenetre.GetHeight()/1.8);
	text.SetColor(sf::Color::Blue);
	text.SetSize(22.f);
	text.SetFont(cursiveFont);
	sf::Event event;

	sf::Sprite monstre(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/monstre_gagne.png"));
		monstre.SetPosition(fenetre.GetWidth()/3,fenetre.GetHeight()/2);

	vector<Musique *> tabMusic;

	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/conclusion/ccl1.ogg"));
	tabMusic[0]->ChargerFichier();
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/conclusion/ccl2.ogg"));
	tabMusic[1]->ChargerFichier();
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/conclusion/ccl3.ogg"));
	tabMusic[2]->ChargerFichier();


	// # création d'une vue sur la fenêtre - !! Puisqu'une vue a été créee sur l'ecran précédent (Mapemonde) obligé de recréer une vue
	//pour toutes les fenetres suivantes, ou images et sprites ne s'affichent pas!
	//a voir pour trouver une autre solution : suppression vue ? re-definition de la vue par defaut ?
	//ou on crée une autre vue a chaque fois.


	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);
	////////////////////////////////
	tabMusic[0]->Lecture();

	unsigned int etapeInitiale = etape;

	while(fenetre.IsOpened()&& (ecranSuivant == GAGNE_JEU) )
	{
				while (fenetre.GetEvent(event)) {
						// # Instanciation de tous les éc fermeture de la fenetre
						// si echap ou fermeture manuelle
						if (event.Type == sf::Event::Closed)
						fenetre.Close();
					else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
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

		// Musique //////////////////////////
		if (Clock.GetElapsedTime() < tabMusic[0]->GetDuration() )
			etape = 0;
		else if (Clock.GetElapsedTime() < (tabMusic[0]->GetDuration() + tabMusic[1]->GetDuration()) )
			etape = 1;
		else
			etape = 2;

		if (Clock.GetElapsedTime() < (tabMusic[0]->GetDuration() + tabMusic[1]->GetDuration() + tabMusic[2]->GetDuration()) )
			if( tabMusic[etape]->GetStatus() == sf::Music::Stopped)
				tabMusic[etape]->Lecture();

		///////////Dessin
		fenetre.Clear(sf::Color(255, 255, 255));
		fenetre.Draw(text);
		fenetre.Draw(monstre);
		pays.dessinerPage(fenetre);
		fenetre.Display();


	}
	// INTERUPTION de toutes les musiques
		for(unsigned int i = 0; i < tabMusic.size(); i++)
			tabMusic[i]->Stop();

		// on éteint
	return ecranSuivant;

}
