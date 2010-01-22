/*
 * TestDeplacer.cpp
 *
 *  Created on: 21 janv. 2010
 *      Author: sophie
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// WIKI SFML //////////////////////////
#include "Bouton.h"
#include "BoutonMove.h"
#include "AccueilPays.h"
#include "Page.h"
#include "TestDeplacer.h"


TestDeplacer::TestDeplacer() {
}

TestDeplacer::~TestDeplacer() {
}

int TestDeplacer::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 75; //Juste une classe de test, donc si vous voulez voir le résultat, mettre une valeur correcte ici et dans le main :)

	bool mouseMove = false;
	//Booléen pour savoir si la souris est en mouvement: utile pour déplacer des objets a la souris

	sf::Clock Clock;
	Clock.Reset();

    //SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Page pays;

	BoutonMove piece5; //piece5 est un bouton que l'on veut pouvoir déplacer a la souris
	piece5.initBouton("le_voyage_de_barbulle/img/sprite/piece5.png","le_voyage_de_barbulle/img/sprite/piece5.png");
	piece5.placer(300,300);
	piece5.decalageSouris(25.0,25.0); //On met un décalage si on le souhaite, pour un meilleur
									  //affichage de l'objet par rapport a la souris

    //EVENEMENTS/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Event event;

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while(fenetre.IsOpened())
	{
		mouseMove=false; //On remet le booléen indiquant que la souris bouge a faux a chaque nouveau tour de boucle
						 //Pour vérifier si cette condition est toujours vraie
		while (fenetre.GetEvent(event)) {
				    // # Instanciation de tous les éc fermeture de la fenetre
					// si echap ou fermeture manuelle
					if (event.Type == sf::Event::Closed)
						fenetre.Close();
					else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
						fenetre.Close();
					//Si l'evenement est de type: souris en mouvement, mouseMove est vrai (utile pour les boutonMove)
					else if(event.Type==sf::Event::MouseMoved)
						mouseMove=true;
				}

		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			return ecranSuivant=pays.changerEcran(fenetre,2,4,1) ; //ecranSuivant = jeuItalie (4), ecranCourant = Italie (2),
																   //ecranPrecedent = Mapmonde (1)
		if (fenetre.GetInput().IsKeyDown(sf::Key::O))
			return ecranSuivant=4;

		piece5.deplacer(fenetre,mouseMove);

		fenetre.Clear(sf::Color(255, 255, 255));
		pays.dessinerPage(fenetre);
		piece5.drawMe(&fenetre);
		fenetre.Display();
	}

	return ecranSuivant;

}
