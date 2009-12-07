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

#include "Person2D.h"

Person2D::Person2D(const float widthCase, const float heightCase, const int stepLenght, const int nbCaseX, const int nbCaseY)
{
	this->widthCase = widthCase;
	this->heightCase = heightCase;

	this->nbCaseX = nbCaseX;
	this->nbCaseY = nbCaseY;

	this->activeLeftCase = 0;
	this->activeRightCase = 0;
	this->activeTopCase = 0;
	this->activeBottomCase = 0;

	this->stepLenght = stepLenght;
	this->timeSinceLastRefresh.Reset();
}

void Person2D::create(const float widthCase, const float heightCase, const int stepLenght, const int nbCaseX, const int nbCaseY)
{
	this->widthCase = widthCase;
	this->heightCase = heightCase;

	this->nbCaseX = nbCaseX;
	this->nbCaseY = nbCaseY;

	this->activeLeftCase = 0;
	this->activeRightCase = 0;
	this->activeTopCase = 0;
	this->activeBottomCase = 0;

	this->stepLenght = stepLenght;

}


void Person2D::initClip()
{
	this->activeLeftCase = 0;
	this->activeRightCase = 0;
	this->activeBottomCase = 0;
	this->activeTopCase = 0;

	this->SetSubRect(sf::IntRect(0, heightCase*2, widthCase, heightCase*3));
}

void Person2D::walk(moveDirection direction, float interval)
{
	if( (direction == LEFT) && ( readyToMove(interval) ) )
	{
		if(activeLeftCase < nbCaseX)
		{

			int px = activeLeftCase * widthCase, py;
			int lx, ly;

			// on deplace le sprite vers la gauche
			this->Move(-stepLenght / (nbCaseX+1), 0);

			// on change la partie visible du sprite
			if(activeLeftCase == nbCaseX -1) px = 0;
			else px += widthCase;
			lx = px + widthCase;

			py = heightCase * 1;
			ly = py + heightCase;

			activeLeftCase ++; // on passe a la case suivante
			this->SetSubRect(sf::IntRect(px, py, lx, ly));

			timeSinceLastRefresh.Reset();
		}
		else activeLeftCase = 0;

	}
	else if( (direction == RIGHT) && ( readyToMove(interval) ) )
	{
		if(activeRightCase < nbCaseX)
		{

			int px  = activeRightCase * widthCase, py;
			int lx, ly;

			// on deplace le sprite vers la droite
			this->Move(stepLenght/ (nbCaseX+1), 0);

			// on change la partie visible du sprite
			if(activeRightCase == nbCaseX -1) px = 0;
			else px += widthCase;
			lx = px + widthCase;

			py = heightCase * 2;
			ly = py + heightCase;

			activeRightCase ++; // on passe a la case suivante
			this->SetSubRect(sf::IntRect(px, py, lx, ly));

			timeSinceLastRefresh.Reset();
		}
		else activeRightCase = 0;

	}
	else if( (direction == BOTTOM) && ( readyToMove(interval) ) )
	{
		if(activeBottomCase < nbCaseX)
		{
			int px  = activeBottomCase * widthCase, py;
			int lx, ly;

			// on deplace le sprite vers le haut
			this->Move(0, stepLenght/(nbCaseY)+1);

			// on change la partie visible du sprite
			if(activeBottomCase == nbCaseX -1) px = 0;
			else px += widthCase;
			lx = px + widthCase;

			py = 0;
			ly = py + heightCase;

			activeBottomCase ++; // on passe a la case suivante
			this->SetSubRect(sf::IntRect(px, py, lx, ly));

			timeSinceLastRefresh.Reset();
		}
		else activeBottomCase = 0;

	}
	else if( (direction == TOP) && ( readyToMove(interval) ) )

	{
		if(activeTopCase < nbCaseX)
		{

			int px  = activeTopCase * widthCase, py;
			int lx, ly;

//			// on deplace le sprite vers le haut
			this->Move(0, stepLenght/(-(nbCaseY)+1));

//			// on change la partie visible du sprite
			if(activeTopCase == nbCaseX -1) px = 0;
			else px += widthCase;
			lx = px + widthCase;

			py = heightCase*3;
			ly = py + heightCase;

			activeTopCase++; // on passe a la case suivante
			this->SetSubRect(sf::IntRect(px, py, lx, ly));

			timeSinceLastRefresh.Reset();
		}
		else activeTopCase = 0;
	}
}

bool Person2D::inMoveTo(moveDirection direction)
{
	// retourne vrai si: le sprite et en mouvement vers la gauche (si activeLeftCase > 0)
	// 				ou : le sprite et en mouvement vers la droite (si activeRightCase > 0)
	//				ou : le sprite en mouvement vers le haut (si activeTopCase > 0)
	//				ou le sprite en mouvement vers le bas (si activeBottomCase > 0)
	return ( (direction == LEFT) && (getActiveLeftCase() > 0) ) || ( (direction == RIGHT) && (getActiveRightCase() > 0))
			|| ((direction == TOP) && (getActiveTopCase() > 0)) || ( (direction == BOTTOM) && (getActiveBottomCase() > 0));
}

bool Person2D::readyToMove(float interval)
{
	return ( (timeSinceLastRefresh.GetElapsedTime() * 1000) >= ( interval / (nbCaseX +1) ) );
}

