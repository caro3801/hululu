/*
 * JeuItalie.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: sophie
 */
#include <iostream>
#include <sstream>
using namespace std;

#include "JeuItalie.h"
#include "Page.h"
#include "Bouton.h"
#include "PoleSud_Porte.h"
#include "Objet.h"
#include "DefineEcrans.h"
#include "effetSurTexte.h"
JeuItalie::JeuItalie() {
}

JeuItalie::~JeuItalie() {
}

bool JeuItalie::erreur1Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon
float posImgX=imgEResize.GetPosition().x;
float posImgY=imgEResize.GetPosition().y;
float posX = fenetre.GetInput().GetMouseX(); //On récupere la position de la souris lors du clic
float posY = fenetre.GetInput().GetMouseY();

	if 		((posX >= (posImgX+110*rapX))		&& (posX<= (120*rapX  + posImgX))
			&& (posY>=(147*rapY + posImgY))
			&& (posY<=(162*rapY + posImgY)))

		//Si position souris entre 113 + posImgX et 122 +posImgX en X et entre 154 + posImgY et 160 + posImgY en Y
		// Soit si la position de la souris est dans le cercle de l'erreur
		return true; //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}
//erreur2=	54, 266
//erreur3=	92,317
//erreur4=	314,114
//erreur5=	390, 145
//erreur6=	370,513
//erreur7=	119,396

bool JeuItalie::erreur2Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize) {
	//Retourne Vrai si l'erreur 2 est cliquée, faux sinon
	float posImgX=imgEResize.GetPosition().x;
	float posImgY=imgEResize.GetPosition().y;
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (((posX >= (30.f*rapX + posImgX)) && (posX <= (46.f*rapX + posImgX)) && (posY
			>= (270.f*rapY + posImgY)) && (posY <= (278.f*rapY + posImgY))) || ((posX
			>= (42.f*rapX + posImgX)) && (posX <= (60.f*rapX + posImgX)) && (posY
			>= (260.f*rapY + posImgY)) && (posY <= (270.f*rapY + posImgY))))

		return true; //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}


bool JeuItalie::erreur3Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize) {
	//Retourne Vrai si l'erreur 3 est cliquée, faux sinon
	float posImgX=imgEResize.GetPosition().x;
	float posImgY=imgEResize.GetPosition().y;
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (82.f*rapX + posImgX)) && (posX <= (104.f*rapX + posImgX)) && (posY
			>= (310.f*rapY + posImgY)) && (posY <= (330.f*rapY + posImgY)))
		return true;
	else
		return false;
}

bool JeuItalie::erreur4Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize) {
	//Retourne Vrai si l'erreur 4 est cliquée, faux sinon
	float posImgX=imgEResize.GetPosition().x;
	float posImgY=imgEResize.GetPosition().y;
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (308.f*rapX + posImgX)) && (posX <= (322.f*rapX + posImgX)) && (posY
			>= (105.f*rapY + posImgY)) && (posY <= (126.f*rapY + posImgY)))
		return true;
	else
		return false;
}

bool JeuItalie::erreur5Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon
	float posImgX=imgEResize.GetPosition().x;
	float posImgY=imgEResize.GetPosition().y;
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (((posX >= (377.f*rapX + posImgX)) && (posX <= (386.f*rapX + posImgX)) && (posY
			>= (162.f*rapY + posImgY)) && (posY <= (180.f*rapY + posImgY))) || ((posX
			>= (384.f*rapX + posImgX)) && (posX <= (392.f*rapX + posImgX)) && (posY
			>= (142.f*rapY + posImgY)) && (posY <= (164.f*rapY + posImgY))) || ((posX
			>= (390.f*rapX + posImgX)) && (posX <= (398.f*rapX + posImgX)) && (posY
			>= (124.f*rapY + posImgY)) && (posY <= (144.f*rapY + posImgY))) || ((posX
			>= (397.f*rapX + posImgX)) && (posX <= (405.f*rapX + posImgX)) && (posY
			>= (107.f*rapY + posImgY)) && (posY <= (126.f*rapY + posImgY)))){
				return true;
	}
		 //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}

bool JeuItalie::erreur6Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon
	float posImgX=imgEResize.GetPosition().x;
	float posImgY=imgEResize.GetPosition().y;
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (361.f*rapX + posImgX)) && (posX <= (377.f*rapX + posImgX)) && (posY
			>= (510*rapY + posImgY)) && (posY <= (522*rapY + posImgY)))
		return true; //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}

bool JeuItalie::erreur7Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon
	float posImgX=imgEResize.GetPosition().x;
	float posImgY=imgEResize.GetPosition().y;
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (((posX >= (111.f*rapX + posImgX)) && (posX <= (118.f*rapX + posImgX)) && (posY
			>= (395*rapY + posImgY)) && (posY <= (408*rapY + posImgY))) || ((posX
			>= (114.f*rapX + posImgX)) && (posX <= (122.f*rapX + posImgX)) && (posY
			>= (387*rapY + posImgY)) && (posY <= (397*rapY + posImgY))))
		return true; //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}

void JeuItalie::dessineMarque(sf::RenderWindow &fenetre, bool er1, bool er2,
		bool er3, bool er4, bool er5, bool er6, bool er7, float posImgX,
		float posImgY) {
	//Dessine les erreurs si celles-ci ont été trouvées

	if (er1) {
		sf::Sprite er1;
		er1.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er1.png"));
		er1.Resize(
				2.5 * er1.GetSize().x * er1.GetSize().x / fenetre.GetWidth(),
				1.25 * er1.GetSize().y * er1.GetSize().y / fenetre.GetHeight());

		er1.SetPosition(posImgX, posImgY);
		fenetre.Draw(er1);
	}
	if (er2) {
		sf::Sprite er2;
		er2.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er2.png"));
		er2.Resize(
				2.5 * er2.GetSize().x * er2.GetSize().x / fenetre.GetWidth(),
				1.25 * er2.GetSize().y * er2.GetSize().y / fenetre.GetHeight());
		er2.SetPosition(posImgX, posImgY);
		fenetre.Draw(er2);
	}
	if (er3) {
		sf::Sprite er3;
		er3.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er3.png"));
		er3.Resize(
				2.5 * er3.GetSize().x * er3.GetSize().x / fenetre.GetWidth(),
				1.25 * er3.GetSize().y * er3.GetSize().y / fenetre.GetHeight());
		er3.SetPosition(posImgX, posImgY);
		fenetre.Draw(er3);
	}
	if (er4) {
		sf::Sprite er4;
		er4.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er4.png"));
		er4.Resize(
				2.5 * er4.GetSize().x * er4.GetSize().x / fenetre.GetWidth(),
				1.25 * er4.GetSize().y * er4.GetSize().y / fenetre.GetHeight());
		er4.SetPosition(posImgX, posImgY);
		fenetre.Draw(er4);
	}
	if (er5) {
		sf::Sprite er5;
		er5.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er5.png"));
		er5.Resize(
				2.5 * er5.GetSize().x * er5.GetSize().x / fenetre.GetWidth(),
				1.25 * er5.GetSize().y * er5.GetSize().y / fenetre.GetHeight());
		er5.SetPosition(posImgX, posImgY);
		fenetre.Draw(er5);
	}
	if (er6) {
		sf::Sprite er6;
		er6.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er6.png"));
		er6.Resize(
				2.5 * er6.GetSize().x * er6.GetSize().x / fenetre.GetWidth(),
				1.25 * er6.GetSize().y * er6.GetSize().y / fenetre.GetHeight());
		er6.SetPosition(posImgX, posImgY);
		fenetre.Draw(er6);
	}
	if (er7) {
		sf::Sprite er7;
		er7.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er7.png"));
		er7.Resize(
				2.5 * er7.GetSize().x * er7.GetSize().x / fenetre.GetWidth(),
				1.25 * er7.GetSize().y * er7.GetSize().y / fenetre.GetHeight());
		er7.SetPosition(posImgX, posImgY);
		fenetre.Draw(er7);
	}
}

void JeuItalie::afficherAide(sf::RenderWindow &fenetre, bool er1, bool er2,
		bool er3, bool er4, bool er5, bool er6, bool er7, float posImgX,
		float posImgY, float tailleX, float tailleY) {

	if (!er1) {
		sf::Sprite aide1;
		aide1.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide1.png"));
		aide1.Resize(tailleX, tailleY);
		aide1.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide1);

	} else if (!er2) {
		sf::Sprite aide2;
		aide2.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide2.png"));
		aide2.Resize(2.5 * aide2.GetSize().x * aide2.GetSize().x
				/ fenetre.GetWidth(), 1.25 * aide2.GetSize().y
				* aide2.GetSize().y / fenetre.GetHeight());
		aide2.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide2);

	}

	else if (!er3) {
		sf::Sprite aide3;
		aide3.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide3.png"));
		aide3.Resize(2.5 * aide3.GetSize().x * aide3.GetSize().x
				/ fenetre.GetWidth(), 1.25 * aide3.GetSize().y
				* aide3.GetSize().y / fenetre.GetHeight());
		aide3.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide3);

	} else if (!er4) {
		sf::Sprite aide4;
		aide4.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide4.png"));
		aide4.Resize(2.5 * aide4.GetSize().x * aide4.GetSize().x
				/ fenetre.GetWidth(), 1.25 * aide4.GetSize().y
				* aide4.GetSize().y / fenetre.GetHeight());
		aide4.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide4);

	} else if (!er5) {
		sf::Sprite aide5;
		aide5.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide5.png"));
		aide5.Resize(2.5 * aide5.GetSize().x * aide5.GetSize().x
				/ fenetre.GetWidth(), 1.25 * aide5.GetSize().y
				* aide5.GetSize().y / fenetre.GetHeight());
		aide5.SetPosition(posImgX, posImgY);

		fenetre.Draw(aide5);

	} else if (!er6) {
		sf::Sprite aide6;
		aide6.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide6.png"));
		aide6.Resize(2.5 * aide6.GetSize().x * aide6.GetSize().x
				/ fenetre.GetWidth(), 1.25 * aide6.GetSize().y
				* aide6.GetSize().y / fenetre.GetHeight());

		aide6.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide6);

	} else if (!er7) {
		sf::Sprite aide7;
		aide7.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide7.png"));
		aide7.Resize(2.5 * aide7.GetSize().x * aide7.GetSize().x
				/ fenetre.GetWidth(), 1.25 * aide7.GetSize().y
				* aide7.GetSize().y / fenetre.GetHeight());
		aide7.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide7);

	}
}

int JeuItalie::run(sf::RenderWindow &fenetre) {
	//Initialisation des variables////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Clock Clock; //Horloge
	int ecranSuivant = 4; // par défault, celui de l'écran actif
	bool er1 = false;
	bool er2 = false; //booléens indiquant si les erreurs ont été trouvées
	bool er3 = false; //déclarés en plusieurs fois sinon certains sont a true dès le départ ..
	bool er4 = false;
	bool er5 = false;
	bool er6 = false;
	bool er7 = false;
	int nbATrouver = 7; //Le nombre d'erreurs a trouver est de 7 au départ
	Page pays; //Declaration d'une Page pays qui servira a afficher les menus music et menu


	//SPRITES////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//float rapport= fenetre.GetHeight()/fenetre.GetWidth();
	sf::Sprite fond; //L'image comportant les Erreurs
	fond.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/JeuMusee.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Sprite original; //L'image originale
	original.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/7erreurs_originalp.png"));
	float sizeXO = 2.5 * original.GetSize().x * original.GetSize().x
			/ fenetre.GetWidth();
	float sizeYO = 1.25 * original.GetSize().y * original.GetSize().y
			/ fenetre.GetHeight();
	original.Resize(sizeXO, sizeYO);
	original.SetPosition(fenetre.GetWidth() / 2 - original.GetSize().x - 10,
			(fenetre.GetHeight() - original.GetSize().y) / 2); // positionement de l'image originale
	//if(rapport > (fenetre.GetHeight()/fenetre.GetWidth()))
	//original.Resize((fenetre.GetWidth()/2) * (772/1036),  (fenetre.GetHeight()/2)*(772/1036));
	//else
	//original.Resize(fenetre.GetWidth()/2,((fenetre.GetWidth()/2) *(1036/772)));
	sf::Sprite titre; //L'image comportant les instructions
		titre.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/titrejeu.png"));
		titre.SetScale(0.75,0.75);
		titre.SetPosition(fenetre.GetWidth()/2-titre.GetSize().x/2,0); // placement de l'image erronée en fonction de l'originale

	sf::Sprite erreur; //L'image comportant les Erreurs
	erreur.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/7erreurs_fautep.png"));
	sf::Vector2f vectorSize(erreur.GetSize().x,erreur.GetSize().y);
	float sizeXE = 2.5 * erreur.GetSize().x * erreur.GetSize().x
			/ fenetre.GetWidth();
	float sizeYE = 1.25 * erreur.GetSize().y * erreur.GetSize().y
			/ fenetre.GetHeight();
	erreur.Resize(sizeXE, sizeYE);
	erreur.SetPosition(fenetre.GetWidth() / 2 + 10, (fenetre.GetHeight()
			- original.GetSize().y) / 2); // placement de l'image erronée en fonction de l'originale

	//erreur.Resize( erreur.GetSize().x*rapport, erreur.GetSize().y*rapport);
	sf::Sprite instructions; //L'image comportant les instructions
	instructions.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/bulle1.png"));
	instructions.SetPosition(original.GetPosition().x
			- instructions.GetSize().x - 20, fenetre.GetHeight() / 2
			- instructions.GetSize().y / 2-20); // placement de l'image erronée en fonction de l'originale

	//TEXTES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Font MyFont;
	if (!MyFont.LoadFromFile(
			"le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
		cerr << "Erreur lors du chargement de la police";

	sf::Font MyFontB;
		if (!MyFontB.LoadFromFile(
				"le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 50))
			cerr << "Erreur lors du chargement de la police";


	sf::String legendeOriginal("Tableau de Gauche", MyFont, 30.f);
	legendeOriginal.Move(original.GetPosition().x + original.GetSize().x / 2
			- legendeOriginal.GetRect().GetWidth() / 2,
			original.GetPosition().y - 30);

	sf::String legendeErreur("Tableau aux 7 erreurs", MyFont, 30.f);
	legendeErreur.Move(erreur.GetPosition().x + erreur.GetSize().x / 2
			- legendeErreur.GetRect().GetWidth() / 2, erreur.GetPosition().y
			- 30);

	sf::String jeu(L"Nombre d'erreurs à trouver : ",MyFont,35.f);
	jeu.Move(fenetre.GetWidth() / 2 - (jeu.GetRect().Right) / 2,
			fenetre.GetHeight() - 2*(original.GetSize().y)/ 7);
	jeu.SetColor(sf::Color::White);

	sf::String nbErreurs("7");
	nbErreurs.Move(jeu.GetRect().Right, jeu.GetPosition().y);
	nbErreurs.SetColor(sf::Color::White);

	sf::String gagne("Tu as gagne !",MyFontB,40.f);
	float originalbottom=original.GetPosition().y+original.GetSize().y;
	float diff= (jeu.GetPosition().y -originalbottom)/2;
	gagne.Move(fenetre.GetWidth() / 2 - gagne.GetRect().Right/2,originalbottom+diff-gagne.GetSize()/2);
	gagne.SetColor(sf::Color::Green);

	sf::String ombreGagne;
	ombreTexte(gagne, ombreGagne, sf::Color::Black, 2, 2);

	sf::String txtAide("Aide",MyFont,25.f);
	//Bouton////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Bouton boutAide;
	boutAide.initBouton("le_voyage_de_barbulle/img/italie/barbulleAide.png",
			"le_voyage_de_barbulle/img/italie/barbulleAide.png");
	boutAide.redimensionner(0.5);
	boutAide.placer(erreur.GetPosition().x+erreur.GetSize().x+20,(fenetre.GetHeight()/1.4));
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//Vue
	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()));
	fenetre.SetView(vue);
	Clock.Reset(); //On remet l'horloge a zéro en dehors de la boucle. Sert pour passer a l'ecran Suivant uniquement si l'ecran actuel est resté affiché
	// Plus d'une seconde, voir condition plus bas : (Clock.GetElapsedTime() > 1). Sécurité sinon le clic sur les fleches est compté
	// Pour tous les écrans ! (boutons au même endroit sur tous les écrans :p )

	// # Pour que le programme ne se termine pas :)
	sf::Event event;
	while (fenetre.IsOpened() && (ecranSuivant == JEU_ITALIE) )
	{

		// EVENEMENTS //////////////////////////////////////////
		while (fenetre.GetEvent(event))
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type == sf::Event::KeyReleased && event.Key.Code
					== sf::Key::Escape)
				fenetre.Close();
		///On dessine sur la fenetre
		fenetre.Clear();
		fenetre.Draw(fond);
		fenetre.Draw(titre);
		boutAide.drawMe(fenetre);
			fenetre.Draw(txtAide);
			fenetre.Draw(original);//Image d'origine
			fenetre.Draw(legendeOriginal);
		fenetre.Draw(erreur); //Image d'erreur
		fenetre.Draw(legendeErreur);
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left)) {
			//Si on clique sur la fenetre, on regarde la position du clic si elle correspond a une des erreurs

			float rapportX=erreur.GetSize().x/vectorSize.x;
			float rapportY=erreur.GetSize().y/vectorSize.y;

			if (!er1 && erreur1Trouvee(fenetre,rapportX,rapportY,erreur)) {
				er1 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er2 && erreur2Trouvee(fenetre,rapportX,rapportY,erreur)) {
				er2 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er3 && erreur3Trouvee(fenetre,rapportX,rapportY,erreur)) {
				er3 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er4 && erreur4Trouvee(fenetre,rapportX,rapportY,erreur)) {
				er4 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er5 && erreur5Trouvee(fenetre,rapportX,rapportY,erreur)) {
				er5 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er6 && erreur6Trouvee(fenetre,rapportX,rapportY,erreur)) {
				er6 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er7 && erreur7Trouvee(fenetre,rapportX,rapportY,erreur)) {
				er7 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
		}


		fenetre.Draw(jeu);
		fenetre.Draw(instructions);
		pays.dessinerPage(fenetre);

		//Ecrire les instructions : "Cliquez sur l'image fausse pour trouver les erreurs..."

		//convertir nbAtrouver en string avec la fonction ostringstream
		std::ostringstream texteb;
		// on récupère le nombre d'erreur a trouver dans le flux
		texteb << nbATrouver;
		// on en extrait une chaîne de caractères
		std::string Texte = texteb.str();

		nbErreurs.SetText(Texte);
		nbErreurs.SetFont(MyFont);
		nbErreurs.SetSize(35.f);
		fenetre.Draw(nbErreurs);
		if (boutAide.estClique(fenetre)) {
			afficherAide(fenetre, er1, er2, er3, er4, er5, er6, er7,erreur.GetPosition().x, erreur.GetPosition().y,erreur.GetSize().x,erreur.GetSize().y);

		}
		dessineMarque(fenetre, er1, er2, er3, er4, er5, er6, er7,
				erreur.GetPosition().x, erreur.GetPosition().y);
		if(nbATrouver == 0)	{

			fenetre.Draw(ombreGagne);
			fenetre.Draw(gagne);

			PoleSud_Porte::blason.setTrouve(true);
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
								ecranSuivant=pays.changerEcran(fenetre,JEU_ITALIE,ITALIEGAGNE,ITALIEMUSEE) ;
			Clock.Reset();
		}

		fenetre.Display();
		if (nbATrouver==0)
		{
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
					ecranSuivant=pays.changerEcran(fenetre,JEU_ITALIE,ITALIEGAGNE,ITALIEMUSEE) ;
		}
		else
		{
			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
						ecranSuivant=pays.changerEcran(fenetre,JEU_ITALIE,JEU_ITALIE,ITALIEMUSEE) ;
		}
	}

	return ecranSuivant;
}

