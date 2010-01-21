/*
 * Japon.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: Clappaz&Mollier
 */
#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Perou.h"
#include "Person2D.h"
#include "Mapmonde.h"
#include "JeuPerou.h"


// WIKI SFML //////////////////////////
#include "Bouton.h"

Perou::Perou() {
	// TODO Auto-generated constructor stub

}

Perou::~Perou() {
	// TODO Auto-generated destructor stub
}

int Perou::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 4;

	//IMAGES////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
		sf::Sprite fond ;
		fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/Drapeau_Debut.png"));
		fond.SetPosition(0.f, 0.f);
		fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

		sf::Sprite back_icon ;
		back_icon.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/back_icon.png"));
		back_icon.SetPosition((fenetre.GetWidth()-100),(fenetre.GetHeight()-100));
		back_icon.Resize(30,30);

		// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		sf::String texte("El Perudo, el pais de los Incas");
		texte.SetColor(sf::Color::Red);
		texte.SetSize(25.f);
		texte.SetPosition((fenetre.GetWidth()*7/20), (fenetre.GetHeight()/8));

		sf::Event event;

		// # création d'une vue sur la fenêtre
		sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
		fenetre.SetView(vue);







	// # image garçon

			sf::Image garcon_img;
			if (!garcon_img.LoadFromFile("le_voyage_de_barbulle/img/sprite/sprite_g_walk_petit.png"))
				cerr << "Erreur lors du chargement de l'image.";

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Person2D garcon_sp(50.f, 100.f, fenetre.GetWidth()/15, 6, 4); // le personnage parcours 1/10 de la largeur de la fenêtre à chaque pas
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
	// c-à-d on n'affiche que les parties du sprite qui nous intérèssent
	garcon_sp.initClip();


	///AFFICHAGE FENETRE////////////////////////////////

			while(fenetre.IsOpened())
				{
					while (fenetre.GetEvent(event)) {
							    // # Instanciation de tous les écrans fermeture de la fenetre
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
					fenetre.Draw(garcon_sp);

					// ANIMATIONS //////////////////////////////////////////
							// # on avance le bonhome vers la droite pour commencer
							 if( ( garcon_sp.GetPosition().x < 50.f) and not garcon_sp.inMoveTo(Person2D::RIGHT) ) { // initialise le mouvement
									garcon_sp.walk(Person2D::RIGHT, 450);
							 }
							 else if(garcon_sp.inMoveTo(Person2D::RIGHT)) {// poursuit le mouvement
									garcon_sp.walk(Person2D::RIGHT, 450);
							 }
							 //déplacement vers la gauche
							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) || ( garcon_sp.inMoveTo(Person2D::LEFT) ) ) {
							 			garcon_sp.walk(Person2D::LEFT, 450);
							 }
							 //déplacement vers la droite
							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Right)) || ( garcon_sp.inMoveTo(Person2D::RIGHT) ) ) {
							 			garcon_sp.walk(Person2D::RIGHT, 450);
							 }
							 //déplacement vers le haut
							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Up)) || ( garcon_sp.inMoveTo(Person2D::TOP) ) ) {
							 			garcon_sp.walk(Person2D::TOP, 450) ;
							 }
							 //déplacement vers le bas
							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Down)) || ( garcon_sp.inMoveTo(Person2D::BOTTOM) ) ) {
							 			garcon_sp.walk(Person2D::BOTTOM, 450);
							 }
				//dessin de la fenêtre
				 fenetre.Display();

					if ((fenetre.GetInput().IsKeyDown(sf::Key::Tab)))
					return (ecranSuivant=6);
			}

	return ecranSuivant;

}


