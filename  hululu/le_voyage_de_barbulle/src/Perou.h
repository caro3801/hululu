/*
 * Perou.h
 *
 *  Created on: 15 déc. 2009
 *      Author: talotte&Mollier
 */

#ifndef PEROU_H_
#define PEROU_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"
#include "JeuPerou.h"

class Perou: public Ecran {
public:
	Perou();
	virtual ~Perou();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* PEROU_H_ */
