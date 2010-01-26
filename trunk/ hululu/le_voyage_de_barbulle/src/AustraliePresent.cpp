/*
 * AustraliePresent.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: pirhoo
 */
// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "AustraliePresent.h"
#include "DefineEcrans.h"

#include "Bouton.h"
#include "Page.h"

#include "effetSurTexte.h"

#include <iostream>
using namespace std;

AustraliePresent::AustraliePresent() {
	// TODO Auto-generated constructor stub

}

AustraliePresent::~AustraliePresent() {
	// TODO Auto-generated destructor stub
}


int AustraliePresent::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = AUSTRALIE_PRESENT;


	// DEF de la police ////////////////
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	Page modelePage;


	// HORLOGE //////////////////////////
	sf::Clock Clock;
	Clock.Reset();

	// ELEMENTS /////////////////////////

	// -- titre
	sf::String txtTitre("Australie");
	txtTitre.SetSize(40.f);
	txtTitre.SetFont(cursiveFont);
	txtTitre.SetColor(sf::Color(255,173,0));

	int position[2];
	position[0] = 80;
	position[1] = 15; // sur y, ici il est centré
	txtTitre.SetPosition(position[0],position[1]);

	// -- titre OMBRE
	sf::String txtTitreOMBRE;
	ombreTexte(txtTitre, txtTitreOMBRE, sf::Color(70, 40, 0), 2, 2);

	// -- cadre présentation
	sf::Sprite presentation;
	presentation.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/presentation.png"));
	position[0] -= 60;
	position[1] += txtTitre.GetRect().GetHeight() + 10;
	presentation.SetPosition(position[0],position[1]);
	float indice = presentation.GetSize().y / presentation.GetSize().x;
	presentation.Resize(fenetre.GetWidth()*0.40, fenetre.GetWidth()*0.40*indice);

	// IMAGE DE FONT ////////////////////
	sf::Sprite backgroundKangoo;
	backgroundKangoo.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/kangou.jpg"));
	backgroundKangoo.SetPosition(0.f, 0.f);
	backgroundKangoo.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	while (fenetre.IsOpened() && (ecranSuivant == AUSTRALIE_PRESENT) )
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
		fenetre.Draw(txtTitreOMBRE);
		fenetre.Draw(txtTitre);
		fenetre.Draw(presentation);
		modelePage.dessinerPage(fenetre);

		fenetre.Display();

		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			ecranSuivant = modelePage.changerEcran(fenetre, AUSTRALIE_PRESENT, AUSTRALIE_PRESENT, AUSTRALIE_INTRO) ;

	}

	return ecranSuivant;
}
