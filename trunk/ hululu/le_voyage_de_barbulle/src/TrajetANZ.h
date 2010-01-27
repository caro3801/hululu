/*
 * TrajetANZ.h
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */

#ifndef TRAJETANZ_H_
#define TRAJETANZ_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class TrajetANZ : public Ecran {
public:
	TrajetANZ();
	virtual ~TrajetANZ();
	virtual int run(sf::RenderWindow &fenetre);

};

#endif /* TRAJETANZ_H_ */
