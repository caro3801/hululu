/*
 * ecran.h
 *
 *  Created on: 10 déc. 2009
 *      Author: pirhoo
 * Description: CLASSE ABSTRAITE, mère de tous les écrans
 */

#ifndef ECRAN_H_
#define ECRAN_H_


// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ecran
{
public:
	virtual int run (sf::RenderWindow &fenetre) = 0;
	// serie d'instructions propres à chaque écran
	// pas d'implémentation ici
};

#endif /* ECRAN_H_ */
