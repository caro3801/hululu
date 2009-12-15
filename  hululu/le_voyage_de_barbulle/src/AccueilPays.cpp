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

AccueilPays::AccueilPays() {
	this->present = present;
	this->lieu = lieu;
	this->drapeau = drapeau;
}

AccueilPays::~AccueilPays() {

}

void AccueilPays::dessiner(sf::RenderWindow &fenetre,
		const std::string &imgDrapeau) {
	//affichage du fond d'accueil et du drapeau du pays concerné
	//affichage du texte : bienvenue dasn la langue et ville visitée
	sf::Sprite SpriteAccueil(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/accueil/fondaccueil.png"));
	SpriteAccueil.SetPosition(0.f, 0.f);
	SpriteAccueil.Resize(fenetre.GetWidth(), fenetre.GetHeight());
	fenetre.Clear(sf::Color(255, 255, 255));
	fenetre.Draw(SpriteAccueil);
	drapeau.SetImage(Ecran::MonManager.GetImage(imgDrapeau));
	drapeau.Resize(300, 200);
	drapeau.SetPosition((fenetre.GetWidth() / 2 - 150), (fenetre.GetHeight()	/ 2 - 100));
	fenetre.Draw(drapeau);
	fenetre.Draw(present);
	fenetre.Draw(lieu);
}

void AccueilPays::InfosPays(sf::RenderWindow &fenetre,	const sf::Unicode::Text & pres, const sf::Unicode::Text & li) {
	// informations du Pays
	//pres : presentation du pays: bienvenue dans la langue et nom du pays ex: "benvenuto in italia"
	//li : nom de la ville visitée ex: "florence"
	sf::Vector2f centre;
	present.SetText(pres);
	present.SetColor(sf::Color::Red);
	present.SetSize(30.f);
	present.SetPosition((fenetre.GetWidth()/2-150), (fenetre.GetHeight() / 4));

	lieu.SetText(li);
	lieu.SetColor(sf::Color::Red);
	lieu.SetSize(20.f);
	lieu.SetPosition((fenetre.GetWidth() / 2-150), (fenetre.GetHeight() / 3));
}


