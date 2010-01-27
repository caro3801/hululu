/*
 * AustraliePresent.h
 *
 *  Created on: 25 janv. 2010
 *      Author: pirhoo
 */

#ifndef AUSTRALIEPRESENT_H_
#define AUSTRALIEPRESENT_H_


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"


class AustraliePresent : public Ecran {
public:
	AustraliePresent();
	virtual ~AustraliePresent();
	virtual int run(sf::RenderWindow &fenetre);
protected:
	unsigned int _etape;
};

#endif /* AUSTRALIEPRESENT_H_ */
