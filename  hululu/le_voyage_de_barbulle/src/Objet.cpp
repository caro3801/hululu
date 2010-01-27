/*
 * Objet.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#include "Objet.h"

Objet::Objet() {
	this->trouve=false;
	this->place=false;
	this->nom=" ";
}
Objet::~Objet() {
}


<<<<<<< .mine
void Objet::setPlace(bool placeObj) {
	this->place=placeObj;
}

bool Objet::estPlace() {
	return place;
}
=======
void Objet::initDessin(const std::string &img1) {
	image.SetImage(Ecran::MonManager.GetImage(img1));

}
void Objet::placer(float x, float y) {
	image.SetPosition(x,y);
>>>>>>> .r173

}
void dessinerSurPorte() {

}
void Objet::dessinerObjet(sf::RenderWindow& fenetre) {
	fenetre.Draw(image) ;
}
