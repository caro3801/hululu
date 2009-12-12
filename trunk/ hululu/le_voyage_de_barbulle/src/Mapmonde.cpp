/*
 * Mapmonde.cpp
 *
 *  Created on: 10 déc. 2009
 *      Author: pirhoo
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Mapmonde.h"
#include "Person2D.h"


int Mapmonde::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = 1; // par défault, celui de l'écran actif

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image garçon
	sf::Image garcon_img;
	if (!garcon_img.LoadFromFile("Test_animation/img/sprite/sprite_g_walk_petit.png"))
		cerr << "Erreur lors du chargement de l'image.";

	// # image de fond
	sf::Image carte;
	if (!carte.LoadFromFile("Test_animation/img/sprite/mapemondev02.png"))
		cerr << "Erreur lors du chargement de l'image.";


	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image garçon
	Person2D garcon_sp(50.f, 100.f, fenetre.GetWidth()/15, 6, 4); // le personnage parcoud 1/10 de la largeur de la fenêtre à chaque pas
	garcon_sp.SetColor(sf::Color(255, 255, 255, 255));

	// positione le garçon dans le vide horizontalement, à gauche de la fenêtre
	// mais au centre, verticalement
	garcon_sp.SetPosition(-100.f, ( fenetre.GetHeight() - garcon_sp.getHeightCase() ) / 2.f);

	// charge l'image
	garcon_sp.SetImage(garcon_img); // la taille du personnage dépend de la fenêtre
	garcon_sp.Resize(fenetre.GetWidth()/3, fenetre.GetHeight()/2); /* on ne redimensione pas avec le même indice
																    * puisque le sprite à 6 cases en largeur
																    * et 4 en hauteur */

	// clipage du sprite
	// c-à-d on n'affiche que les partie du sprite qui nous intérèssent
	garcon_sp.initClip();

	// # image de fond
	sf::Sprite SpriteCarte(carte);
	SpriteCarte.SetPosition(0.f, 0.f);
	SpriteCarte.Resize(fenetre.GetWidth(), fenetre.GetHeight());


	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// instruction
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("Test_animation/img/font/Cursive_standard.ttf", 50))
		cerr << "Erreur lors du chargement de la police";

	sf::String text("Fleches haut, bas, gauche et droite pour deplacer le personnage.");
	text.Move(10, 600);
	text.SetColor(sf::Color::Blue);
	text.SetSize(25.f);
	text.SetFont(MyFont);

	// RENDU/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	// Pour que le programme ne se termine pas :)
	sf::Event event;
	while(fenetre.IsOpened())
	{
		// ANIMATIONS //////////////////////////////////////////
		// # on avance le bonhome vers la droite pour commencer
		 if( ( garcon_sp.GetPosition().x < 50.f) and not garcon_sp.inMoveTo(Person2D::RIGHT) ) // initialise le mouvement
				garcon_sp.walk(Person2D::RIGHT, 450);
		 else if(garcon_sp.inMoveTo(Person2D::RIGHT)) // poursuit le mouvement
				garcon_sp.walk(Person2D::RIGHT, 450);

		// EVENEMENTS //////////////////////////////////////////
		while (fenetre.GetEvent(event))
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
				fenetre.Close();

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) || ( garcon_sp.inMoveTo(Person2D::LEFT) ) )
			garcon_sp.walk(Person2D::LEFT, 450);

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Right)) || ( garcon_sp.inMoveTo(Person2D::RIGHT) ) )
			garcon_sp.walk(Person2D::RIGHT, 450);

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Up)) || ( garcon_sp.inMoveTo(Person2D::TOP) ) )
			garcon_sp.walk(Person2D::TOP, 450);

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Down)) || ( garcon_sp.inMoveTo(Person2D::BOTTOM) ) )
			garcon_sp.walk(Person2D::BOTTOM, 450);


		fenetre.Clear(sf::Color(255, 255, 255));

		fenetre.Draw(SpriteCarte) ;
		// on dessine le Sprite sur la fenetre de rendu
		fenetre.Draw(garcon_sp);
		// on dessine les instructions
		fenetre.Draw(text);
		// toujours pour actualiser le rendu (et en fin de boucle surtout) !

		fenetre.Display();

	}

	return  ecranSuivant;
}

