/*
 * Australie.h
 *
 *  Created on: 15 déc. 2009
 *      Author: pirhoo
 */

#ifndef AUSTRALIE_H_
#define AUSTRALIE_H_

#include "Ecran.h"

class Australie : public Ecran
{
public:
	Australie();
	int run(sf::RenderWindow &fenetre); // retourne le numéro du prochain écran à afficher
};

#endif /* AUSTRALIE_H_ */
