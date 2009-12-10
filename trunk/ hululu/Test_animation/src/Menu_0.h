/*
 * menu_0.h
 *
 *  Created on: 10 déc. 2009
 *      Author: pirhoo
 */

#ifndef MENU_0_H_
#define MENU_0_H_


// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Ecran.h"

// j'ai mis Menu_0 par convention pour marquer le début d'une "liste"
// qui plus est, on poura avoir d'autre "menu", sait-on jamais.
class Menu_0 : public Ecran
{

public:
    virtual int run (sf::RenderWindow &fenetre);

};

#endif /* MENU_0_H_ */
