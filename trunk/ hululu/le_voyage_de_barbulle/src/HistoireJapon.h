/*
 * Japon.h
 *
 *  Created on: 15 déc. 2009
 *      Author: pollet
 */

#ifndef HISTOIREJAPON_H_
#define HISTOIREJAPON_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class HistoireJapon : public Ecran {
public:
	HistoireJapon();
	virtual ~HistoireJapon();
	virtual int run(sf::RenderWindow &fenetre);

protected:
	unsigned int _etape;
};

#endif /* JAPON_H_ */
