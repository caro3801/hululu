/*
 * PoleSud_Porte.h
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#ifndef POLESUD_PORTE_H_
#define POLESUD_PORTE_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"
#include "DefineEcrans.h"
#include "Objet.h"


class PoleSud_Porte : public Ecran {
public:

	PoleSud_Porte();
	virtual ~PoleSud_Porte();
	virtual int run(sf::RenderWindow &fenetre);
	static Objet blason;
	static Objet lampion;
	static Objet weta;
	static Objet poncho;
};

#endif /* POLESUD_PORTE_H_ */
