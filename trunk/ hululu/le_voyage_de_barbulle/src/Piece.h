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
#include "BoutonMove.h"


class Piece: public BoutonMove{
public:
	Piece();
	virtual ~Piece();
	int getValeur();
	void setValeur(float val);
private:
	int valeur;
};

#endif /* PIECE_H_ */
