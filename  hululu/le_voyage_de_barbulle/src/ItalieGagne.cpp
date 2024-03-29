/*
 * ItalieGagne.cpp
 *
 *  Created on: 28 janv. 2010
 *      Author: anthony
 */

#include "ItalieGagne.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Ecran.h"
#include "Musique.h"
#include "Page.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "DefineEcrans.h"
#include "PoleSud_Porte.h"

ItalieGagne::ItalieGagne() {
	// TODO Auto-generated constructor stub

}

ItalieGagne::~ItalieGagne() {
	// TODO Auto-generated destructor stub
}


int ItalieGagne::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = ITALIEGAGNE;
	sf::Clock Clock;
	Clock.Reset();
	Page pays;

	vector<Musique *> tabMusic;
	sf::Vector2f rapportBlason;

	// FONT//////////////////////////////////////////////////////////////////////////
	sf::Event event;

	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Sprite Conservateur;
	Conservateur.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/conservateur_content.png"));
	Conservateur.SetPosition((fenetre.GetWidth()/30), ((fenetre.GetHeight())/30));

	sf::Sprite Barbulle;
	Barbulle.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/barbulle_italie.png"));
	Barbulle.SetPosition((fenetre.GetWidth())/1.4, ((fenetre.GetHeight())/2.5));
	Barbulle.Scale(0.75, 0.75);


	sf::Sprite Explication;
		Explication.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/explication.png"));
		sf::Vector2f vect;
		vect.x=Explication.GetSize().x*Explication.GetSize().x/fenetre.GetWidth();
		vect.y=Explication.GetSize().y*Explication.GetSize().y/fenetre.GetHeight();
		Explication.Resize(vect.x,vect.y);
		Explication.Scale(1.5,1.5);
		Explication.SetPosition((fenetre.GetWidth())/1.8, ((fenetre.GetHeight())/15));
	tabMusic.push_back(new Musique("le_voyage_de_barbulle/music/divers/bravo.ogg"));

	//Objet gagné /////////////////////////////////////////////////////////////////////////////

	PoleSud_Porte::blason.initDessin("le_voyage_de_barbulle/img/objets/blason.png");

	PoleSud_Porte::blason.placerDessin(fenetre.GetWidth()/2-164, (fenetre.GetHeight()/2-160));



	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// instruction
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 80.f))
	cerr << "Erreur lors du chargement de la police";

	//Texte//////////////////////////////////////////////////////////////////////////////////////

	sf::String text(L"Bravo, tu as trouvé l'objet Blason.");
	text.Move((fenetre.GetWidth())/30, ((fenetre.GetHeight())/1.5));
	text.SetColor(sf::Color::Color(120,15,0));
	text.SetSize(80.f);
	text.SetFont(MyFont);

	////////////////////////////////
	tabMusic[0]->Lecture();

			while(fenetre.IsOpened() && (ecranSuivant == ITALIEGAGNE))
			{
				while (fenetre.GetEvent(event)) {
					// # Instanciation de tous les éc fermeture de la fenetre
					// si echap ou fermeture manuelle
					if (event.Type == sf::Event::Closed)
						fenetre.Close();
					else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
						fenetre.Close();
				}



				fenetre.Clear(sf::Color(76,100,255));
				fenetre.Draw(Conservateur);
				fenetre.Draw(Barbulle);
				fenetre.Draw(text);
				fenetre.Draw(Explication);
				PoleSud_Porte::blason.setTrouve(true);
				PoleSud_Porte::blason.dessinerObjet(fenetre);
				pays.dessinerPage(fenetre);
				fenetre.Display();

				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
					ecranSuivant=pays.changerEcran(fenetre,ITALIEGAGNE,MAPPEMONDE,ITALIEGAGNE) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
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
		// 232, 532, 111



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

			// on éteint

			return ecranSuivant;
}
