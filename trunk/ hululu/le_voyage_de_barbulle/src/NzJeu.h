/*
 * NzJeu.h
 *
 *  Created on: 27 janv. 2010
 *      Author: pirhoo
 */

#ifndef NZJEU_H_
#define NZJEU_H_


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

class NzJeu : public Ecran{
public:
	NzJeu();
	virtual ~NzJeu();
	inline int run(sf::RenderWindow &fenetre) { return 0; }
};

#endif /* NZJEU_H_ */
