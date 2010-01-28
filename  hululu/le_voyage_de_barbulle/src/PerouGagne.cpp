/*
 * PerouGagne.cpp
 *
 *  Created on: 28 janv. 2010
 *      Author: pollet
 */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

#include "PerouGagne.h"
#include "Page.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "DefineEcrans.h"
#include "PoleSud_Porte.h"

PerouGagne::PerouGagne() {
	// TODO Auto-generated constructor stub

}

PerouGagne::~PerouGagne() {
	// TODO Auto-generated destructor stub
}

int PerouGagne::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = PEROUGAGNE;
	return ecranSuivant;
}
