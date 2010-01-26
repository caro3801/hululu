/*
 * JeuJapon.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: pollet
 */
#include <iostream>
#include <sstream>
using namespace std;

#include "JeuJapon.h"
#include "Page.h"
#include "HistoireJapon.h"
#include "Person2D.h"
#include "Mapmonde.h"
#include "Bouton.h"
#include "AccueilPays.h"

#include "Carte.h"


JeuJapon::JeuJapon() {
	// TODO Auto-generated constructor stub
}

JeuJapon::~JeuJapon() {
	// TODO Auto-generated destructor stub
}


int JeuJapon::run(sf::RenderWindow &fenetre)
{
	/////Déclaration/////////////////////////////
	sf::Clock Clock; //Horloge
	Clock.Reset();
	int ecranSuivant = 6; // par défault, celui de l'écran actif
	Page pays;


	// Declaration CARTES //////////////////////
	Carte carteJanvier(	"le_voyage_de_barbulle/img/japon/hanafuda_01-01.png",
						"le_voyage_de_barbulle/img/japon/hanafuda_01-01C.png", 1, 1, 1); // janvier, carte 1, active
	carteJanvier.placer(500, 500);


	// FONT//////////////////////////////////////////////////////////////////////////////


	sf::Event event;

	// # création d'une vue sur la fenêtre
			sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
			fenetre.SetView(vue);



	///AFFICHAGE FENETRE////////////////////////////////

				while(fenetre.IsOpened() && (ecranSuivant==6))
					{
						while (fenetre.GetEvent(event)) {
								    // # Instanciation de tous les écrans fermeture de la fenetre
									// si echap ou fermeture manuelle
									if (event.Type == sf::Event::Closed)
										fenetre.Close();
									else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
										fenetre.Close();
								}

							fenetre.Clear(sf::Color(255, 200, 122));
							pays.dessinerPage(fenetre);

							if(carteJanvier.estClique(fenetre)) // la carte est cliquée
								carteJanvier.changerEtat(); // on change son état
							carteJanvier.carteVisible().drawMe(fenetre); // on dessine la carte visible (grisé ou non)

							fenetre.Display();


					if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
							ecranSuivant=pays.changerEcran(fenetre,6,7,1) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
														 																		   //ecranPrecedent = Mapmonde (1)
					if (fenetre.GetInput().IsKeyDown(sf::Key::O))
							ecranSuivant=6;

					if ((fenetre.GetInput().IsKeyDown(sf::Key::Space)))
							ecranSuivant=6;



					}
				return ecranSuivant;
}

