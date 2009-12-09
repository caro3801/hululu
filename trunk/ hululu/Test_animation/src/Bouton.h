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
	void initBouton(sf::Image img1, sf::Image img2);
	void setPosition(float x,float y);
	inline void placerTexte(sf::String texte) {	texte.SetPosition(getPosY(),getPosX()); }
	inline float getPosX() { return spriten.GetPosition().x; }
	inline float getPosY() { return spriten.GetPosition().y; }
	inline float getTailleX() { return spriten.GetSize().x; }
	inline float getTailleY() { return spriten.GetSize().y; }
	bool estClique(sf::RenderWindow* fenetre);
	void focus(sf::RenderWindow* fenetre);

private:

	sf::Sprite spriten ;
	sf::Sprite spritef ;
};
#endif /* BOUTON_H_ */
