/*
 * Page.h
 *
 *  Created on: 21 déc. 2009
 *      Author: sophie
 */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Bouton.h"

#ifndef PAGE_H_
#define PAGE_H_

class Page {
public:
	Page();
	virtual ~Page();
	void dessinerPage(sf::RenderWindow &fenetre); //A appeler dans chaque ecran d'histoire
	void dessinerFond(sf::RenderWindow &fenetre);
	void dessinerMusic(sf::RenderWindow &fenetre);
	//Fond + boutons precedents suivant + menu musique
private:
	Bouton back;
	Bouton go;
	Bouton pause;
	Bouton play;
	Bouton mute;
	Bouton menu;
};

#endif /* PAGE_H_ */
