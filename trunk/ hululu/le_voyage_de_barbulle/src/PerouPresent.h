/*
 * PerouPresent.h
 *
 *  Created on: 27 janv. 2010
 *      Author: pollet
 */

#ifndef PEROUPRESENT_H_
#define PEROUPRESENT_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"


class PerouPresent : public Ecran {
public:
	PerouPresent();
	virtual ~PerouPresent();
	virtual int run(sf::RenderWindow &fenetre);

protected:
	unsigned int _etape;
};

#endif /* PEROUPRESENT_H_ */
