/*
 * AccueilPays.h
 *
 *  Created on: 14 déc. 2009
 *      Author: caroline
 */


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Ecran.h"

#include <iostream>
using namespace std;
#ifndef ACCUEILPAYS_H_
#define ACCUEILPAYS_H_

class AccueilPays {
public:
	AccueilPays();
	virtual ~AccueilPays();
	void dessiner(sf::RenderWindow &fenetre,const std::string &imgDrapeau);
	void InfosPays(sf::RenderWindow &fenetre, const sf::Unicode::Text & pres,const sf::Unicode::Text & li);

private:
	sf::String present;
	sf::String lieu;
	sf::Sprite drapeau;
};

#endif /* ACCUEILPAYS_H_ */
