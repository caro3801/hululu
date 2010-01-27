/*
 * Musique.h
 *
 *  Created on: 26 janv. 2010
 *      Author: pirhoo
 */

#ifndef MUSIQUE_H_
#define MUSIQUE_H_

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
using namespace std;

class Musique : public sf::Music {
public:
	Musique(string chemin);
	virtual ~Musique();
	void Lecture();

protected:
	string _chemin;
	bool _charge;
};

#endif /* MUSIQUE_H_ */
