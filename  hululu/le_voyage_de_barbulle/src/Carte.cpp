/*
 * Carte.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: pollet
 */

#include "Carte.h"
#include "Bouton.h"

Carte::Carte(std::string actif, std::string passif, int mois, int numero, int etat) {
	this->actif.initBouton(actif, actif);
	this->passif.initBouton(passif, passif);
	this->mois = mois;
	this->numero = numero;
	this->etat = 1;
	//actif 1 // passif 0
}

void Carte::create(std::string actif, std::string passif, int mois, int numero, int etat) {
	this->actif.initBouton(actif, actif);
	this->passif.initBouton(passif, passif);
	this->mois = mois;
	this->numero = numero;
	this->etat = 1;
	//actif 1 // passif 0
}

Carte::~Carte() {
	// TODO Auto-generated destructor stub
}

void Carte::changerEtat() {

	if (etat)
		etat=0;
	else
		etat=1;
}

bool Carte::estClique(sf::RenderWindow & fenetre) {
	return ( actif.estClique(fenetre) || passif.estClique(fenetre) );
}

Bouton & Carte::carteVisible() {
	if(etat)
		return actif;
	else
		return passif;
}

void Carte::placer(float x, float y) {
	actif.placer(x,y);
	passif.placer(x,y);
}

void Carte::redimensionner(float scale) {
	actif.redimensionner(scale);
	passif.redimensionner(scale);
}



