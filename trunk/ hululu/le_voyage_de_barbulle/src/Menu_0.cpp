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

int Menu_0::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = 0;
	sf::Clock Clock;
	// SPRITES /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//sf::Sprite page(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/page1.png"));
	//page.SetPosition(0.f, 0.f);
	Bouton bouton;
	bouton.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png","le_voyage_de_barbulle/img/histoire/bouton_f.png" );
	bouton.placer(300,300);
	bouton.redimensionner(300,200);

	// # image garçon
		Person2D garcon_sp(50.f, 100.f, fenetre.GetWidth()/15, 6, 4); // le personnage parcoud 1/10 de la largeur de la fenêtre à chaque pas
		garcon_sp.SetColor(sf::Color(255, 255, 255, 255));

		// positione le garçon dans le vide horizontalement, à gauche de la fenêtre
		// mais au centre, verticalement
		garcon_sp.SetPosition(-100.f, ( fenetre.GetHeight() - garcon_sp.getHeightCase() ) / 2.f);

		// charge l'image
		garcon_sp.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/sprite/sprite_g_walk_petit.png")); // la taille du personnage dépend de la fenêtre
		//garcon_sp.Resize(fenetre.GetWidth()/3, fenetre.GetHeight()/2); /* on ne redimensione pas avec le même indice
																	 //   * puisque le sprite à 6 cases en largeur
																	 //   * et 4 en hauteur */

		// clipage du sprite
		// c-à-d on n'affiche que les partie du sprite qui nous intérèssent
		garcon_sp.initClip();

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Font MyFont;
		if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
		{
			cout << "Erreur lors du chargement de la police";
		}

		sf::String texte("Continuer");
		texte.SetColor(sf::Color::Black);
		texte.SetSize(25.f);

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

			// ANIMATIONS //////////////////////////////////////////
					// # on avance le bonhome vers la droite pour commencer
			 if( ( garcon_sp.GetPosition().x < 200.f) and not garcon_sp.inMoveTo(Person2D::RIGHT) ) { // initialise le mouvement
					garcon_sp.walk(Person2D::RIGHT, 450);
			 }
			 else if(garcon_sp.inMoveTo(Person2D::RIGHT)) {// poursuit le mouvement
					garcon_sp.walk(Person2D::RIGHT, 450);
			 }

			bouton.placerTexte(&texte);

			fenetre.Clear(sf::Color(255, 255, 255));
			//fenetre.Draw(page);
			fenetre.Draw(garcon_sp);
			bouton.drawMe(&fenetre);
			fenetre.Draw(texte);

			if(bouton.estClique(&fenetre)) {
				Clock.Reset();
				while(Clock.GetElapsedTime()<1) {
					 if( ( garcon_sp.GetPosition().x < 600.f) and not garcon_sp.inMoveTo(Person2D::RIGHT) ) { // initialise le mouvement
							garcon_sp.walk(Person2D::RIGHT, 450);
					 }
					 else if(garcon_sp.inMoveTo(Person2D::RIGHT)) {// poursuit le mouvement
							garcon_sp.walk(Person2D::RIGHT, 450);
					 }
				fenetre.Clear(sf::Color(255, 255, 255));
				bouton.drawMe(&fenetre);
				fenetre.Draw(texte);
				fenetre.Draw(garcon_sp);
				fenetre.Display();
				}
				return (ecranSuivant=1);
			}
			fenetre.Display();

		}
	return ecranSuivant;
}
