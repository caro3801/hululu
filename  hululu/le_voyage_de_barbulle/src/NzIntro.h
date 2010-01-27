/*
 * NzIntro.h
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */

#ifndef NZINTRO_H_
#define NZINTRO_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class NzIntro : public Ecran {
public:
	NzIntro();
	virtual ~NzIntro();
	virtual int run(sf::RenderWindow &fenetre);
};

#endif /* NZINTRO_H_ */
