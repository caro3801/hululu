/*
 * ItaliePresent.h
 *
 *  Created on: 26 janv. 2010
 *      Author: anthony
 */

#ifndef ITALIEPRESENT_H_
#define ITALIEPRESENT_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"
class ItaliePresent {
public:
	ItaliePresent();
	virtual ~ItaliePresent();
	virtual int run(sf::RenderWindow &fenetre);

};

#endif /* ITALIEPRESENT_H_ */
