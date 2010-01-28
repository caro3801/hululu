/*
 * Page.cpp
 *
 *  Created on: 21 déc. 2009
 *      Author: sophie
 */


#include "Page.h"
#include "DefineEcrans.h"
#include <iostream>
using namespace std;


Page::Page() {
	playing = false;
	muting = true;
	alpha = 255;
}

Page::~Page() {
	// TODO Auto-generated destructor stub
}

void Page::dessinerFond(sf::RenderWindow &fenetre) {

}

void Page::dessinerMusic(sf::RenderWindow &fenetre) {


	fontMusic.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/fontBouton.png") );
	fontMusic.SetPosition(10,10);
	//font.Set(110,60);
	fenetre.Draw(fontMusic);



	// -- MUTE /////////////////////

	noMute.initBouton("le_voyage_de_barbulle/img/histoire/icon_music.png","le_voyage_de_barbulle/img/histoire/icon_music_a.png");
	noMute.placer(20, 20);
	noMute.redimensionner(40,40);

	mute.initBouton("le_voyage_de_barbulle/img/histoire/icon_music_mute.png","le_voyage_de_barbulle/img/histoire/icon_music_mute.png");
	mute.placer(noMute.getPosX(), noMute.getPosY());
	mute.redimensionner(40,40);

	if(muting) {
		mute.resetTimer();
		noMute.drawMe(fenetre);
		if(noMute.estClique(fenetre)) {
			noMute.resetTimer();
			muting=false;
		}
	}
	else {
		noMute.resetTimer();
		mute.drawMe(fenetre);
		if(mute.estClique(fenetre)) {
			mute.resetTimer();
			muting=true;
		}
	}


	// -- PLAY / PAUSE /////////////////////

	play.initBouton("le_voyage_de_barbulle/img/histoire/play_icon.png","le_voyage_de_barbulle/img/histoire/play_icon_a.png");
	play.placer(noMute.getPosX() + 50, noMute.getPosY());
	play.redimensionner(40,40);

	pause.initBouton("le_voyage_de_barbulle/img/histoire/pause_icon.png","le_voyage_de_barbulle/img/histoire/pause_icon_a.png");
	pause.placer(play.getPosX(), play.getPosY());
	pause.redimensionner(40,40);

	if(playing) {
		pause.resetTimer();
		play.drawMe(fenetre);
		if(play.estClique(fenetre)) {
			play.resetTimer();
			playing=false;
		}
	}
	else {
		play.resetTimer();
		pause.drawMe(fenetre);
		if(pause.estClique(fenetre)) {
			pause.resetTimer();
			playing=true;
		}
	}



	// -- REPETER /////////////////////

	repeter.initBouton("le_voyage_de_barbulle/img/histoire/repeter_icon.png","le_voyage_de_barbulle/img/histoire/repeter_icon_a.png");
	repeter.placer(play.getPosX() + 50, play.getPosY());
	repeter.redimensionner(40,40);
	repeter.drawMe(fenetre);

}

void Page::dessinerPage(sf::RenderWindow &fenetre) {
	dessinerFond(fenetre);
	dessinerMusic(fenetre);

	fontNavigation.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/fontBouton.png") );
	fontNavigation.SetPosition((fenetre.GetWidth()/2)-60.f, fenetre.GetHeight()-70);
	//font.Set(110,60);
	fenetre.Draw(fontNavigation);

	map.initBouton("le_voyage_de_barbulle/img/histoire/map_icon.png","le_voyage_de_barbulle/img/histoire/map_icon_a.png");
	map.placer((fenetre.GetWidth()/2),fenetre.GetHeight()-60);
	map.redimensionner(40.f,40.f);
	map.drawMe(fenetre);

	back.initBouton("le_voyage_de_barbulle/img/histoire/back_icon.png","le_voyage_de_barbulle/img/histoire/back_icon_a.png");
	back.placer(map.getPosX()-50.f,fenetre.GetHeight()-60);
	back.redimensionner(40.f,40.f);
	back.drawMe(fenetre);

	go.initBouton("le_voyage_de_barbulle/img/histoire/go_icon.png","le_voyage_de_barbulle/img/histoire/go_icon_a.png");
	go.placer(map.getPosX()+50.f,fenetre.GetHeight()-60);
	go.redimensionner(40.f,40.f);
	go.drawMe(fenetre);

}

bool Page::menuActif(sf::RenderWindow & fenetre) {
	if(back.estClique(fenetre) || go.estClique(fenetre) || map.estClique(fenetre))
		return true;
	else
		return false;
}

int Page::changerEcran(sf::RenderWindow &fenetre, int cour, int suiv, int prec) {

	if (go.estClique(fenetre))
	{
		go.resetTimer();
		return suiv;
	}
	else if (back.estClique(fenetre))
	{
		back.resetTimer();
		return prec;
	}
	else if (map.estClique(fenetre))
	{
		map.resetTimer();
		return MAPPEMONDE;
	}
	else
		return cour;
}

void Page::setAlpha(int valeur) {

	alpha = valeur;

	fontMusic.SetColor(sf::Color(255,255,255, valeur));
	fontNavigation.SetColor(sf::Color(255,255,255, valeur));
	map.SetAlpha(valeur);
	back.SetAlpha(valeur);
	go.SetAlpha(valeur);
	pause.SetAlpha(valeur);
	play.SetAlpha(valeur);
	mute.SetAlpha(valeur);
	noMute.SetAlpha(valeur);
	repeter.SetAlpha(valeur);
}

