/*
 * BoutonMove.cpp
 *
 *  Created on: 22 janv. 2010
 *      Author: sophie
 */
#include <iostream>
using namespace std;
#include "BoutonMove.h"

BoutonMove::BoutonMove() : Bouton() {
	this->decalageY=0;
	this->decalageX=0;
	this->enMouvement=false;
	this->aBouger=false;
}

BoutonMove::~BoutonMove() {
}

bool BoutonMove::enDeplacement(sf::RenderWindow &fenetre) {
	//a modifier si jamais onweta veut que ce soit un autre bouton que clicGauche
	return enMouvement;
}

void BoutonMove::decalageSouris(float x, float y) {
	this->decalageX=x;
	this->decalageY=y;
}
void BoutonMove::setABouger(bool bouger) {
	this->aBouger=bouger;
}
bool BoutonMove::estBougeable() {
	return this->aBouger ;
}
void BoutonMove::deplacer(sf::RenderWindow &fenetre, bool mouseMove, bool lache) {
	float posX = 0.0;
	float posY = 0.0;
	bool bouger=true;
	if(estBougeable() && sourisGaucheAppuye(fenetre)) {
		enMouvement=true;
	}
	else if(enMouvement==true && lache==true) {
		enMouvement=false;
		lache=false;
		bouger=false;
		setABouger(bouger);
	}

	if(enMouvement && mouseMove) {
		posX = sourisPositionX(fenetre) - decalageX;
		posY = sourisPositionY(fenetre) - decalageY;
		this->placer(posX, posY);
	}
}
void BoutonMove::plusBouger(bool arret) {
	//bool arret=true;
	this->enMouvement=false;
}


