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

void Bouton::initBouton(const std::string &img1, const std::string &img2) {
	spriten.SetImage(Ecran::MonManager.GetImage(img1));
	spritef.SetImage(Ecran::MonManager.GetImage(img2));


}
void Bouton::redimensionner(float x, float y) {
	spriten.Resize(x,y);
	spritef.Resize(x,y);
}

void Bouton::placer(float x, float y) {
	spriten.SetPosition(x,y);
	spritef.SetPosition(x,y);
}

void Bouton::drawMe(sf::RenderWindow* fenetre) {
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

