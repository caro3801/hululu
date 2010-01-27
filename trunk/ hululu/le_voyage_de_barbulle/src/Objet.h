/*
 * Objet.h
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#ifndef OBJET_H_
#define OBJET_H_

#include "BoutonMove.h"
#include <iostream>
using namespace std;

class Objet : public BoutonMove {
public:
	Objet();
	Objet(string nom);
	virtual ~Objet();

	inline string getNom() { return this->nom ; }
	inline void setNom(string) { this->nom=nom; }
	inline void setTrouve(bool trouve) { this->trouve=trouve;}
	inline bool getTrouve() { return this->trouve; } //objet trouvé ou non, oui a la fin d'un jeu réussi
	void dessinerDansSac(); //Pole : dessiner l'objet dans la case correspondante
	void emplacementPorte(); //Afficher l'emplacement de l'objet sur la porte
	void dessinerSurPorte(); //Dessiner l'image correspondant a l'objet (porte_weta, porte_lampion,..)
	void dessinerObjet(sf::RenderWindow& fenetre);
	void initDessin(const std::string &img1);
private:
	string nom; //weta, poncho, blason, lampion
	bool trouve; //objet trouvé ou non, initialisé a faux
	sf::Sprite image;
};

#endif /* OBJET_H_ */
