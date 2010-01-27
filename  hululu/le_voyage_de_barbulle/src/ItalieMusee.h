/*
 * ItalieMusee.h
 *
 *  Created on: 27 janv. 2010
 *      Author: caroline
 */

#ifndef ITALIEMUSEE_H_
#define ITALIEMUSEE_H_


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"


class ItalieMusee :public Ecran{
public:
	ItalieMusee();
	virtual ~ItalieMusee();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* ITALIEMUSEE_H_ */
