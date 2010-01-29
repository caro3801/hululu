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
#include "PoleSud_Porte.h"
#include "Musique.h"

int Menu_0::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = MENU_0;
	sf::Clock Clock;

	// DEF de la police par défaut
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 25.f))
		cerr << "Erreur lors du chargement de la police" << endl;


	Musique musicNuit("le_voyage_de_barbulle/music/nz/nuit.ogg");

	// DEF du bouton "nouvelle partie" ////////////

	Bouton boutNouvPartie;
	boutNouvPartie.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png","le_voyage_de_barbulle/img/histoire/bouton_f.png" );
	boutNouvPartie.redimensionner(0.5);

	int boutonPosition[2]; // position du bouton en fonction de la taille de la fenêtre
	boutonPosition[0] = (fenetre.GetWidth() / 2) - (boutNouvPartie.getTailleX() / 2);  // sur x, ici il est centré
	// on veut ajuster le premier bouton pour centrer les 4
	// la taille effective d'un bouton est égale à sa taille... plus 6px !
	// Soit (boutNouvPartie.getTailleY() + 6px) * 4 boutons /2
	boutonPosition[1] = (int)(fenetre.GetHeight() / 2) - (boutNouvPartie.getTailleY() + 6) * 2; // sur y, ici il est centré

	boutNouvPartie.placer(boutonPosition[0],boutonPosition[1]);

	// texte du bouton
	sf::String txtNouvPartie("Nouvelle Partie");
	txtNouvPartie.SetColor(sf::Color::Black);
	txtNouvPartie.SetSize(25.f);
	txtNouvPartie.SetFont(cursiveFont);
	boutNouvPartie.placerTexte(txtNouvPartie);

	// texte du bouton
	sf::Sprite background(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/fond_menu.png"));
	background.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	// DEF du bouton "continuer" ////////////

	Bouton boutContinuer;
	boutContinuer.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png","le_voyage_de_barbulle/img/histoire/bouton_f.png" );
	boutContinuer.redimensionner(0.5);

	// Seule la position vertical change pour ce bouton, on réutilise les variables précédentes
	// la hauteur un bouton plus 6px entre chaque bouton
	// on poura eventuellement changer plus tard pour coller au font
	boutonPosition[1] += boutContinuer.getTailleY() + 6;

	boutContinuer.placer(boutonPosition[0],boutonPosition[1]);

	// texte du bouton
	sf::String txtContinuer("Continuer");
	txtContinuer.SetColor(sf::Color::Black);
	txtContinuer.SetSize(25.f);
	txtContinuer.SetFont(cursiveFont);
	boutContinuer.placerTexte(txtContinuer);

	// DEF du bouton "scores" ////////////

	Bouton boutScores;
	boutScores.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png","le_voyage_de_barbulle/img/histoire/bouton_f.png" );
	boutScores.redimensionner(0.5);

	// Seule la position vertical change pour ce bouton, on réutilise les variables précédentes
	// la hauteur un bouton plus 6px entre chaque bouton
	// on poura eventuellement changer plus tard pour coller au font
	boutonPosition[1] += boutScores.getTailleY() + 6;

	boutScores.placer(boutonPosition[0],boutonPosition[1]);

	// texte du bouton
	sf::String txtScores("Scores");
	txtScores.SetColor(sf::Color::Black);
	txtScores.SetSize(25.f);
	txtScores.SetFont(cursiveFont);
	boutScores.placerTexte(txtScores);

	// DEF du bouton "crédits" ////////////

	Bouton boutCredits;
	boutCredits.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png","le_voyage_de_barbulle/img/histoire/bouton_f.png" );
	boutCredits.redimensionner(0.5);

	// Seule la position vertical change pour ce bouton, on réutilise les variables précédentes
	// la hauteur un bouton plus 6px entre chaque bouton
	// on poura eventuellement changer plus tard pour coller au font
	boutonPosition[1] += boutCredits.getTailleY() + 6;

	boutCredits.placer(boutonPosition[0],boutonPosition[1]);

	// texte du bouton
	sf::String txtCredits(L"Crédits");
	txtCredits.SetColor(sf::Color::Black);
	txtCredits.SetSize(25.f);
	txtCredits.SetFont(cursiveFont);
	boutCredits.placerTexte(txtCredits);


	// DEF titre de la page /////////////////////
	// texte du bouton
	sf::String txtTitre("Voyage avec Barbulle");
	txtTitre.SetSize(25.f);
	txtTitre.SetFont(cursiveFont);
	sf::Color::Color bleuclair(179,195,228);
	txtTitre.SetColor(bleuclair);

	int txtPosition[2];
	txtPosition[0] = (fenetre.GetWidth() / 2) - (txtTitre.GetRect().GetWidth() / 2);  // sur x, ici il est centré
	txtPosition[1] = boutNouvPartie.getPosY() - txtTitre.GetRect().GetHeight() - 6.f;
	txtTitre.SetPosition(txtPosition[0], txtPosition[1]);

	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	while(fenetre.IsOpened() && (ecranSuivant == MENU_0) )
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

		// titre de la fenêtre
		fenetre.Draw(txtTitre);

		// DESSIN DES BOUTONS //////////////////////////////////////
		fenetre.Draw(background);

		// -- nouvelle partie
		boutNouvPartie.drawMe(fenetre);
		fenetre.Draw(txtNouvPartie);
		// -- continuer
		boutContinuer.drawMe(fenetre);
		fenetre.Draw(txtContinuer);
		// -- scores
		boutScores.drawMe(fenetre);
		fenetre.Draw(txtScores);
		// -- crédits
		boutCredits.drawMe(fenetre);
		fenetre.Draw(txtCredits);


		fenetre.Display();

		// CLIQUE SUR nouvelle partie ///////////////////////////////
		if(boutNouvPartie.estClique(fenetre)) {
			Clock.Reset();
			musicNuit.Lecture();
			ecranSuivant = INTRO_G;
		}

	}

	return ecranSuivant;
}
