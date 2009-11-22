/*
 * Person2D.cpp
 *
 *  Created on: 21 nov. 2009
 *      Author: pirhoo
 */

#include "Person2D.h"
#include <iostream>
using namespace std;

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Person2D::Person2D(const float widthCase, const float heightCase, const int stepLenght, const int nbCaseX, const int nbCaseY)
{
	this->widthCase = widthCase;
	this->heightCase = heightCase;

	this->nbCaseX = nbCaseX;
	this->nbCaseY = nbCaseY;

	this->activeLeftCase = 0;
	this->activeRightCase = 0;


	this->stepLenght = stepLenght;
}

void Person2D::create(const float widthCase, const float heightCase, const int stepLenght, const int nbCaseX, const int nbCaseY)
{
	this->widthCase = widthCase;
	this->heightCase = heightCase;

	this->nbCaseX = nbCaseX;
	this->nbCaseY = nbCaseY;

	this->activeLeftCase = 0;
	this->activeRightCase = 0;

	this->stepLenght = stepLenght;

}


void Person2D::initClip()
{
	this->activeLeftCase = 0;
	this->activeRightCase = 0;

	this->SetSubRect(sf::IntRect(0, heightCase*2, widthCase, heightCase*3));
}

void Person2D::walkLeft(float interval)
{
	if(activeLeftCase < nbCaseX)
	{

		int px, py;
		int lx, ly;

		// on deplace le sprite de vers la gauche
		this->Move(-stepLenght / (nbCaseX+1), 0);

		// on change la partie visible du sprite
		if(activeLeftCase == nbCaseX -1) px = 0;
		else px += widthCase;
		lx = px + widthCase;

		py = heightCase * 1;
		ly = py + heightCase;

		activeLeftCase ++; // on passe a la case suivante
		this->SetSubRect(sf::IntRect(px, py, lx, ly));

		sleep( interval / (nbCaseX + 1) );

	}
	else activeLeftCase = 0;
}

void Person2D::walkRight(float interval)
{
	if(activeRightCase < nbCaseX)
	{

		int px, py;
		int lx, ly;

		// on deplace le sprite de vers la droite
		this->Move(stepLenght/ (nbCaseX+1), 0);

		// on change la partie visible du sprite
		if(activeRightCase == nbCaseX -1) px = 0;
		else px += widthCase;
		lx = px + widthCase;

		py = heightCase * 2;
		ly = py + heightCase;

		activeRightCase ++; // on passe a la case suivante
		this->SetSubRect(sf::IntRect(px, py, lx, ly));

		sleep( 0.5 );

	}
	else activeRightCase = 0;
}


