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
void BoutonMove::aBouger(sf::RenderWindow &fenetre) {
	if(estClique(fenetre)) {
		cout << "en mouvement = vrai" << endl;
		enMouvement=true;
	}
}
void BoutonMove::deplacer(sf::RenderWindow &fenetre, bool mouseMove, bool lache) {
	float posX = 0.0;
	float posY = 0.0;
	if(enMouvement==true && lache==true) {
			enMouvement=false;
			lache=false;
			cout << "bouton laché, en mouvement = faux" << endl;
		}

	if(enMouvement && mouseMove) {
		cout <<"le bouger" << endl;
		posX = sourisPositionX(fenetre) - decalageX;
		posY = sourisPositionY(fenetre) - decalageY;
		this->placer(posX, posY);
	}
	else
		cout <<"ne pas le bouger" << endl;
}


