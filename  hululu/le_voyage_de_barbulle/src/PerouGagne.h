/*
 * PerouGagne.h
 *
 *  Created on: 28 janv. 2010
 *      Author: pollet
 */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

#ifndef PEROUGAGNE_H_
#define PEROUGAGNE_H_

class PerouGagne : public Ecran{
public:
	PerouGagne();
	virtual ~PerouGagne();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* PEROUGAGNE_H_ */
