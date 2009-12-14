/*
 * Bouton.h
 *
 *  Created on: 8 déc. 2009
 *      Author: sophie
 */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"
#ifndef BOUTON_H_
#define BOUTON_H_

class Bouton : public sf::Sprite
{
public:
	Bouton();
	void initBouton(const std::string &img1,const std::string &img2);
	void placer(float x,float y);
	void redimensionner(float x, float y);
	inline sf::Sprite getSprite() { return spriten; }
	inline void placerTexte(sf::String* texte) {texte->SetPosition(getPosX()+10.0,getPosY()+10.0); }
	inline float getPosX() { return spriten.GetPosition().x; }
	inline float getPosY() { return spriten.GetPosition().y; }
	inline float getTailleX() { return spriten.GetSize().x; }
	inline float getTailleY() { return spriten.GetSize().y; }
	bool estClique(sf::RenderWindow* fenetre);
	void drawMe(sf::RenderWindow* fenetre);

private:

	sf::Sprite spriten ;
	sf::Sprite spritef ;
};
#endif /* BOUTON_H_ */
