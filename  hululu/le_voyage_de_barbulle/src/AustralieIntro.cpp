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


#include "AustralieIntro.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Person2D.h"
#include "Mapmonde.h"
#include "JeuPerou.h"
#include "Page.h"

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

	Page page;
	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();

	// ELEMENTS /////////////////////////
	sf::String txtTitre("Welcome in Australia !");
	txtTitre.SetSize(50.f);
	txtTitre.SetFont(cursiveFont);
	txtTitre.SetColor(sf::Color(255,173,0));

	int position[2]; // position du bouton en fonction de la taille de la fenêtre
	position[0] = (fenetre.GetWidth() / 2) - ( txtTitre.GetRect().GetWidth() / 2);
	position[1] = (int)(fenetre.GetHeight()*0.1); // sur y, ici il est centré

	txtTitre.SetPosition(position[0],position[1]);

	// IMAGE DE FONT ////////////////////
	sf::Sprite backgroundKangoo;
	backgroundKangoo.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/kangou.jpg"));
	backgroundKangoo.SetPosition(0.f, 0.f);
	backgroundKangoo.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	while (fenetre.IsOpened())
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


		// DESSINS  //////////////////////////
		fenetre.Draw(backgroundKangoo);
		fenetre.Draw(txtTitre);
		page.dessinerPage(fenetre);

		fenetre.Display();

	}

	return ecranSuivant;
}
