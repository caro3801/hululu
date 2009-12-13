/*
 * Italie.cpp
 *
 *  Created on: 12 déc. 2009
 *      Author: sof
 */
#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// WIKI SFML //////////////////////////
#include "Italie.h"
#include "Bouton.h"
ImageManager Ecran::MonManager; //a ne definir qu'une seule fois dans tout le programme

Italie::Italie() {
}

Italie::~Italie() {
}

int Italie::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 2;

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
	sf::Sprite fond ;
	fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/italie_fond.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize((fenetre.GetWidth()/3), (fenetre.GetHeight()/3));

	sf::Sprite back_icon ;
	back_icon.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/back_icon.png"));
	back_icon.SetPosition((fenetre.GetWidth()-100),(fenetre.GetHeight()-100));
	back_icon.Resize(30,30);

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		sf::String texte("Benvenuto in Italia");
		texte.SetColor(sf::Color::Blue);
		texte.SetSize(25.f);
		texte.SetPosition((fenetre.GetWidth()/3), (fenetre.GetHeight()/3));

	sf::Event event;

	// # création d'une vue sur la fenêtre - !! Puisqu'une vue a été créee sur l'ecran précédent (Mapemonde) obligé de recréer une vue
	//pour toutes les fenetres suivantes, ou images et sprites ne s'affichent pas!
	//a voir pour trouver une autre solution : suppression vue ? re-definition de la vue par defaut ?
	//ou on crée une autre vue a chaque fois.
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);
	////////////////////////////////

	while(fenetre.IsOpened())
	{
		while (fenetre.GetEvent(event)) {
				    // # Instanciation de tous les éc fermeture de la fenetre
					// si echap ou fermeture manuelle
					if (event.Type == sf::Event::Closed)
						fenetre.Close();
					else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
						fenetre.Close();
				}

		fenetre.Clear(sf::Color(255, 255, 255));
		fenetre.Draw(fond);
		fenetre.Draw(texte);
		fenetre.Draw(back_icon);
		fenetre.Display();
		if ((fenetre.GetInput().IsKeyDown(sf::Key::Space)))
			return (ecranSuivant=1);
	}

	return ecranSuivant;

}
