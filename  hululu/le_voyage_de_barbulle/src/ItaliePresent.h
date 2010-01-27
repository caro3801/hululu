/*
 * ItaliePresent.h
 *
 *  Created on: 26 janv. 2010
 *      Author: caroline
 */
#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#include "Page.h"
#include "DefineEcrans.h"
#ifndef ITALIEPRESENT_H_
#define ITALIEPRESENT_H_

class ItaliePresent : public Ecran{
public:
	ItaliePresent();
	virtual ~ItaliePresent();
	virtual int run(sf::RenderWindow &fenetre);
private:
	int etape;
};

#endif /* ITALIEPRESENT_H_ */
