/*
 * GagneJeu.h
 *
 *  Created on: 27 janv. 2010
 *      Author: pollet
 */

#ifndef GAGNEJEU_H_
#define GAGNEJEU_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ecran.h"

class GagneJeu : public Ecran {
public:
	GagneJeu();
	virtual ~GagneJeu();
	virtual int run(sf::RenderWindow &fenetre);
private:
	unsigned int etape;
};

#endif /* GAGNEJEU_H_ */
