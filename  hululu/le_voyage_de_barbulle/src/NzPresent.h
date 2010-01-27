/*
 * NzPresent.h
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */

#ifndef NZPRESENT_H_
#define NZPRESENT_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class NzPresent : public Ecran{
public:
	NzPresent();
	virtual ~NzPresent();
	virtual int run(sf::RenderWindow &fenetre);
protected:
	int _etape;
};

#endif /* NZPRESENT_H_ */
