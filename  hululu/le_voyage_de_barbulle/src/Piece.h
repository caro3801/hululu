/*
 * Piece.h
 *
 *  Created on: 10 déc. 2009
 *      Author: talotte
 */

#ifndef PIECE_H_
#define PIECE_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Mapmonde.h"



class Piece: public Ecran{
public:
	Piece();
	virtual ~Piece();
	void initPiece(sf::RenderWindow* fenetre,const std::string &img);
	void placerPiece(float x, float y);
	int getValeur();
	void setValeur(float val);
	virtual int run(sf::RenderWindow &fenetre);
	void deplacerPiece(sf::RenderWindow* fenetre,float x, float y);
private:
	sf::Sprite monnaie;
	int valeur;
};

#endif /* PIECE_H_ */
