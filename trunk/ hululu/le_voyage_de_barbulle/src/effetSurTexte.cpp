/*
 * effetSurTexte.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: pirhoo
 */

// LIB SFM L/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "effetSurTexte.h"

// JOLIE OMBRE /////////////////////////
void ombreTexte(sf::String &src, sf::String &dest, sf::Color couleur, int xStep, int yStep)
{
	dest.SetText(src.GetText());
	dest.SetSize(src.GetSize());
	dest.SetFont(src.GetFont());
	dest.SetColor(couleur);
	dest.SetPosition(src.GetPosition().x+xStep,src.GetPosition().y+xStep);
}
