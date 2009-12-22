/*
 * Page.cpp
 *
 *  Created on: 21 déc. 2009
 *      Author: sophie
 */


#include "Page.h"

bool playing=true;

Page::Page() {
	// TODO Auto-generated constructor stub

}

Page::~Page() {
	// TODO Auto-generated destructor stub
}

void Page::dessinerFond(sf::RenderWindow &fenetre) {

}
void Page::dessinerMusic(sf::RenderWindow &fenetre) {

	play.initBouton("le_voyage_de_barbulle/img/histoire/play_icon.png","le_voyage_de_barbulle/img/histoire/play_icon_a.png");
	play.placer(fenetre.GetWidth()/6,0.f);
	play.redimensionner(40,40);
	pause.initBouton("le_voyage_de_barbulle/img/histoire/pause_icon.png","le_voyage_de_barbulle/img/histoire/pause_icon_a.png");
	pause.placer(fenetre.GetWidth()/6,0.f);
	pause.redimensionner(40,40);

	if(playing) {
		play.drawMe(&fenetre);
		if(play.estClique(&fenetre)) {
			playing=false;
		}
	}
	else {
		pause.drawMe(&fenetre);
		if(pause.estClique(&fenetre)) {
			playing=true;
		}
	}
}

void Page::dessinerPage(sf::RenderWindow &fenetre) {
	dessinerFond(fenetre);
	dessinerMusic(fenetre);
	back.initBouton("le_voyage_de_barbulle/img/histoire/back_icon.png","le_voyage_de_barbulle/img/histoire/back_icon_a.png");
	back.placer((fenetre.GetWidth()/2)-40.f,fenetre.GetHeight()-90);
	back.redimensionner(40.f,40.f);
	back.drawMe(&fenetre);
	go.initBouton("le_voyage_de_barbulle/img/histoire/go_icon.png","le_voyage_de_barbulle/img/histoire/go_icon_a.png");
	go.placer((fenetre.GetWidth()/2)+10,fenetre.GetHeight()-90);
	go.redimensionner(40.f,40.f);
	go.drawMe(&fenetre);
}
bool Page::menuActif(sf::RenderWindow &fenetre) {
	if(back.estClique(& fenetre) || go.estClique(& fenetre))
		return true;
	else
		return false;
}

int Page::changerEcran(sf::RenderWindow &fenetre, int cour, int suiv, int prec) {
	if (go.estClique(& fenetre))
		return suiv;
	if (back.estClique(& fenetre))
		return prec;
	else
		return cour;
}



