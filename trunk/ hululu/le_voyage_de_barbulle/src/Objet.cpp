/*
 * Objet.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#include "Objet.h"

Objet::Objet() {
	this->trouve=false;
	this->nom=" ";
}
Objet::~Objet() {
}


void Objet::initDessin(const std::string &img1) {
	image.SetImage(Ecran::MonManager.GetImage(img1));

}
void dessinerSurPorte() {

}
void Objet::dessinerObjet(sf::RenderWindow& fenetre) {
	fenetre.Draw(image) ;
}
