/*
 * BoutonMove.cpp
 *
 *  Created on: 22 janv. 2010
 *      Author: sophie
 */

#include "BoutonMove.h"

BoutonMove::BoutonMove() : Bouton() {
	this->decalageY=0;
	this->decalageX=0;
}

BoutonMove::~BoutonMove() {
}

bool BoutonMove::enDeplacement(sf::RenderWindow &fenetre) {
	//a modifier si jamais on veut que ce soit un autre bouton que clicGauche
	return ( estClique(fenetre) || sourisGaucheAppuye(fenetre) );

}

void BoutonMove::decalageSouris(float x, float y) {
	this->decalageX=x;
	this->decalageY=y;
}

void BoutonMove::deplacer(sf::RenderWindow &fenetre, bool mouseMove) {
	if(enDeplacement(fenetre) && mouseMove) {
		float posX = sourisPositionX(fenetre) - decalageX;
		float posY = sourisPositionY(fenetre) - decalageY;
		this->placer(posX, posY);
	}
}


