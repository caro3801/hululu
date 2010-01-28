/*
 * JeuPerou.h
 *
 *  Created on: 5 déc. 2009
 *      Author: talotte
 */

#ifndef JEUPEROU_H_
#define JEUPEROU_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Mapmonde.h"
#include "Bouton.h"
#include "BoutonMove.h"

class JeuPerou: public Ecran {
public:
	JeuPerou();
	virtual ~JeuPerou();
	inline bool lance() { return estLance; };
	void lancer();
	void placerFond(sf::RenderWindow &fenetre,sf::Image img);
	void creerPieces(sf::RenderWindow &fenetre,const std::string & piece1,const std::string & piece1_p,const std::string & piece2,const std::string & piece2_p,const std::string & piece3,const std::string & piece3_p, const std::string & piece5,const std::string & piece5_p);
	bool detectePiecePayes(sf::RenderWindow &fenetre, float posImgX,float posImgY);
	virtual int run(sf::RenderWindow &fenetre);
	bool autoriseBouger(Piece & obj);
	bool inZone(sf::RenderWindow &fenetre,Piece piece);
	int inZoneCalculeSomme(sf::RenderWindow &fenetre, int somme,Piece piece);

private:
	bool estLance;
	sf::Sprite fond;
	sf::Sprite piece1;
	sf::Sprite piece2;
	sf::Sprite piece3;
	sf::Sprite piece5;
	Piece val1_1;
	Piece val1_2;
	Piece val1_3;
	Piece val2_3;
	Piece val3_2;
	Piece val5_1;
	Piece pieceA;
	sf::Sprite inst;
	sf::String erreur;
};

#endif /* JEUPEROU_H_ */
