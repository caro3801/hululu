/*
 * JeuJapon.h
 *
 *  Created on: 15 déc. 2009
 *      Author: pollet
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"


#ifndef JEUJAPON_H_
#define JEUJAPON_H_

class JeuJapon: public Ecran {
public:
	JeuJapon();
	virtual ~JeuJapon();
	virtual int run(sf::RenderWindow &fenetre);

protected:
	unsigned int _etape;
};

#endif /* JEUJAPON_H_ */
