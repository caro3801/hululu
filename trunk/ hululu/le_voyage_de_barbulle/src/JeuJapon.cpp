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
#include <vector>

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


	vector<Carte> tabCarte;


	// Declaration CARTES //////////////////////
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-01.png","le_voyage_de_barbulle/img/japon/hanafuda_01-01C.png", 1, 1, 1) ); // janvier, carte 1, active
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-02.png","le_voyage_de_barbulle/img/japon/hanafuda_01-02C.png", 1, 2, 1) ); // janvier, carte 1, active
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-03.png","le_voyage_de_barbulle/img/japon/hanafuda_01-03C.png", 1, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-04.png","le_voyage_de_barbulle/img/japon/hanafuda_01-04C.png", 1, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-01.png","le_voyage_de_barbulle/img/japon/hanafuda_02-01C.png", 2, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-02.png","le_voyage_de_barbulle/img/japon/hanafuda_02-02C.png", 2, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-03.png","le_voyage_de_barbulle/img/japon/hanafuda_02-03C.png", 2, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-04.png","le_voyage_de_barbulle/img/japon/hanafuda_02-01C.png", 2, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-01.png","le_voyage_de_barbulle/img/japon/hanafuda_03-01C.png", 3, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-02.png","le_voyage_de_barbulle/img/japon/hanafuda_03-02C.png", 3, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-03.png","le_voyage_de_barbulle/img/japon/hanafuda_03-03C.png", 3, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-04.png","le_voyage_de_barbulle/img/japon/hanafuda_03-04C.png", 3, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-01.png","le_voyage_de_barbulle/img/japon/hanafuda_04-01C.png", 4, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-02.png","le_voyage_de_barbulle/img/japon/hanafuda_04-02C.png", 4, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-03.png","le_voyage_de_barbulle/img/japon/hanafuda_04-03C.png", 4, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-04.png","le_voyage_de_barbulle/img/japon/hanafuda_04-04C.png", 4, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-01.png","le_voyage_de_barbulle/img/japon/hanafuda_05-01C.png", 5, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-02.png","le_voyage_de_barbulle/img/japon/hanafuda_05-02C.png", 5, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-03.png","le_voyage_de_barbulle/img/japon/hanafuda_05-03C.png", 5, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-04.png","le_voyage_de_barbulle/img/japon/hanafuda_05-04C.png", 5, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-01.png","le_voyage_de_barbulle/img/japon/hanafuda_06-01C.png", 6, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-02.png","le_voyage_de_barbulle/img/japon/hanafuda_06-02C.png", 6, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-03.png","le_voyage_de_barbulle/img/japon/hanafuda_06-03C.png", 6, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-04.png","le_voyage_de_barbulle/img/japon/hanafuda_06-04C.png", 6, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-01.png","le_voyage_de_barbulle/img/japon/hanafuda_07-01C.png", 7, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-02.png","le_voyage_de_barbulle/img/japon/hanafuda_07-02C.png", 7, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-03.png","le_voyage_de_barbulle/img/japon/hanafuda_07-03C.png", 7, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-04.png","le_voyage_de_barbulle/img/japon/hanafuda_07-04C.png", 7, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-01.png","le_voyage_de_barbulle/img/japon/hanafuda_08-01C.png", 8, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-02.png","le_voyage_de_barbulle/img/japon/hanafuda_08-02C.png", 8, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-03.png","le_voyage_de_barbulle/img/japon/hanafuda_08-03C.png", 8, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-04.png","le_voyage_de_barbulle/img/japon/hanafuda_08-04C.png", 8, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-01.png","le_voyage_de_barbulle/img/japon/hanafuda_09-01C.png", 9, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-02.png","le_voyage_de_barbulle/img/japon/hanafuda_09-02C.png", 9, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-03.png","le_voyage_de_barbulle/img/japon/hanafuda_09-03C.png", 9, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-01.png","le_voyage_de_barbulle/img/japon/hanafuda_09-01C.png", 9, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-01.png","le_voyage_de_barbulle/img/japon/hanafuda_10-01C.png", 10, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-02.png","le_voyage_de_barbulle/img/japon/hanafuda_10-02C.png", 10, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-03.png","le_voyage_de_barbulle/img/japon/hanafuda_10-03C.png", 10, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-04.png","le_voyage_de_barbulle/img/japon/hanafuda_10-04C.png", 10, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-01.png","le_voyage_de_barbulle/img/japon/hanafuda_11-01C.png", 11, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-02.png","le_voyage_de_barbulle/img/japon/hanafuda_11-02C.png", 11, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-03.png","le_voyage_de_barbulle/img/japon/hanafuda_11-03C.png", 11, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-04.png","le_voyage_de_barbulle/img/japon/hanafuda_11-04C.png", 11, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-01.png","le_voyage_de_barbulle/img/japon/hanafuda_12-01C.png", 12, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-02.png","le_voyage_de_barbulle/img/japon/hanafuda_12-02C.png", 12, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-03.png","le_voyage_de_barbulle/img/japon/hanafuda_12-03C.png", 12, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-04.png","le_voyage_de_barbulle/img/japon/hanafuda_12-04C.png", 12, 4, 1) );

	// PLACEMENT CARTE
	int j=0;
	int k=0;
	int i=0;

	while (i<48){

		tabCarte[0].placer((fenetre.GetWidth()/4)+j, (fenetre.GetHeight()/4)+k);
		j=j+70;
		k=k+100;
		i++;
	}
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
						//	pays.dessinerPage(fenetre);

							if(tabCarte[0].estClique(fenetre)) // la carte est cliquée
								tabCarte[0].changerEtat(); // on change son état
							tabCarte[0].carteVisible().drawMe(fenetre); // on dessine la carte visible (grisé ou non)

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

