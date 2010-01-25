/*
 * Carte.h
 *
 *  Created on: 25 janv. 2010
 *      Author: pollet
 */

#ifndef CARTE_H_
#define CARTE_H_
#include "Bouton.h"

class Carte {
public:

	Carte(sf::Image actif, sf::Image passif, int mois, int etat);
	virtual ~Carte();
	changerEtat(int etat, Bouton bouton);

private :
	Bouton passif;
	Bouton actif;
	int mois;
	int etat;
};

#endif /* CARTE_H_ */
