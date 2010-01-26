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
	AccueilPays(sf::RenderWindow &fenetre,const std::string &imgDrapeau,const std::string &imgFond,const sf::Unicode::Text & ti, const sf::Unicode::Text & ssti,const sf::Color & colorTi,const sf::Color & colorSsti);
	virtual ~AccueilPays();
	void initAccueil(sf::RenderWindow &fenetre);
	void dessinerAccueil(sf::RenderWindow &fenetre);
	void dessinerFond(sf::RenderWindow &fenetre);
	void dessinerDrapeau(sf::RenderWindow &fenetre);
	void InfosPays(sf::RenderWindow &fenetre);
	void mettrePolice(sf::Font& cursiveFont,float sizeT, float sizeS);
private:
	sf::String titre;
	sf::String sstitre;
	sf::Sprite drapeau;
	sf::Sprite fond;
};

#endif /* ACCUEILPAYS_H_ */
