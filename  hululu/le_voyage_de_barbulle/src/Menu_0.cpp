/*
 * menu_0.cpp
 *
 *  Created on: 10 déc. 2009
 *      Author: pirhoo
 * Description: AFFICHE LE MENU PRINCIPAL
 */


#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// LIB PERSOS///////////////////////////
#include "Menu_0.h"
#include "Bouton.h"
#include "Person2D.h"
#include "DefineEcrans.h"

int Menu_0::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = MENU_0;
	sf::Clock Clock;


	// DEF du bouton "nouvelle partie" ////////////

	Bouton boutNouvPartie;
	boutNouvPartie.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png","le_voyage_de_barbulle/img/histoire/bouton_f.png" );
	boutNouvPartie.redimensionner(0.5);

	int boutonPosition[2]; // position du bouton en fonction de la taille de la fenêtre
	boutonPosition[0] = (fenetre.GetWidth() / 2) - (boutNouvPartie.getTailleX() / 2);  // sur x, ici il est centré
	boutonPosition[1] = (int)(fenetre.GetHeight() / 2) - (boutNouvPartie.getTailleY() / 2); // sur y, ici il est centré

	boutNouvPartie.placer(boutonPosition[0],boutonPosition[1]);

	// texte du bouton
	sf::String txtNouvPartie("Nouvelle Partie");
	txtNouvPartie.SetColor(sf::Color::Black);
	txtNouvPartie.SetSize(25.f);
	boutNouvPartie.placerTexte(txtNouvPartie);


	// DEF du bouton "continuer" ////////////

	Bouton boutContinuer;
	boutContinuer.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png","le_voyage_de_barbulle/img/histoire/bouton_f.png" );
	boutContinuer.redimensionner(0.5);

	// Seule la position vertical change pour ce bouton, on réutilise les variables précédentes
	// la hauteur d'un demi bouton entre chaque bouton
	// on poura eventuellement changer plus tard pour coller au font
	boutonPosition[1] += boutContinuer.getTailleY();

	boutContinuer.placer(boutonPosition[0],boutonPosition[1]);

	// texte du bouton
	sf::String txtContinuer("Continuer");
	txtContinuer.SetColor(sf::Color::Black);
	txtContinuer.SetSize(25.f);
	boutContinuer.placerTexte(txtContinuer);


	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	//Programme en lui-meme
	while(fenetre.IsOpened())
	{
		// EVENEMENTS //////////////////////////////////////////
		while (fenetre.GetEvent(event)) {
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
				fenetre.Close();
		}

		// init du font de la fenêtre
		fenetre.Clear(sf::Color(255, 255, 255));

		// DESSIN DES BOUTONS //////////////////////////////////////
		// -- nouvelle partie
		boutNouvPartie.drawMe(fenetre);
		fenetre.Draw(txtNouvPartie);
		// -- continuer
		boutContinuer.drawMe(fenetre);
		fenetre.Draw(txtContinuer);

		// CLIQUE SUR nouvelle partie ///////////////////////////////
		if(boutNouvPartie.estClique(fenetre)) {
			Clock.Reset();
			while(Clock.GetElapsedTime()<1) {
				fenetre.Clear(sf::Color(255, 255, 255));
				boutNouvPartie.drawMe(fenetre);
				fenetre.Draw(txtNouvPartie);
				fenetre.Display();
			}
			return (ecranSuivant = MAPPEMONDE);
		}
		fenetre.Display();

	}
	return ecranSuivant;
}
