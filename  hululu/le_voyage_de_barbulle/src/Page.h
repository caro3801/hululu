/*
 * Page.h
 *
 *  Created on: 21 déc. 2009
 *      Author: sophie
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Bouton.h"

#ifndef PAGE_H_
#define PAGE_H_

class Page {
public:
	Page();
	virtual ~Page();
	void dessinerPage(sf::RenderWindow &fenetre); //A appeler dans chaque Ecran pour dessiner toute la page (page + music)
	void dessinerFond(sf::RenderWindow &fenetre);
	void dessinerMusic(sf::RenderWindow &fenetre);
	bool menuActif(sf::RenderWindow &fenetre); //Vérifie que le clic est sur un élément du menu (Sécurité)
	int  changerEcran(sf::RenderWindow &fenetre,int cour, int suiv, int prec);
    inline Bouton getPlay() {return play; }
    inline bool getGoClique(sf::RenderWindow &fenetre) {return go.estClique(fenetre); }
    inline bool getBackClique(sf::RenderWindow &fenetre) {return back.estClique(fenetre); }
    inline bool getMapClique(sf::RenderWindow &fenetre) {return map.estClique(fenetre); }
    inline bool getRepeterClique(sf::RenderWindow &fenetre) {return repeter.estClique(fenetre); }
    inline Bouton getGo() {return go; }
    inline Bouton getBack() {return back; }
    inline Bouton getMap() {return map; }
    inline Bouton getRepeter() {return repeter; }
	//A appeler pour passer d'un écran a l'autre lorsqu'on clique sur les fleches
	//Donner en parametre le numéro de l'ecran courant, celui du suivant et celui d'avant
	inline bool getPlaying() { return playing; }
	inline void triggerPlaying() { playing = (playing) ? false : true; }
	inline bool getMuting() { return muting; }
	inline void triggerMuting() { muting = (muting) ? false : true; }
	void setAlpha(int valeur);
	inline int getAlpha() { return alpha;}

private:
	sf::Sprite fontNavigation;

	Bouton map; //Retourner en arriere
	Bouton back; //Retourner en arriere
	Bouton go; //Aller a l'ecran suivant


	sf::Sprite fontMusic;
	sf::Sprite fontAide;

	Bouton pause; //Pause et Play pour lire les instructions
	Bouton play; //Fonctionnent ensembles ( play || pause)
	Bouton mute; //Music pour la musique de fond et Mute pour l'enlever
	Bouton noMute; // (noMute || mute)
	Bouton repeter; // repeter les instructions

	Bouton aide; // repeter les instructions
	Bouton fermer; // repeter les instructions

	bool playing;
	bool muting;

	int alpha;
};

#endif /* PAGE_H_ */
