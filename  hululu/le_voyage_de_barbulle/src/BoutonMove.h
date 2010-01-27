/*
 * BoutonMove.h
 *
 *  Created on: 22 janv. 2010
 *      Author: sophie
 *
 *  Classe héritée de Bouton permettant les memes fonctionnalités que celle-ci (objetCliquable)
 *  et également de le déplacer (= Drag & Drop)
 */


#include "Bouton.h"

#ifndef BOUTONMOVE_H_
#define BOUTONMOVE_H_

class BoutonMove : public Bouton {
public:
	BoutonMove();
	virtual ~BoutonMove();

	inline bool sourisDroitAppuye(sf::RenderWindow &fenetre) { return fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Right); }
	//renvoie vrai si le bouton droit de la souris est appuyé, faux sinon
	inline bool sourisGaucheAppuye(sf::RenderWindow & fenetre) { return fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left); }
	//renvoie vrai si le bouton gauche de la souris est appuyé, faux sinon

	inline float sourisPositionX(sf::RenderWindow &fenetre) { return fenetre.GetInput().GetMouseX(); }
	//renvoie la position de la souris en X dans la fenetre spécifiée
	inline float sourisPositionY(sf::RenderWindow &fenetre) { return fenetre.GetInput().GetMouseY(); }
	//renvoie la position de la souris en Y dans la fenetre spécifiée
	inline bool estLache(sf::RenderWindow &fenetre) {	return ((sourisGaucheAppuye(fenetre))); }
	bool enDeplacement(sf::RenderWindow &fenetre);
	//savoir si l'objet est en train d'etre déplacé-> retour: - vrai si l'objet est cliqué ET le bouton de la souris appuyé,
	//														  - faux sinon
	void decalageSouris(float x, float y);
	//Positionner l'objet par rapport a la souris pendant le déplacement: param: la valeur en X et Y du décalage souhaité
	// (sinon par défaut l'objet aura son coin supérieur gauche a la place de la souris)
	void setABouger(bool bouger);
	bool estBougeable();
	void deplacer(sf::RenderWindow &fenetre, bool mouseMove, bool lache);
	//déplacer l'objet a ses nouvelles coordonnées : déplacer l'objet si enDeplacement et la souris bouge dans la fenetre, ne rien faire sinon
	//nouvelles coordonnées : sourisPosition(X,Y) + posSouris(X,Y) (pour le décalage)
	void plusBouger(bool arret) ;

private:
	float decalageY; //le décalage en Y de l'objet par rapport a la souris (0 par défaut)
	float decalageX; //le décalage en X de l'objet par rapport a la souris (0 par défaut)
	bool enMouvement;
	bool aBouger;
};

#endif /* BOUTONMOVE_H_ */
