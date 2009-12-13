/*
 * Italie.h
 *
 *  Created on: 12 déc. 2009
 *      Author: sof
 */

#ifndef ITALIE_H_
#define ITALIE_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class Italie : public Ecran {
public:
	Italie();
	virtual ~Italie();
	virtual int run(sf::RenderWindow &fenetre);

};

#endif /* ITALIE_H_ */
