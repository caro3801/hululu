/*
 * Bouton.cpp
 *
 *  Created on: 8 déc. 2009
 *      Author: sophie
 */

#include "Bouton.h"

Bouton::Bouton() {
this->spriten=spriten;
this->spritef=spritef;
}

void Bouton::initBouton(sf::Image* img1, sf::Image* img2) {
	spriten.SetImage(*img1);
	spritef.SetImage(*img2);
	spriten.Resize(200,100);
	spritef.Resize(200,100);

}

void Bouton::setPosition(float x, float y) {
	spriten.SetPosition(x,y);
	spritef.SetPosition(x,y);
}

void Bouton::focus(sf::RenderWindow* fenetre) {
	if ((fenetre->GetInput().GetMouseX()<=(getPosX()+getTailleX()) && fenetre->GetInput().GetMouseX()>=getPosX())
			&& (fenetre->GetInput().GetMouseY()<=(getPosY()+getTailleY()) && fenetre->GetInput().GetMouseY()>=getPosY()))
	fenetre->Draw(spritef);
	else
	fenetre->Draw(spriten);
}

bool Bouton::estClique(sf::RenderWindow* fenetre) {
	return (fenetre->GetInput().IsMouseButtonDown(sf::Mouse::Left) && (fenetre->GetInput().GetMouseX()<=(getPosX()+getTailleX()) && fenetre->GetInput().GetMouseX()>=getPosX())
			&& (fenetre->GetInput().GetMouseY()<=(getPosY()+getTailleY()) && fenetre->GetInput().GetMouseY()>=getPosY()) ) ;
}

