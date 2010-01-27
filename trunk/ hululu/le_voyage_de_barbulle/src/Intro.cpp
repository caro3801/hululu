/*
 * Intro.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: talotte
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Intro.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Page.h"

#include "effetSurTexte.h"

Intro::Intro() {
	this->etape = 0;

}

Intro::~Intro() {
	// TODO Auto-generated destructor stub
}

int Intro::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = INTRO_G;
	Page modelePage;


	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();

	// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	// ELEMENTS /////////////////////////

	// -- fond
	sf::Sprite accueil;
	accueil.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/accueil/fondaccueil.png"));
	accueil.SetPosition(0.f, 0.f);
	accueil.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// -- sous-titre
	//ecran1
	sf::String txtSousTitre1("Il etait une fois...");
	txtSousTitre1.SetSize(40.f);
	txtSousTitre1.SetFont(cursiveFont);
	txtSousTitre1.SetColor(sf::Color(48,84,163));
	int position[2];
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre1.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre1.GetRect().GetHeight() );
	txtSousTitre1.SetPosition(position[0],position[1]);

	//ecran2
	sf::String txtSousTitre2("ce soir là");
	txtSousTitre2.SetSize(40.f);
	txtSousTitre2.SetFont(cursiveFont);
	txtSousTitre2.SetColor(sf::Color(255,173,0));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre2.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre2.GetRect().GetHeight() );
	txtSousTitre2.SetPosition(position[0],position[1]);

	//ecran3
	sf::String txtSousTitre3("soudain");
	txtSousTitre2.SetSize(40.f);
	txtSousTitre2.SetFont(cursiveFont);
	txtSousTitre2.SetColor(sf::Color(255,173,0));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre3.GetRect().GetWidth() / 2);
	position[1] = (10 +  txtSousTitre3.GetRect().GetHeight() );
	txtSousTitre3.SetPosition(position[0],position[1]);



	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	// # Pour que le programme ne se termine pas :)
	sf::Event event;
	int etapeInitiale = etape;

	while (fenetre.IsOpened() && (ecranSuivant == INTRO_G) && (etapeInitiale == etape) )
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

		switch (etape) {
		case 0:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre1);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					ecranSuivant = PEROU;

				} else
					ecranSuivant = MAPPEMONDE;
			}
			break;

		case 1:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre2);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape++;
					ecranSuivant = INTRO_G;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}

			break;
		case 2:
			fenetre.Draw(accueil);
			fenetre.Draw(txtSousTitre3);
			modelePage.dessinerPage(fenetre);
			fenetre.Display();
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre)) {
				if (modelePage.getGoClique(fenetre)) {
					modelePage.getGo().resetTimer();
					etape = 0;
					ecranSuivant = MAPPEMONDE;
				} else if (modelePage.getBackClique(fenetre)) {
					modelePage.getBack().resetTimer();
					etape--;
					ecranSuivant = INTRO_G;
				} else
					ecranSuivant = MAPPEMONDE;
			}
			break;
		}


		// CTRL changement d'écran ////////////
	//	if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre))
	//		ecranSuivant = modelePage.changerEcran(fenetre, INTRO_G, INTRO_G, MAPPEMONDE) ;

	}

	return ecranSuivant;
}
