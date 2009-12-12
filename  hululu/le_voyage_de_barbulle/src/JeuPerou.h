/*
 * JeuPerou.h
 *
 *  Created on: 5 déc. 2009
 *      Author: talotte
 */

#ifndef JEUPEROU_H_
#define JEUPEROU_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class JeuPerou {
public:
	JeuPerou();
	inline bool lance() { return estLance; };
	void lancer();
	void placerFond(sf::RenderWindow* fenetre,sf::Image img);

private:
	bool estLance;
	sf::Sprite fond;
};

#endif /* JEUPEROU_H_ */
