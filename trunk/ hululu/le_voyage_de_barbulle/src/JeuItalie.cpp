/*
 * JeuItalie.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: sophie
 */

#include "JeuItalie.h"

JeuItalie::JeuItalie() {
}

JeuItalie::~JeuItalie() {
}

int JeuItalie::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = 4; // par défault, celui de l'écran actif

	sf::Sprite original;
	original.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/7erreurs_original.png"));
	original.SetPosition(10.f,10.f);
	original.Resize( ((fenetre.GetWidth())/2), ((fenetre.GetHeight())));

	sf::Sprite erreur;
	erreur.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/7erreurs_faute.png"));
	erreur.SetPosition(fenetre.GetWidth()-erreur.GetSize().x,0.f);
	erreur.Resize( ((fenetre.GetWidth())/2), ((fenetre.GetHeight())));
	//Vue
	// # création d'une vue sur la fenêtre
		sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
		fenetre.SetView(vue);

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

		fenetre.Clear();
		fenetre.Draw(original);
		fenetre.Draw(erreur);
		fenetre.Display();

	}

	return  ecranSuivant;
}
