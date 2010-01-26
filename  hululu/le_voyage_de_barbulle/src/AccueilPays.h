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
	void dessinerAccueil(sf::RenderWindow &fenetre,const std::string &imgDrapeau,const std::string &imgFond,const sf::Unicode::Text & ti, const sf::Unicode::Text & ssti,const sf::Color & colorTi,const sf::Color & colorSsti);
	void dessinerFond(sf::RenderWindow &fenetre,const std::string &imgFond);
	void dessinerDrapeau(sf::RenderWindow &fenetre,const std::string &imgDrapeau);
	void InfosPays(sf::RenderWindow &fenetre, const sf::Unicode::Text & titre,const sf::Unicode::Text & sstitre,const sf::Color colorTi,const sf::Color colorSsti);

private:
	sf::String titre;
	sf::String sstitre;
	sf::Sprite drapeau;
	sf::Sprite fond;
};

#endif /* ACCUEILPAYS_H_ */
