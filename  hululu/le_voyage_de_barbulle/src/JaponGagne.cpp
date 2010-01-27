/*
 * JaponGagne.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pollet
 */

#include "JaponGagne.h"
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
#include "DefineEcrans.h"
#include <vector>
#include "PoleSud_Porte.h"

#include "Carte.h"

JaponGagne::JaponGagne() {
	// TODO Auto-generated constructor stub

}

JaponGagne::~JaponGagne() {
	// TODO Auto-generated destructor stub
}

int JaponGagne::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = JAPONGAGNE;
	sf::Clock Clock;
	Clock.Reset();
	Page pays;


	// FONT//////////////////////////////////////////////////////////////////////////
	sf::Event event;

	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Sprite Sakura;
	Sakura.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/Sakura.png"));
	Sakura.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/1.3));
	Sakura.Resize(400, 400);

	sf::Sprite Sakura2;
	Sakura2.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/Sakura.png"));
	Sakura2.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/30));
	Sakura2.Resize(100, 100);

	//PoleSud_Porte::lampion.initDessin("le_voyage_de_barbulle/img/objets/lampion.png");
	PoleSud_Porte::lampion.placer((fenetre.GetWidth())/2, ((fenetre.GetHeight())/3));

	////////////////////////////////

				while(fenetre.IsOpened() && (ecranSuivant == JAPONGAGNE))
				{
					while (fenetre.GetEvent(event)) {
						// # Instanciation de tous les éc fermeture de la fenetre
						// si echap ou fermeture manuelle
						if (event.Type == sf::Event::Closed)
							fenetre.Close();
						else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
							fenetre.Close();
					}

					fenetre.Clear(sf::Color(255, 200, 122));

					fenetre.Draw(Sakura);
					fenetre.Draw(Sakura2);
					pays.dessinerPage(fenetre);
		//			PoleSud_Porte::lampion.dessinerObjet(fenetre);
					fenetre.Display();

					if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
						ecranSuivant=pays.changerEcran(fenetre,JAPON,HISTOIREJAPON,MAPPEMONDE) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
																			   //ecranPrecedent = Mapmonde (1)
					if (fenetre.GetInput().IsKeyDown(sf::Key::O))
						ecranSuivant=MAPPEMONDE;

				}

	return ecranSuivant;
}
