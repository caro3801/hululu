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
#include "PoleSud_Porte.h"

#include <iostream>
#include <sstream>
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
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/nz/nzMaori.ogg"));
	tabMusic[0]->Lecture();

	sf::SoundBuffer buffer;
	buffer.LoadFromFile("le_voyage_de_barbulle/music/nz/splif.ogg");
	sf::Sound splif;
	splif.SetBuffer(buffer);

	// ELEMENTS /////////////////////////

	sf::Sprite background;
	background.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/nz/gardeManger.png"));
	background.SetPosition(0.f, 0.f);
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	// -- titre
	sf::String txtTitre("La chasse aux wetas!");
	txtTitre.SetSize(40.f);
	txtTitre.SetFont(cursiveFont);
	txtTitre.SetColor(sf::Color(189,7,11));

	int position[2];
	position[0] = 180;
	position[1] = 15; // sur y, ici il est centré
	txtTitre.SetPosition(position[0],position[1]);

	// -- titre OMBRE
	sf::String txtTitreOMBRE;
	ombreTexte(txtTitre, txtTitreOMBRE, sf::Color(94,4,5), 2, 2);

	// -- vieux Maori
	sf::Sprite maori(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/nz/maori.png"));
	float rapport = fenetre.GetWidth() / fenetre.GetHeight();
	maori.Resize(fenetre.GetWidth()*0.2, fenetre.GetWidth()*0.2*rapport);
	maori.SetPosition(fenetre.GetWidth()-maori.GetSize().x, fenetre.GetHeight()-maori.GetSize().y );

	// -- bulle du vieu maori
	sf::Sprite bulle(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/nz/bulle.png"));
	bulle.SetPosition(maori.GetPosition().x, maori.GetPosition().y + 40 );

	// -- compteur visuel
	sf::String txtCompteur("Il te reste 10 wetas a attraper !");
	txtCompteur.SetFont(cursiveFont);
	txtCompteur.SetColor(sf::Color(189,7,11));
	txtCompteur.SetPosition(maori.GetPosition().x -  txtCompteur.GetRect().GetWidth(), maori.GetPosition().y);

	// -- compteur OMBRE
	sf::String txtCompteurOMBRE;
	ombreTexte(txtCompteur, txtCompteurOMBRE, sf::Color(94,4,5), 2, 2);

	Bouton weta;
	weta.initBouton("le_voyage_de_barbulle/img/nz/yeux_weta.png","le_voyage_de_barbulle/img/nz/yeux_weta.png" );
	weta.placer(-100, -100);

	// -- Weta GEANT !!!
	sf::Sprite wetaGeant(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/objets/weta.png"));
	wetaGeant.SetPosition(fenetre.GetWidth()/2 - wetaGeant.GetSize().x/2, fenetre.GetHeight()- wetaGeant.GetSize().y/2);

	// VUE ///////////////////////
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Event event;

	// initialise le timer des wetas
	sf::Clock clockWeta;
	clockWeta.Reset();

	float intervalWeta = tabMusic[0]->GetDuration() + 0.5; // durée entre chaque wéta (change à chaque nouveau wéta)
	int wetaRestant = 10;
	int numWetaTouche = 0;
	int numDerWeta = 1;

	int continuer = NZ_JEU;

	while (fenetre.IsOpened() && (ecranSuivant == NZ_JEU) )
	{


		if(weta.estClique(fenetre) && (numWetaTouche != numDerWeta)  && (wetaRestant > 0))
		{
			numWetaTouche = numDerWeta;
			splif.Play();
			wetaRestant--;


			ostringstream imageInt;
			imageInt << wetaRestant;

			if(wetaRestant > 1)
				txtCompteur.SetText("Il te reste "+imageInt.str()+" wetas a attraper !");
			else
				txtCompteur.SetText("Il te reste "+imageInt.str()+" weta a attraper !");

			txtCompteur.SetPosition(maori.GetPosition().x -  txtCompteur.GetRect().GetWidth(), maori.GetPosition().y);
			ombreTexte(txtCompteur, txtCompteurOMBRE, sf::Color(94,4,5), 2, 2);
		}

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
		{
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(0);
			splif.SetVolume(0);
		}
		else if (tabMusic.size() > 0)
		{
			for(unsigned int i = 0; i < tabMusic.size(); i++)
				tabMusic[i]->SetVolume(100);
			splif.SetVolume(100);
		}


		if(clockWeta.GetElapsedTime() >= intervalWeta)
		{
			// nouvel interval
			intervalWeta = sf::Randomizer::Random(0.5, 2.f);
			clockWeta.Reset();

			float scale = sf::Randomizer::Random((float)0.5, (float)1.5);
			weta.redimensionner(96,44);
			weta.redimensionner(scale);

			float x = sf::Randomizer::Random(0.f, 	fenetre.GetWidth() - weta.GetScale().x);
			float y = sf::Randomizer::Random(40.f, fenetre.GetHeight() - maori.GetSize().y);
			weta.placer(x, y);
			numDerWeta++;
		}


		// DESSINS  //////////////////////////
		fenetre.Clear(sf::Color::Black);
		fenetre.Draw(background);
		fenetre.Draw(txtTitreOMBRE);
		fenetre.Draw(txtTitre);

		fenetre.Draw(txtCompteurOMBRE);
		fenetre.Draw(txtCompteur);
		fenetre.Draw(bulle);

		fenetre.Draw(maori);

		// GAGNEEEEE ////////////////////////
		if(wetaRestant == 0)
		{
			txtCompteur.SetText(L"Ah ! Me voila débarrassé de ces wetas pour un moment !\nPour te remercier, voici une statuette du Weta Géant !");
			txtCompteur.SetPosition(maori.GetPosition().x -  txtCompteur.GetRect().GetWidth(), maori.GetPosition().y);
			ombreTexte(txtCompteur, txtCompteurOMBRE, sf::Color(94,4,5), 2, 2);
			continuer=MAPPEMONDE;
			PoleSud_Porte::weta.setTrouve(true);
			fenetre.Draw(wetaGeant);
		}


		if( (numWetaTouche != numDerWeta) && (wetaRestant > 0) )
			weta.drawMe(fenetre);
		modelePage.dessinerPage(fenetre);


		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
			ecranSuivant = modelePage.changerEcran(fenetre, NZ_JEU, continuer, NZ_PRESENT) ;

		fenetre.Display();
	}

	return ecranSuivant;
}
