/*
 * JaponGagne.h
 *
 *  Created on: 27 janv. 2010
 *      Author: pollet
 */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

#ifndef JAPONGAGNE_H_
#define JAPONGAGNE_H_

class JaponGagne : public Ecran{
public:
	JaponGagne();
	virtual ~JaponGagne();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* JAPONGAGNE_H_ */
