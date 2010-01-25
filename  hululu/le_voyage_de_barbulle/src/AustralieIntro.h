/*
 * AustralieIntro.h
 *
 *  Created on: 24 janv. 2010
 *      Author: pirhoo
 */

#ifndef AUSTRALIEINTRO_H_
#define AUSTRALIEINTRO_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"


class AustralieIntro: public Ecran {
public:
	AustralieIntro();
	virtual ~AustralieIntro();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* AUSTRALIEINTRO_H_ */
