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

void ombreTexte(sf::String &src, sf::String &dest, sf::Color couleur = sf::Color::Black, int xStep = 1, int yStep =1)
{
	dest.SetText(src.GetText());
	dest.SetSize(src.GetSize());
	dest.SetFont(src.GetFont());
	dest.SetColor(couleur);
	dest.SetPosition(src.GetPosition().x+xStep,src.GetPosition().y+xStep);
}

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

	// ELEMENTS /////////////////////////

	// -- drapeaux
	sf::Sprite flag;
	flag.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/flag.png"));
	int position[2]; // position de l'élément en fonction de la taille de la fenêtre
	position[0] = (fenetre.GetWidth() / 2) - ( flag.GetSize().x / 2);
	position[1] = (fenetre.GetHeight() / 2) - ( flag.GetSize().y / 2);
	flag.SetPosition(position[0],position[1]);

	// -- sous-titre
	sf::String txtSousTitre("Le pays des kangouroux...");
	txtSousTitre.SetSize(40.f);
	txtSousTitre.SetFont(cursiveFont);
	txtSousTitre.SetColor(sf::Color(255,173,0));
	position[0] = (fenetre.GetWidth() / 2) - ( txtSousTitre.GetRect().GetWidth() / 2);
	position[1] -= (10 +  txtSousTitre.GetRect().GetHeight() );
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
	sf::Sprite backgroundKangoo;
	backgroundKangoo.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/australie/kangou.jpg"));
	backgroundKangoo.SetPosition(0.f, 0.f);
	backgroundKangoo.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

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


		// DESSINS  //////////////////////////
		fenetre.Draw(backgroundKangoo);
		fenetre.Draw(txtTitreOMBRE);
		fenetre.Draw(txtTitre);
		fenetre.Draw(txtSousTitreOMBRE);
		fenetre.Draw(txtSousTitre);
		fenetre.Draw(flag);
		modelePage.dessinerPage(fenetre);

		fenetre.Display();

		// CTRL changement d'écran ////////////
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && modelePage.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			ecranSuivant = modelePage.changerEcran(fenetre, AUSTRALIE_INTRO, AUSTRALIE_INTRO, MAPPEMONDE) ;

	}

	return ecranSuivant;
}
