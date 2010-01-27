/*
 * PoleSud_Porte.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#include "PoleSud_Porte.h"
#include <iostream>
using namespace std;

// WIKI SFML //////////////////////////
#include "BoutonMove.h"
#include "AccueilPays.h"
#include "Page.h"
#include "Bouton.h"
#include "Objet.h"

PoleSud_Porte::PoleSud_Porte() {

}

PoleSud_Porte::~PoleSud_Porte() {
}

Objet PoleSud_Porte::blason;
Objet PoleSud_Porte::weta;
Objet PoleSud_Porte::poncho;
Objet PoleSud_Porte::lampion;


int PoleSud_Porte::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = POLESUD_PORTE;
	sf::Clock Clock;
	Clock.Reset();
	bool mouseMove = false;
	bool lache = true;

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
	sf::Sprite fond ;
	fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_sans_objets.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	sf::Sprite porte_blason ;
	porte_blason.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_blason.png"));
	porte_blason.SetPosition(0.f, 0.f);
	porte_blason.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	poncho.initBouton("le_voyage_de_barbulle/img/objets/poncho.png","le_voyage_de_barbulle/img/objets/poncho.png");
	poncho.placer(100,100);
	poncho.decalageSouris(poncho.getTailleX()/2,poncho.getTailleY()/2);

	weta.placer(200,200);
	weta.initBouton("le_voyage_de_barbulle/img/objets/weta.png","le_voyage_de_barbulle/img/objets/weta.png");
	weta.decalageSouris(weta.getTailleX()/2,weta.getTailleY()/2);


	blason.placer(300,300);
	blason.initBouton("le_voyage_de_barbulle/img/objets/blason.png","le_voyage_de_barbulle/img/objets/blason.png");
	blason.decalageSouris(blason.getTailleX()/2,blason.getTailleY()/2);


	lampion.placer(400,400);
	lampion.initBouton("le_voyage_de_barbulle/img/objets/lampion.png","le_voyage_de_barbulle/img/objets/lampion.png");
	lampion.decalageSouris(lampion.getTailleX()/2,lampion.getTailleY()/2);
	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Event event;

	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	////////////////////////////////

	while(fenetre.IsOpened())
	{

		while (fenetre.GetEvent(event)) {
			// # Instanciation de tous les éc fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
				fenetre.Close();
			else if(event.Type==sf::Event::MouseMoved)
				mouseMove=true;
			else if(event.Type==sf::Event::MouseButtonPressed && (event.MouseButton.Button==sf::Mouse::Left)) {
				lache = true;
			}
		}

		fenetre.Clear(sf::Color(255, 255, 255));
		fenetre.Draw(fond);
		pays.dessinerPage(fenetre);

		if( autoriseBouger(PoleSud_Porte::poncho) && PoleSud_Porte::poncho.estClique(fenetre) ) {
			PoleSud_Porte::poncho.setABouger(true);
		}

		if( autoriseBouger(PoleSud_Porte::weta)  && PoleSud_Porte::weta.estClique(fenetre) ) {
			PoleSud_Porte::weta.setABouger(true);
		}

		if( autoriseBouger(PoleSud_Porte::blason) && PoleSud_Porte::blason.estClique(fenetre) ) {
			PoleSud_Porte::blason.setABouger(true);
		}

		if( autoriseBouger(PoleSud_Porte::lampion)  && PoleSud_Porte::lampion.estClique(fenetre) ) {
			PoleSud_Porte::lampion.setABouger(true);
		}


		PoleSud_Porte::weta.deplacer(fenetre,mouseMove,lache);
		PoleSud_Porte::poncho.deplacer(fenetre,mouseMove,lache);
		PoleSud_Porte::lampion.deplacer(fenetre,mouseMove,lache);
		PoleSud_Porte::blason.deplacer(fenetre,mouseMove,lache);


		if(PoleSud_Porte::blason.getTrouve()==true) {
			fenetre.Draw(porte_blason);
		}

		PoleSud_Porte::weta.drawMe(fenetre);
		PoleSud_Porte::poncho.drawMe(fenetre);
		PoleSud_Porte::lampion.drawMe(fenetre);
		PoleSud_Porte::blason.drawMe(fenetre);

		fenetre.Display();

		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			return ecranSuivant=pays.changerEcran(fenetre,POLESUD_PORTE,POLESUD_PORTE,MAPPEMONDE) ;

	}

	return ecranSuivant;

}

bool PoleSud_Porte::autoriseBouger(Objet & obj) {

	if(&obj == &weta)
		return ( !lampion.estBougeable() && !blason.estBougeable() && !poncho.estBougeable() );

	else if(&obj == &lampion)
		return ( !blason.estBougeable() && !poncho.estBougeable() && !weta.estBougeable());

	else if(&obj == &blason)
		return ( !lampion.estBougeable() && !poncho.estBougeable() && !weta.estBougeable());

	else // poncho
		return ( !lampion.estBougeable() && !blason.estBougeable() && !weta.estBougeable());
}
