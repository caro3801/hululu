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
	play.placer(fenetre.GetWidth()*0.02, fenetre.GetHeight()*0.02);
	play.redimensionner(40,40);
	pause.initBouton("le_voyage_de_barbulle/img/histoire/pause_icon.png","le_voyage_de_barbulle/img/histoire/pause_icon_a.png");
	pause.placer(fenetre.GetWidth()*0.02, fenetre.GetHeight()*0.02);
	pause.redimensionner(40,40);

	if(playing) {
		play.drawMe(fenetre);
		if(play.estClique(fenetre)) {
			playing=false;
		}
	}
	else {
		pause.drawMe(fenetre);
		if(pause.estClique(fenetre)) {
			playing=true;
		}
	}
}

void Page::dessinerPage(sf::RenderWindow &fenetre) {
	dessinerFond(fenetre);
	dessinerMusic(fenetre);

	font.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/fontBouton.png") );
	font.SetPosition((fenetre.GetWidth()/2)-60.f, fenetre.GetHeight()-70);
	//font.Set(110,60);
	fenetre.Draw(font);

	back.initBouton("le_voyage_de_barbulle/img/histoire/back_icon.png","le_voyage_de_barbulle/img/histoire/back_icon_a.png");
	back.placer((fenetre.GetWidth()/2)-50.f,fenetre.GetHeight()-60);
	back.redimensionner(40.f,40.f);
	back.drawMe(fenetre);

	go.initBouton("le_voyage_de_barbulle/img/histoire/go_icon.png","le_voyage_de_barbulle/img/histoire/go_icon_a.png");
	go.placer((fenetre.GetWidth()/2),fenetre.GetHeight()-60);
	go.redimensionner(40.f,40.f);
	go.drawMe(fenetre);
}
bool Page::menuActif(sf::RenderWindow & fenetre) {
	if(back.estClique(fenetre) || go.estClique(fenetre))
		return true;
	else
		return false;
}

int Page::changerEcran(sf::RenderWindow &fenetre, int cour, int suiv, int prec) {
	if (go.estClique(fenetre))
		return suiv;
	if (back.estClique(fenetre))
		return prec;
	else
		return cour;
}



