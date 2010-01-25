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

	// FONT//////////////////////////////////////////////////////////////////////////////


	sf::Event event;

	// # création d'une vue sur la fenêtre
			sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
			fenetre.SetView(vue);



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

							fenetre.Clear(sf::Color(255, 200, 122));
							pays.dessinerPage(fenetre);
							fenetre.Display();

					if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
									return ecranSuivant=pays.changerEcran(fenetre,6,7,1) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
														 																		   //ecranPrecedent = Mapmonde (1)
					if (fenetre.GetInput().IsKeyDown(sf::Key::O))
							 		return ecranSuivant=6;

					if ((fenetre.GetInput().IsKeyDown(sf::Key::Space)))
									return (ecranSuivant=6);



					}
				return ecranSuivant;
}

