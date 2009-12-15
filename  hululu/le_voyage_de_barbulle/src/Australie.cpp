/*
 * Australie.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: pirhoo
 */


#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Australie.h"
#include "Person2D.h"

Australie::Australie()
{

}

int Australie::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = 1; // par défault, celui de l'écran actif



	// # image de fond
	// l'image
	sf::Image background;
	if (!background.LoadFromFile("Test_animation/img/sprite/mapemondev02.png"))
		cerr << "Erreur lors du chargement de l'image.";
	// son sprite
	sf::Sprite background_sp(background);
	background_sp.SetPosition(0.f, 0.f); // en haut à gauche
	background_sp.Resize(fenetre.GetWidth(), fenetre.GetHeight()); // aux dimensions de la fenêtre


	// # Pour que le programme ne se termine pas :)
	sf::Event event;
	while(fenetre.IsOpened())
	{

		// EVENEMENTS //////////////////////////////////////////
		while (fenetre.GetEvent(event))
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
				fenetre.Close();

		fenetre.Draw(background_sp) ;
		fenetre.Display();

	}

	return  ecranSuivant;
}


