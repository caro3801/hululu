/*
 * Piece.cpp
 *
 *  Created on: 10 déc. 2009
 *      Author: talotte
 */

#include "Piece.h"
#include "ImageManager.h"
#include <iostream>
using namespace std;
Piece::Piece() {
valeur = 1;
}

Piece:: ~Piece()
{
}

void Piece::initPiece(sf::RenderWindow* fenetre,const std::string &img)
{
	monnaie.SetImage((Ecran::MonManager.GetImage(img)));
	//monnaie.SetPosition(0.f,0.f);
	fenetre->Draw(monnaie);
}

void Piece::placerPiece(float x, float y)
{
	monnaie.SetPosition(x,y);
}

int Piece::getValeur()
{
	return valeur;
}
void Piece::setValeur(float val)
{
	valeur=val;
}

int Piece::run(sf::RenderWindow &fenetre)
{
	return 0;
}

void Piece::deplacerPiece(sf::RenderWindow* fenetre,float x, float y)
{
	//sf::Event event;
	//bool clicked(false);
	//float mouseX(0.f), mouseY(0.f);
	if(fenetre->GetInput().IsMouseButtonDown(sf::Mouse::Left))
	{
		//if(fenetre->GetInput())
		if(monnaie.GetSubRect().Contains(fenetre->GetInput().GetMouseX(),fenetre->GetInput().GetMouseY()))
		{
			cout<<"ok";
		}
	}
//solution de tom pour une piece:
	//if (app.GetInput().IsMouseButtonDown(sf::Mouse::Left) && Input->GetMouseX() >= pospiece.x && Input->GetMouseX() <= pospiece.x + largeurpiece && Input->GetMouseY() >= pospiece.y && Input->GetMouseY() <= pospiece.y + hauteurpiece)
	//solution de tom pour plusieures pieces:
//	if (app.GetInput().IsMouseButtonDown(sf::Mouse::Left)
//	{
//	      for (int i = 0; i < nbpiece; i++)
//	      {
//	         if (Input->GetMouseX() >= pospiece[i].x && Input->GetMouseX() <= pospiece[i].x + largeurpiece && Input->GetMouseY() >= pospiece[i].y && Input->GetMouseY() <= pospiece[i].y + hauteurpiece)
//
//	         .... Ce qu'il doit se passer
//
//	      }
//	}
}
