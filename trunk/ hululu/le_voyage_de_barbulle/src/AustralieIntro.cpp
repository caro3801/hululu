/*
 * AutralieIntro.cpp
 *
 *  Created on: 24 janv. 2010
 *      Author: pirhoo
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#include "AustralieIntro.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Page.h"
#include "Musique.h"
#include "effetSurTexte.h"

AustralieIntro::AustralieIntro() {
	// TODO Auto-generated constructor stub

}

AustralieIntro::~AustralieIntro() {
	// TODO Auto-generated destructor stub
}

int AustralieIntro::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = AUSTRALIE_INTRO;


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
	// -- drapeaux
	sf::Sprite flag;
	flag.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/flag.png"));
	float position[2];
	position[0] = (fenetre.GetWidth()  / 2) - ( flag.GetSize().x / 2);
	position[1] = (fenetre.GetHeight() / 2) - ( flag.GetSize().y / 2);
	flag.SetPosition(position[0],position[1]);

	// -- sous-titre
	sf::String txtSousTitre("Le pays des kangourous...");
	txtSousTitre.SetSize(40.f);
	txtSousTitre.SetFont(cursiveFont);
	txtSousTitre.SetColor(sf::Color(255,173,0));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre.GetRect().GetWidth() / 2);
	position[1] -= (30 +  txtSousTitre.GetRect().GetHeight() );
	txtSousTitre.SetPosition(position[0],position[1]);

	// -- sous-titre OMBRE
	sf::String txtSousTitreOMBRE;
	ombreTexte(txtSousTitre, txtSousTitreOMBRE, sf::Color(70, 40, 0), 2, 2);

	// -- titre
	sf::String txtTitre("Welcome in Australia !");
	txtTitre.SetSize(50.f);
	txtTitre.SetFont(cursiveFont);
	txtTitre.SetColor(sf::Color(255,173,0));

	position[0] = (fenetre.GetWidth() / 2) - ( txtTitre.GetRect().GetWidth() / 2);
	position[1] -= 60; // sur y, ici il est centré

	txtTitre.SetPosition(position[0],position[1]);

	// -- titre OMBRE
	sf::String txtTitreOMBRE;
	ombreTexte(txtTitre, txtTitreOMBRE, sf::Color(70, 40, 0), 2, 2);

	// IMAGE DE FONT ////////////////////
	sf::Sprite background;
	background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/uluru.jpg"));
	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/australie/austBienv.ogg"));

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	tabMusic[0]->Lecture();

	while (fenetre.IsOpened() && (ecranSuivant == AUSTRALIE_INTRO) )
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
		fenetre.Draw(flag);
		fenetre.Draw(txtTitreOMBRE);
		fenetre.Draw(txtTitre);
		fenetre.Draw(txtSousTitreOMBRE);
		fenetre.Draw(txtSousTitre);
		modelePage.dessinerPage(fenetre);

		fenetre.Display();

		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
			ecranSuivant = modelePage.changerEcran(fenetre, AUSTRALIE_INTRO, AUSTRALIE_PRESENT, MAPPEMONDE) ;

	}
	// INTERUPTION de toutes les musiques
	for(unsigned int i = 0; i < tabMusic.size(); i++)
		tabMusic[i]->Stop();

	// on éteint

	return ecranSuivant;
}
