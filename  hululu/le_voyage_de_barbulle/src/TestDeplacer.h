/*
 * TestDeplacer.h
 *
 *  Created on: 21 janv. 2010
 *      Author: sophie
 */


#ifndef TESTDEPLACER_H_
#define TESTDEPLACER_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class TestDeplacer: public Ecran {
public:
	TestDeplacer();
	virtual ~TestDeplacer();
	virtual int run(sf::RenderWindow &fenetre);

};

#endif /* TESTDEPLACER_H_ */
