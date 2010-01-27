/*
 * ItalieMusee.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: caroline
 */


#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ItalieMusee.h"
#include "Page.h"
#include "DefineEcrans.h"
ItalieMusee::ItalieMusee() {
	// TODO Auto-generated constructor stub

}

ItalieMusee::~ItalieMusee() {
	// TODO Auto-generated destructor stub
}
int ItalieMusee::run(sf::RenderWindow &fenetre){
	int ecranSuivant = ITALIEMUSEE;
Page pays;
	if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
		ecranSuivant=pays.changerEcran(fenetre,ITALIEMUSEE,JEU_ITALIE,ITALIEPRESENT) ;
	return ecranSuivant;

}
