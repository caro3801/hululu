/*
 * Mapmonde.h
 *
 *  Created on: 10 déc. 2009
 *      Author: pirhoo
 */

#ifndef MAPMONDE_H_
#define MAPMONDE_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Ecran.h"

class Mapmonde: public Ecran
{
public:
	int virtual run(sf::RenderWindow &fenetre);
	int step(int step); // suit les instructions selon le numéro du step
						// retourne le prochain step à suivre, -1 sinon.
};

#endif /* MAPMONDE_H_ */
