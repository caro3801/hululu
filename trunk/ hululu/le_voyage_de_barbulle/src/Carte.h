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
	Carte(std::string actif, std::string passif, int mois, int numero, int etat);
	virtual ~Carte();
	void changerEtat();
	bool estClique(sf::RenderWindow & fenetre);
	Bouton & carteVisible();
	void placer(float x, float y);
	void redimensionner(float scale);


private :
	Bouton passif;
	Bouton actif;
	int mois;
	int numero;
	int etat;
};

#endif /* CARTE_H_ */
