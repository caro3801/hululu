/*
 * ItalieGagne.h
 *
 *  Created on: 28 janv. 2010
 *      Author: anthony
 */

#ifndef ITALIEGAGNE_H_
#define ITALIEGAGNE_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"
#include "JeuItalie.h"

class ItalieGagne : public Ecran {
public:
	ItalieGagne();
	virtual ~ItalieGagne();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* ITALIEGAGNE_H_ */
