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


void Objet::setPlace(bool placeObj) {
	this->place=placeObj;
}

bool Objet::estPlace() {
	return place;
}

void dessinerSurPorte() {

}
