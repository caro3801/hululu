/*
 * PerouGagne.cpp
 *
 *  Created on: 28 janv. 2010
 *      Author: pollet
 */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Ecran.h"

#include "PerouGagne.h"
#include "Page.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "DefineEcrans.h"
#include "PoleSud_Porte.h"
#include "Musique.h"

PerouGagne::PerouGagne() {
	// TODO Auto-generated constructor stub

}

PerouGagne::~PerouGagne() {
	// TODO Auto-generated destructor stub
}

int PerouGagne::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = PEROUGAGNE;
	sf::Clock Clock;
	Clock.Reset();
	Page pays;

	vector<Musique *> tabMusic;
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/divers/bravo.ogg"));

	// FONT//////////////////////////////////////////////////////////////////////////
	sf::Event event;

	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Sprite Lama;
	Lama.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/lama2.png"));
	Lama.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/2));
//	Sakura.Resize(400, 400);

	sf::Sprite Barbulle;
	Barbulle.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/monstre_perou.png"));
	Barbulle.SetPosition((fenetre.GetWidth())/6.5, ((fenetre.GetHeight())/8));
	Barbulle.Scale(0.75, 0.75);

	//Objet gagné /////////////////////////////////////////////////////////////////////////////

	PoleSud_Porte::poncho.initDessin("le_voyage_de_barbulle/img/objets/poncho.png");
	PoleSud_Porte::poncho.placerDessin((fenetre.GetWidth())*13/20, ((fenetre.GetHeight()*1/100)));



	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// instruction
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 80.f))
	cerr << "Erreur lors du chargement de la police";

	//Texte//////////////////////////////////////////////////////////////////////////////////////
	sf::String text(L"Bravo, tu as trouvé un Objet.");
	text.Move((fenetre.GetWidth())/30, ((fenetre.GetHeight())/1.9));
	text.SetColor(sf::Color::Color(120,15,0));
	text.SetSize(80.f);
	text.SetFont(MyFont);

	////////////////////////////////
		tabMusic[0]->Lecture();
			while(fenetre.IsOpened() && (ecranSuivant == PEROUGAGNE))
			{
				while (fenetre.GetEvent(event)) {
					// # Instanciation de tous les éc fermeture de la fenetre
					// si echap ou fermeture manuelle
					if (event.Type == sf::Event::Closed)
						fenetre.Close();
					else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
						fenetre.Close();
				}



				fenetre.Clear(sf::Color(255, 200, 122));

				fenetre.Draw(Lama);
				fenetre.Draw(Barbulle);
				fenetre.Draw(text);
				pays.dessinerPage(fenetre);
				PoleSud_Porte::poncho.setTrouve(true);
				PoleSud_Porte::poncho.dessinerObjet(fenetre);
				fenetre.Display();

				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
					ecranSuivant=pays.changerEcran(fenetre,PEROUGAGNE,MAPPEMONDE,PEROUGAGNE) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
																		   //ecranPrecedent = Mapmonde (1)

				if (fenetre.GetInput().IsKeyDown(sf::Key::O))
					ecranSuivant=MAPPEMONDE;
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

			}
		// INTERUPTION de toutes les musiques
		for(unsigned int i = 0; i < tabMusic.size(); i++)
			tabMusic[i]->Stop();


	return ecranSuivant;
}
