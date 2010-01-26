/*
 * HistoireJapon.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: pollet
 */
#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "HistoireJapon.h"
#include "Person2D.h"
#include "Mapmonde.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "Page.h"
#include "DefineEcrans.h"


HistoireJapon::HistoireJapon() {
	// TODO Auto-generated constructor stub

}

HistoireJapon::~HistoireJapon() {
	// TODO Auto-generated destructor stub
}

int HistoireJapon::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 5;
	sf::Clock Clock;
	Clock.Reset();
	Page pays;

	//IMAGES////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// # image de fond
		sf::Sprite fond ;
		fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/japon_fond.png"));
		fond.SetPosition(0.f, 0.f);
		fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));


		// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		sf::Event event;

		// # création d'une vue sur la fenêtre
		sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
		fenetre.SetView(vue);

	// # image de l'instruction
		sf::Sprite fondinst ;
		fondinst.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/fondhistoire1.png"));
		fondinst.SetPosition(fenetre.GetWidth()*0.06, fenetre.GetHeight()*0.06);


	// # image garçon

			sf::Image garcon_img;
			if (!garcon_img.LoadFromFile("le_voyage_de_barbulle/img/sprite/sprite_g_walk_petit.png"))
				cerr << "Erreur lors du chargement de l'image.";


	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Person2D garcon_sp(50.f, 100.f, fenetre.GetWidth()/15, 6, 4); // le personnage parcours 1/10 de la largeur de la fenêtre à chaque pas
	garcon_sp.SetColor(sf::Color(255, 255, 255, 255));

	// positione le garçon dans le vide horizontalement, à gauche de la fenêtre
	// mais au centre, verticalement
	garcon_sp.SetPosition(fenetre.GetWidth()+100, ( fenetre.GetHeight() - garcon_sp.getHeightCase() ) / 2.f);

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
					fenetre.Draw(garcon_sp);
					fenetre.Draw(fondinst);
					pays.dessinerPage(fenetre);
					fenetre.Display();




					// ANIMATIONS //////////////////////////////////////////
							// # on avance le bonhome vers la droite pour commencer
							 if( ( garcon_sp.GetPosition().x > fenetre.GetWidth() - 50.f) and not garcon_sp.inMoveTo(Person2D::LEFT) ) { // initialise le mouvement
									garcon_sp.walk(Person2D::LEFT, 450);
							 }
							 else if(garcon_sp.inMoveTo(Person2D::LEFT)) {// poursuit le mouvement
									garcon_sp.walk(Person2D::LEFT, 450);
							 }
							 //déplacement vers la gauche
							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) || ( garcon_sp.inMoveTo(Person2D::LEFT) ) ) {
							 			garcon_sp.walk(Person2D::LEFT, 450);
							 }
							 //déplacement vers la droite
							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Right)) || ( garcon_sp.inMoveTo(Person2D::RIGHT) ) ) {
							 			garcon_sp.walk(Person2D::RIGHT, 450);
							 }

				//dessin de la fenêtre
				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
					return ecranSuivant=pays.changerEcran(fenetre,HISTOIREJAPON,JEUJAPON,JAPON) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
							 																		   //ecranPrecedent = Mapmonde (1)
				if (fenetre.GetInput().IsKeyDown(sf::Key::O))
							 		return ecranSuivant=HISTOIREJAPON;
				if ((fenetre.GetInput().IsKeyDown(sf::Key::Space)))
									return (ecranSuivant=HISTOIREJAPON);
				}
	return ecranSuivant;

}


