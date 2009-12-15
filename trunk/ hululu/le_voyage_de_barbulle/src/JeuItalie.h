/*
 * JeuItalie.h
 *
 *  Created on: 15 déc. 2009
 *      Author: sophie
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

#ifndef JEUITALIE_H_
#define JEUITALIE_H_

class JeuItalie : public Ecran {

public:
	JeuItalie();
	virtual ~JeuItalie();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* JEUITALIE_H_ */
