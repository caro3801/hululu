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
#include "Page.h"
#include "AccueilPays.h"
#include "DefineEcrans.h"

// WIKI SFML //////////////////////////
#include "Bouton.h"

Perou::Perou() {
	// TODO Auto-generated constructor stub

}

Perou::~Perou() {
	// TODO Auto-generated destructor stub
}

int Perou::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = PEROU;
	sf::Clock Clock; //Horloge
	Clock.Reset();
	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	AccueilPays PerouAccueil(fenetre,"le_voyage_de_barbulle/img/perou/drapPerou.jpg","le_voyage_de_barbulle/img/perou/titicaca.jpg","Amerique du Sud et Perou","A la rencontre des Incas",sf::Color::Red,sf::Color::Red);
	PerouAccueil.initAccueil(fenetre);
	//IMAGES////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
		sf::Sprite fond ;
		//fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/Drapeau_Debut.png"));
		//fond.SetPosition(0.f, 0.f);
		//fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

		Page pays;

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//sf::String texte("El Perudo, el pais de los Incas");
		//texte.SetColor(sf::Color::Red);
		//texte.SetSize(25.f);
		//texte.SetPosition((fenetre.GetWidth()*7/20), (fenetre.GetHeight()/8));
	//
		sf::Event event;

		// # création d'une vue sur la fenêtre
		sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
		fenetre.SetView(vue);

	// # image garçon

	//		sf::Image garcon_img;
	//		if (!garcon_img.LoadFromFile("le_voyage_de_barbulle/img/sprite/sprite_g_walk_petit.png"))
				cerr << "Erreur lors du chargement de l'image.";

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
	//				fenetre.Draw(fond);
	//				fenetre.Draw(texte);
					PerouAccueil.dessinerAccueil(fenetre);
					pays.dessinerPage(fenetre);
//					fenetre.Draw(garcon_sp);

//					// ANIMATIONS //////////////////////////////////////////
//							// # on avance le bonhome vers la droite pour commencer
//							 if( ( garcon_sp.GetPosition().x < 50.f) and not garcon_sp.inMoveTo(Person2D::RIGHT) ) { // initialise le mouvement
//									garcon_sp.walk(Person2D::RIGHT, 450);
//							 }
//							 else if(garcon_sp.inMoveTo(Person2D::RIGHT)) {// poursuit le mouvement
//									garcon_sp.walk(Person2D::RIGHT, 450);
//							 }
//							 //déplacement vers la gauche
//							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) || ( garcon_sp.inMoveTo(Person2D::LEFT) ) ) {
//							 			garcon_sp.walk(Person2D::LEFT, 450);
//							 }
//							 //déplacement vers la droite
//							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Right)) || ( garcon_sp.inMoveTo(Person2D::RIGHT) ) ) {
//							 			garcon_sp.walk(Person2D::RIGHT, 450);
//							 }
//							 //déplacement vers le haut
//							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Up)) || ( garcon_sp.inMoveTo(Person2D::TOP) ) ) {
//							 			garcon_sp.walk(Person2D::TOP, 450) ;
//							 }
//							 //déplacement vers le bas
//							 if( (fenetre.GetInput().IsKeyDown(sf::Key::Down)) || ( garcon_sp.inMoveTo(Person2D::BOTTOM) ) ) {
//							 			garcon_sp.walk(Person2D::BOTTOM, 450);
//							 }
				//dessin de la fenêtre
				 fenetre.Display();

				 if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre))
				 			return ecranSuivant=pays.changerEcran(fenetre,PEROU,PEROUPRESENT,MAPPEMONDE) ; //ecranSuivant = jeuPerou (5), ecranCourant = Perou (4),
				 																   //ecranPrecedent = Mapemonde (1)

			}

	return ecranSuivant;

}


