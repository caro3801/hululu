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
	sf::SoundBuffer buffer;
	buffer.LoadFromFile("le_voyage_de_barbulle/music/nz/splif.ogg");
	sf::Sound splif;
	splif.SetBuffer(buffer);

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
	ombreTexte(txtTitre, txtTitreOMBRE, sf::Color(0,12,35), 2, 2);

	Bouton weta;
	weta.initBouton("le_voyage_de_barbulle/img/nz/yeux_weta.png","le_voyage_de_barbulle/img/nz/yeux_weta.png" );

	// VUE ///////////////////////
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Event event;

	// initialise le timer des wetas
	sf::Clock clockWeta;
	clockWeta.Reset();
	float intervalWeta = sf::Randomizer::Random(2.f, 6.f); // durée entre chaque wéta (change à chaque nouveau wéta)
	int wetaRestant = 10;
	int numWetaTouche = 0;
	int numDerWeta = 1;

	while (fenetre.IsOpened() && (ecranSuivant == NZ_JEU) )
	{
		// EVENEMENTS ///////////////////////
		while (fenetre.GetEvent(event))
		{
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if ( (event.Type == sf::Event::KeyReleased) && (event.Key.Code == sf::Key::Escape) )
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


		if(clockWeta.GetElapsedTime() >= intervalWeta)
		{
			// nouvel interval
			intervalWeta = sf::Randomizer::Random(0.5, 2.f);
			clockWeta.Reset();

			float scale = sf::Randomizer::Random((float)0.5, (float)1.5);
			weta.redimensionner(96,44);
			weta.redimensionner(scale);

			//float angle = sf::Randomizer::Random((float)0, (float)360);
			//weta.rotater(angle);

			float x = sf::Randomizer::Random(20.f, 	fenetre.GetWidth() - weta.GetScale().x - 20);
			float y = sf::Randomizer::Random(20.f, fenetre.GetHeight() - weta.GetScale().y - 20);
			weta.placer(x, y);
			numDerWeta++;
		}


		// DESSINS  //////////////////////////
		fenetre.Clear(sf::Color(0,2,5));
		fenetre.Draw(txtTitreOMBRE);
		fenetre.Draw(txtTitre);
		if(numWetaTouche != numDerWeta)
			weta.drawMe(fenetre);
		modelePage.dessinerPage(fenetre);


		if(weta.estClique(fenetre) && (numWetaTouche != numDerWeta))
		{
			numWetaTouche = numDerWeta;
			splif.Play();
			wetaRestant--;
			cout << wetaRestant << endl;
		}


		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
			ecranSuivant = modelePage.changerEcran(fenetre, NZ_JEU, -1,NZ_PRESENT) ;

		fenetre.Display();
	}

	return ecranSuivant;
}
