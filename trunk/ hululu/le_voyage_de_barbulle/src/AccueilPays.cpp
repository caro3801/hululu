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
	this->fond = fond;
	this->titre = titre;
	this->sstitre =sstitre;
	this->drapeau = drapeau;
}

AccueilPays::~AccueilPays() {

}

void AccueilPays::dessinerAccueil(sf::RenderWindow &fenetre,const std::string &imgDrapeau,const std::string &imgFond,const sf::Unicode::Text & ti, const sf::Unicode::Text & ssti,const sf::Color & colorTi,const sf::Color & colorSsti) {
	//@param: fenetre,imageDrapeau, Image de fond, Titre, SousTitre, Couleur titre, couleur soustitre
	//les couleurs peuvent etre en RVB ou posseder un nom
	//affichage du fond d'accueil et du drapeau du pays concerné
	//affichage du texte : bienvenue dans la langue et ville visitée
	InfosPays(fenetre, ti, ssti,colorTi,colorSsti);
	dessinerFond(fenetre,imgFond);
	dessinerDrapeau(fenetre,imgDrapeau);

	fenetre.Draw(fond);
	fenetre.Draw(drapeau);
	fenetre.Draw(titre);
	fenetre.Draw(sstitre);
}

void AccueilPays::dessinerFond(sf::RenderWindow &fenetre,	const std::string &imgFond) {
	sf::Sprite SpriteFond(Ecran::MonManager.GetImage(imgFond));
	SpriteFond.SetPosition(0.f, 0.f);
	SpriteFond.Resize(fenetre.GetWidth(), fenetre.GetHeight());
}





void AccueilPays::dessinerDrapeau(sf::RenderWindow &fenetre,	const std::string &imgDrapeau) {
	drapeau.SetImage(Ecran::MonManager.GetImage(imgDrapeau));
	drapeau.Resize(300, 200);
	drapeau.SetPosition((fenetre.GetWidth()-drapeau.GetSize().x) / 2, (fenetre.GetHeight() - drapeau.GetSize().y)/2);

}

void AccueilPays::InfosPays(sf::RenderWindow &fenetre,	const sf::Unicode::Text & ti, const sf::Unicode::Text & ssti, const sf::Color colorTi,const sf::Color colorSsti) {
	// informations du Pays
	//pres : presentation du pays: bienvenue dans la langue et nom du pays ex: "benvenuto in italia"
	//li : nom de la ville visitée ex: "florence"
	sf::Font MyFont;
	if (!MyFont.LoadFromFile(
			"le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
		cerr << "Erreur lors du chargement de la police";

	titre.SetText(ti);
	titre.SetColor(colorTi);
	titre.SetSize(30.f);
	titre.SetPosition((fenetre.GetWidth() - titre.GetRect().Right)/2, fenetre.GetHeight()/ 4);

	sf::String OmbreTi(ti,	MyFont, 30.f); //ombre
	OmbreTi.Move(titre.GetRect().Right+1,titre.GetRect().Bottom+1);
	OmbreTi.SetColor(sf::Color::Black);

	sstitre.SetText(ssti);
	sstitre.SetColor(colorSsti);
	sstitre.SetSize(30.f);
	sstitre.SetPosition((fenetre.GetWidth() - sstitre.GetRect().Right)/2, titre.GetPosition().y+30);
	sf::String OmbreSsti(ssti,	MyFont, 30.f); //ombre
	OmbreSsti.Move(sstitre.GetRect().Right+1,sstitre.GetRect().Bottom+1);
	OmbreSsti.SetColor(sf::Color::Black);
}

