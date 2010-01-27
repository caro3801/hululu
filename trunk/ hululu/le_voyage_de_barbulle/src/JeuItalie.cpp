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
JeuItalie::JeuItalie() {
}

JeuItalie::~JeuItalie() {
}

bool JeuItalie::erreur1Trouvee(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon

	float posX = fenetre.GetInput().GetMouseX(); //On récupere la position de la souris lors du clic
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (110.f + posImgX)) && (posX <= (120.f + posImgX)) && (posY
			>= (147 + posImgY)) && (posY <= (162 + posImgY)))
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

bool JeuItalie::erreur2Trouvee(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si l'erreur 2 est cliquée, faux sinon

	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if( ((posX >= (30.f + posImgX)) && (posX <= (46.f + posImgX)) && (posY >= (270.f + posImgY)) && (posY <= (278.f + posImgY)))
			|| ((posX >= (42.f + posImgX)) && (posX <= (60.f + posImgX)) && (posY >= (260.f + posImgY)) && (posY <= (270.f + posImgY))))

		return true; //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}

bool JeuItalie::erreur3Trouvee(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si l'erreur 3 est cliquée, faux sinon

	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (82.f + posImgX)) && (posX <= (104.f + posImgX)) && (posY
			>= (310.f + posImgY)) && (posY <= (330.f + posImgY)))
		return true;
	else
		return false;
}

bool JeuItalie::erreur4Trouvee(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si l'erreur 4 est cliquée, faux sinon
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (308.f + posImgX)) && (posX <= (322.f + posImgX)) && (posY
			>= (105.f + posImgY)) && (posY <= (126.f + posImgY)))
		return true;
	else
		return false;
}

bool JeuItalie::erreur5Trouvee(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (((posX >= (377.f + posImgX)) && (posX <= (386.f + posImgX)) && (posY	>= (162.f + posImgY)) && (posY <= (180.f + posImgY)))
			|| ((posX >= (384.f + posImgX)) && (posX <= (392.f + posImgX)) && (posY	>= (142.f + posImgY)) && (posY <= (164.f + posImgY)))
					|| ((posX >= (390.f + posImgX)) && (posX <= (398.f + posImgX)) && (posY	>= (124.f + posImgY)) && (posY <= (144.f + posImgY)))
							|| ((posX >= (397.f + posImgX)) && (posX <= (405.f + posImgX)) && (posY	>= (107.f + posImgY)) && (posY <= (126.f + posImgY))))
		return true; //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}

bool JeuItalie::erreur6Trouvee(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (361.f + posImgX)) && (posX <= (377.f + posImgX)) && (posY
			>= (510 + posImgY)) && (posY <= (522 + posImgY)))
		return true; //L'erreur est trouvée
	else
		return false; //L'erreur n'est pas trouvée
}

bool JeuItalie::erreur7Trouvee(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si l'erreur 1 est cliquée, faux sinon
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (((posX >= (111.f + posImgX)) && (posX <= (118.f + posImgX)) && (posY	>= (395 + posImgY)) && (posY <= (408 + posImgY)))
			||((posX >= (114.f + posImgX)) && (posX <= (122.f + posImgX)) && (posY	>= (387 + posImgY)) && (posY <= (397 + posImgY))))
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
		er1.SetPosition(posImgX, posImgY);
		fenetre.Draw(er1);
	}
	if (er2) {
		sf::Sprite er2;
		er2.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er2.png"));
		er2.SetPosition(posImgX, posImgY);
		fenetre.Draw(er2);
	}
	if (er3) {
		sf::Sprite er3;
		er3.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er3.png"));
		er3.SetPosition(posImgX, posImgY);
		fenetre.Draw(er3);
	}
	if (er4) {
		sf::Sprite er4;
		er4.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er4.png"));
		er4.SetPosition(posImgX, posImgY);
		fenetre.Draw(er4);
	}
	if (er5) {
		sf::Sprite er5;
		er5.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er5.png"));
		er5.SetPosition(posImgX, posImgY);
		fenetre.Draw(er5);
	}
	if (er6) {
		sf::Sprite er6;
		er6.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er6.png"));
		er6.SetPosition(posImgX, posImgY);
		fenetre.Draw(er6);
	}
	if (er7) {
		sf::Sprite er7;
		er7.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er7.png"));
		er7.SetPosition(posImgX, posImgY);
		fenetre.Draw(er7);
	}
}

void JeuItalie::afficherAide(sf::RenderWindow &fenetre, bool er1, bool er2,
		bool er3, bool er4, bool er5, bool er6, bool er7, float posImgX,
		float posImgY) {

	if (!er1) {
		sf::Sprite aide1;
		aide1.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide1.png"));
		aide1.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide1);


	} else if (!er2) {
		sf::Sprite aide2;
		aide2.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide2.png"));
		aide2.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide2);

	}

	else if (!er3) {
		sf::Sprite aide3;
		aide3.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide3.png"));
		aide3.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide3);

	} else if (!er4) {
		sf::Sprite aide4;
		aide4.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide4.png"));
		aide4.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide4);

	} else if (!er5) {
		sf::Sprite aide5;
		aide5.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide5.png"));
		aide5.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide5);

	} else if (!er6) {
		sf::Sprite aide6;
		aide6.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide6.png"));
		aide6.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide6);

	} else if (!er7) {
		sf::Sprite aide7;
		aide7.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/aide7.png"));
		aide7.SetPosition(posImgX, posImgY);
		fenetre.Draw(aide7);

	}
}

int JeuItalie::run(sf::RenderWindow &fenetre) {
	//Initialisation des variables////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Clock Clock; //Horloge
	int ecranSuivant = 4; // par défault, celui de l'écran actif
	bool er1= false;
	bool er2= false;   //booléens indiquant si les erreurs ont été trouvées
	bool er3 = false; //déclarés en plusieurs fois sinon certains sont a true dès le départ ..
	bool er4 = false;
	bool er5 = false;
	bool er6= false;
	bool er7 = false;
	int nbATrouver = 7; //Le nombre d'erreurs a trouver est de 7 au départ
	bool objetGagne = false;
	Page pays; //Declaration d'une Page pays qui servira a afficher les menus music et menu


	//SPRITES////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//float rapport= fenetre.GetHeight()/fenetre.GetWidth();
	sf::Sprite original; //L'image originale
	original.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/7erreurs_originalp.png"));
	original.SetPosition(fenetre.GetWidth() / 2 - original.GetSize().x - 10,
			(fenetre.GetHeight() - original.GetSize().y) / 2); // positionement de l'image originale
	//if(rapport > (fenetre.GetHeight()/fenetre.GetWidth()))
	//original.Resize((fenetre.GetWidth()/2) * (772/1036),  (fenetre.GetHeight()/2)*(772/1036));
	//else
	//original.Resize(fenetre.GetWidth()/2,((fenetre.GetWidth()/2) *(1036/772)));

	sf::Sprite erreur; //L'image comportant les Erreurs
	erreur.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/italie/7erreurs_fautep.png"));
	erreur.SetPosition(fenetre.GetWidth() / 2 + 10, (fenetre.GetHeight()
			- original.GetSize().y) / 2); // placement de l'image erronée en fonction de l'originale

	//erreur.Resize( erreur.GetSize().x*rapport, erreur.GetSize().y*rapport);
	sf::Sprite instructions; //L'image comportant les instructions
		instructions.SetImage(Ecran::MonManager.GetImage(
				"le_voyage_de_barbulle/img/italie/er1.png"));
		instructions.SetPosition(original.GetPosition().x - instructions.GetSize().x-20, fenetre.GetHeight()/2- instructions.GetSize().y/2); // placement de l'image erronée en fonction de l'originale

	//TEXTES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Font MyFont;
	if (!MyFont.LoadFromFile(
			"le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
		cerr << "Erreur lors du chargement de la police";

	sf::String titre(
			"Jeu des 7 Erreurs: \n L'Annonciation de Botticelli (1967)",
			MyFont, 30.f); //Titre
	titre.Move(fenetre.GetWidth() / 3, 60.f);
	titre.SetColor(sf::Color::Blue);

	sf::String legendeOriginal("Tableau Original", MyFont, 25.f);
	legendeOriginal.Move(original.GetPosition().x + original.GetSize().x / 2
			- legendeOriginal.GetRect().GetWidth() / 2,
			original.GetPosition().y - 30);

	sf::String legendeErreur("Tableau aux 7 erreurs", MyFont, 25.f);
	legendeErreur.Move(erreur.GetPosition().x + erreur.GetSize().x / 2
			- legendeErreur.GetRect().GetWidth() / 2, erreur.GetPosition().y
			- 30);

	sf::String jeu("Nombre d'erreurs a trouver : ");
	jeu.Move(fenetre.GetWidth() / 2 - (jeu.GetRect().Right) / 2,
			fenetre.GetHeight() - 2*(original.GetSize().y)/ 7);
	jeu.SetColor(sf::Color::White);

	sf::String nbErreurs("7");
	nbErreurs.Move(jeu.GetRect().Right, jeu.GetPosition().y);
	nbErreurs.SetColor(sf::Color::White);

	sf::String gagne("Tu as gagne !",MyFont,40.f);
	float originalbottom=original.GetPosition().y+original.GetSize().y;
	float diff= (jeu.GetPosition().y -originalbottom)/2;
	gagne.Move(fenetre.GetWidth() / 2 - gagne.GetRect().Right/2,originalbottom+diff);
	gagne.SetColor(sf::Color::Green);

	sf::String txtAide("Aide");
	//Bouton////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Bouton boutAide;
	boutAide.initBouton("le_voyage_de_barbulle/img/italie/barbulle_italie.png",
			"le_voyage_de_barbulle/img/italie/barbulle_italie.png");
	boutAide.redimensionner(0.5);
	boutAide.placer(erreur.GetPosition().x+erreur.GetSize().x+20,(fenetre.GetHeight()-boutAide.GetSize().y)/2);
	boutAide.placerTexte(txtAide);
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
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left)) {
			//Si on clique sur la fenetre, on regarde la position du clic si elle correspond a une des erreurs

			if (!er1 && erreur1Trouvee(fenetre, erreur.GetPosition().x,
					erreur.GetPosition().y)) {
				er1 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er2 && erreur2Trouvee(fenetre, erreur.GetPosition().x,
					erreur.GetPosition().y)) {
				er2 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er3 && erreur3Trouvee(fenetre, erreur.GetPosition().x,
					erreur.GetPosition().y)) {
				er3 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er4 && erreur4Trouvee(fenetre, erreur.GetPosition().x,
					erreur.GetPosition().y)) {
				er4 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er5 && erreur5Trouvee(fenetre, erreur.GetPosition().x,
					erreur.GetPosition().y)) {
				er5 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er6 && erreur6Trouvee(fenetre, erreur.GetPosition().x,
					erreur.GetPosition().y)) {
				er6 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
			if (!er7 && erreur7Trouvee(fenetre, erreur.GetPosition().x,
					erreur.GetPosition().y)) {
				er7 = true; //Erreur 1 trouvée
				nbATrouver = nbATrouver - 1; //Une erreur en moins reste a trouver
			}
		}

		///On dessine sur la fenetre
		fenetre.Clear();
		pays.dessinerPage(fenetre);

		fenetre.Draw(titre);
		boutAide.drawMe(fenetre);
		fenetre.Draw(txtAide);
		fenetre.Draw(original);//Image d'origine
		fenetre.Draw(legendeOriginal);
		fenetre.Draw(erreur); //Image d'erreur
		fenetre.Draw(legendeErreur);
		fenetre.Draw(jeu);
		fenetre.Draw(instructions);
		//Ecrire les instructions : "Cliquez sur l'image fausse pour trouver les erreurs..."

		//convertir nbAtrouver en string avec la fonction ostringstream
		std::ostringstream texteb;
		// on récupère le nombre d'erreur a trouver dans le flux
		texteb << nbATrouver;
		// on en extrait une chaîne de caractères
		std::string Texte = texteb.str();

		nbErreurs.SetText(Texte);
		fenetre.Draw(nbErreurs);
		if (boutAide.estClique(fenetre)) {
			afficherAide(fenetre, er1, er2, er3, er4, er5, er6, er7,erreur.GetPosition().x, erreur.GetPosition().y);

		}
		dessineMarque(fenetre, er1, er2, er3, er4, er5, er6, er7,
				erreur.GetPosition().x, erreur.GetPosition().y);
		if(nbATrouver == 0)	{
			fenetre.Draw(gagne);
			Clock.Reset();
		}

		while (nbATrouver == 0) {
			fenetre.Display();
			if(Clock.GetElapsedTime() > 5) {
				objetGagne=true;
				PoleSud_Porte::blason.setTrouve(objetGagne);
				nbATrouver++;
				ecranSuivant = MAPPEMONDE;
			}
		}

		fenetre.Display();
		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
					ecranSuivant=pays.changerEcran(fenetre,JEU_ITALIE,JEU_ITALIE,ITALIEPRESENT) ;
	}

	return ecranSuivant;
}

