/*
 * Intro.h
 *
 *  Created on: 27 janv. 2010
 *      Author: talotte
 */

#ifndef INTRO_H_
#define INTRO_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"


class Intro: public Ecran {
public:
	Intro();
	virtual ~Intro();
	virtual int run(sf::RenderWindow &fenetre);
private:
	unsigned int etape;
};

#endif /* INTRO_H_ */
