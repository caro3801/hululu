/*
 * AccueilPays.cpp
 *
 *  Created on: 14 déc. 2009
 *      Author: caroline
 */

#include "AccueilPays.h"

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

AccueilPays::AccueilPays(sf::RenderWindow &fenetre,const std::string &imgDrapeau,const std::string &imgFond,const sf::Unicode::Text & ti, const sf::Unicode::Text & ssti,const sf::Color & colorTi,const sf::Color & colorSsti) {
	this->fond.SetImage(Ecran::MonManager.GetImage(imgFond));
	this->titre.SetText(ti);
	this->titre.SetColor(colorTi);
	this->sstitre.SetText(ssti);
	this->titre.SetColor(colorSsti);
	this->drapeau.SetImage(Ecran::MonManager.GetImage(imgDrapeau));
}

AccueilPays::AccueilPays() {

}

AccueilPays::~AccueilPays() {

}


void AccueilPays::initAccueil(sf::RenderWindow &fenetre)
{	//@param: fenetre,imageDrapeau, Image de fond, Titre, SousTitre, Couleur titre, couleur soustitre
	//les couleurs peuvent etre en RVB ou posseder un nom
	dessinerFond(fenetre);
	dessinerDrapeau(fenetre);
	InfosPays(fenetre);


}


void AccueilPays::dessinerAccueil(sf::RenderWindow &fenetre) {

	//affichage du fond d'accueil et du drapeau du pays concerné
	//affichage du texte : bienvenue dans la langue et ville visitée
	fenetre.Draw(fond);
	fenetre.Draw(drapeau);
	fenetre.Draw(titre);
	fenetre.Draw(sstitre);

}

void AccueilPays::dessinerFond(sf::RenderWindow &fenetre) {
	fond.SetPosition(0.f, 0.f);
	fond.Resize(fenetre.GetWidth(), fenetre.GetHeight());
}



void AccueilPays::dessinerDrapeau(sf::RenderWindow &fenetre) {
	drapeau.Resize(300, 200);
	drapeau.SetPosition((fenetre.GetWidth()-drapeau.GetSize().x) / 2, (fenetre.GetHeight() - drapeau.GetSize().y)/2);
}
void AccueilPays::mettrePolice(sf::Font& cursiveFont, float sizeT, float sizeS) {
	titre.SetFont(cursiveFont);
	titre.SetSize(sizeT);
	sstitre.SetFont(cursiveFont);
	sstitre.SetSize(sizeS);
}
void AccueilPays::InfosPays(sf::RenderWindow &fenetre) {
	// informations du Pays
	//pres : presentation du pays: bienvenue dans la langue et nom du pays ex: "benvenuto in italia"
	//li : nom de la ville visitée ex: "florence"
float center=sstitre.GetRect().Right/2;

	sstitre.SetPosition(fenetre.GetWidth()/2-center, drapeau.GetPosition().y-60);
	titre.SetPosition(fenetre.GetWidth()/2 - titre.GetRect().Right/2, sstitre.GetPosition().y-60);


}

