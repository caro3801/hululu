/*
 * Japon.h
 *
 *  Created on: 15 déc. 2009
 *      Author: pollet
 */

#ifndef JAPON_H_
#define JAPON_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class Japon : public Ecran {
public:
	Japon();
	virtual ~Japon();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* JAPON_H_ */
