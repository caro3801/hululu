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

int Menu_0::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = 0;
	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//image de bouton normal
	sf::Image imgbouton_n;
	if (!imgbouton_n.LoadFromFile("le_voyage_de_barbulle/img/histoire/bouton_n.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}
	//image de bouton focus
	sf::Image imgbouton;
	if (!imgbouton.LoadFromFile("le_voyage_de_barbulle/img/histoire/bouton_f.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}

	//image de fond
	sf::Image imgpage;
	if (!imgpage.LoadFromFile("le_voyage_de_barbulle/img/histoire/page1.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}
	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Sprite page(imgpage);
	page.SetPosition(0.f, 0.f);

	Bouton bouton;
	bouton.setPosition(100,200);
	bouton.initBouton(&imgbouton_n, &imgbouton);

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Font MyFont;
		if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
		{
			cout << "Erreur lors du chargement de la police";
		}

		sf::String texte("Continuer");
		texte.SetColor(sf::Color::White);
		texte.SetSize(25.f);

		sf::Event event;

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
			bouton.placerTexte(&texte);

			fenetre.Clear(sf::Color(255, 255, 255));


			fenetre.Draw(page);
			bouton.drawMe(&fenetre);
			fenetre.Draw(texte);
			fenetre.Display();

			if(bouton.estClique(&fenetre)) {
				return (ecranSuivant=1);
			}
		}
	return ecranSuivant;
}
