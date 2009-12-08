/*
 * Bouton.h
 *
 *  Created on: 8 déc. 2009
 *      Author: sophie
 */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#ifndef BOUTON_H_
#define BOUTON_H_

class Bouton : public sf::Sprite
{
public:
	Bouton();
	void InitBouton(sf::Image img);
	sf::Sprite CreerSpriteN(sf::Sprite sprite1);
	sf::Sprite CreerSpriteF(sf::Sprite sprite2);
	void PlacerTexte(sf::String texte);
	int getPosX(sf::Sprite sprite1);
	int getPosY(sf::Sprite sprite1);
	int getTaille(sf::Sprite sprite1);
	int setPosY(sf::Sprite sprite2);
	int setPosX(sf::Sprite sprite2);

private:

	sf::Sprite sprite1 ;
	sf::Sprite sprite2 ;
};
#endif /* BOUTON_H_ */
