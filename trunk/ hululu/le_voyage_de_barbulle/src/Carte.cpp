/*
 * Carte.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: pollet
 */

#include "Carte.h"
#include "Bouton.h"

Carte::Carte(sf::Image actif, sf::Image passif, int mois, int etat) {
	this->actif.initBouton(actif, actif);
	this->passif.initBouton(passif, passif);
	this->mois = mois;
	this->etat = 0;
}

Carte::~Carte() {
	// TODO Auto-generated destructor stub
}

Carte::changerEtat(int etat, Bouton bouton){

	if (bouton==actif){
		return etat=1;
	}
	else{
		return 0;
	}
}
