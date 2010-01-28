/*
 * JeuPerou.cpp
 *
 *  Created on: 5 déc. 2009
 *      Author: talotte&antho
 */
#include "PoleSud_Porte.h"
#include "JeuPerou.h"
#include "Page.h"
#include "DefineEcrans.h"
#include <iostream>
#include <sstream>
using namespace std;

JeuPerou::JeuPerou() {
	estLance = false;
}

JeuPerou::~JeuPerou() {
}

void JeuPerou::lancer() {
	estLance = true;
}
void JeuPerou::placerFond(sf::RenderWindow &fenetre, sf::Image img) {
	fond.SetImage(img);
	fond.SetPosition(0.f, 0.f);
	fenetre.Draw(fond);

}

void JeuPerou::creerPieces(sf::RenderWindow &fenetre,
		const std::string & piece1, const std::string & piece1_p,
		const std::string & piece2, const std::string & piece2_p,
		const std::string & piece3, const std::string & piece3_p,
		const std::string & piece5, const std::string & piece5_p) {

	val1_1.setValeur(1);
	val1_1.initBouton(piece1_p, piece1);
	val1_1.redimensionner(0.65);
	val1_1.placer((fenetre.GetWidth() * 8 / 12), (fenetre.GetHeight() * 9 / 11));
	val1_1.decalageSouris(val1_1.getTailleX(), val1_1.getTailleY());
	val1_2.setValeur(1);
	val1_2.initBouton(piece1_p, piece1);
	val1_2.redimensionner(0.65);
	val1_2.placer((fenetre.GetWidth() * 9 / 12), (fenetre.GetHeight() * 9 / 11));
	val1_2.decalageSouris(25.0, 25.0);
	val1_3.setValeur(1);
	val1_3.initBouton(piece1_p, piece1);
	val1_3.redimensionner(0.65);
	val1_3.placer((fenetre.GetWidth() * 10 / 12),
			(fenetre.GetHeight() * 9 / 11));
	val1_3.decalageSouris(25.0, 25.0);

	val2_3.setValeur(2);
	val2_3.initBouton(piece2_p, piece2);
	val2_3.redimensionner(0.65);
	val2_3.placer((fenetre.GetWidth() * 10 / 12),
			(fenetre.GetHeight() * 8 / 11));
	val2_3.decalageSouris(25.0, 25.0);
	val5_1.setValeur(5);
	val5_1.initBouton(piece5_p, piece5);
	val5_1.redimensionner(0.65);
	val5_1.placer((fenetre.GetWidth() * 8 / 12), (fenetre.GetHeight() * 8 / 11));
	val5_1.decalageSouris(25.0, 25.0);
	val3_2.setValeur(3);
	val3_2.initBouton(piece3_p, piece3);
	val3_2.redimensionner(0.65);
	val3_2.placer((fenetre.GetWidth() * 9 / 12), (fenetre.GetHeight() * 8 / 11));
	val3_2.decalageSouris(25.0, 25.0);
}

bool JeuPerou::detectePiecePayes(sf::RenderWindow &fenetre, float posImgX,
		float posImgY) {
	//Retourne Vrai si une piece est detectee, faux sinon

	float posX = fenetre.GetInput().GetMouseX(); //On récupere la position de la souris lors du clic
	float posY = fenetre.GetInput().GetMouseY();
	if ((posX >= (75.f + posImgX)) && (posX <= (337.f + posImgX)) && (posY
			>= (350 + posImgY)) && (posY <= (540 + posImgY)))
		//Si position souris entre 75 + posImgX et 337 +posImgX en X et entre 350 + posImgY et 540 + posImgY en Y
		// Soit si la position de la souris est dans le rectangle est payé
		return true; //souris dans rectangle
	else
		return false; //souris dans pas rectangle
}

int JeuPerou::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = JEU_PEROU;
	sf::Clock Clock; //Horloge
	Clock.Reset();

	sf::Font cursiveFont;
	if (!cursiveFont.LoadFromFile(
			"le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 25.f))
		cerr << "Erreur lors du chargement de la police" << endl;

	bool mouseMove = false;
	bool lache = true;
	bool entree = true;
	bool boolgagner = false;
	//IMAGES////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
	sf::Sprite fond;
	fond.SetImage(Ecran::MonManager.GetImage(
			"le_voyage_de_barbulle/img/perou/jeuPerou1.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	//INSTRUCTION ////////////////////////////////////////////////////////////////////////

	sf::Sprite inst;
	inst.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/instruction.png"));
	inst.SetPosition((fenetre.GetWidth())*8/20, ((fenetre.GetHeight())*2/20));

	// texte du bouton
	sf::String texteV("Valider");
	texteV.SetColor(sf::Color::Black);
	texteV.SetSize(25.f);
	texteV.SetFont(cursiveFont);
	texteV.SetColor(sf::Color::Black);

	sf::String texteA("Annuler");
	texteA.SetColor(sf::Color::Black);
	texteA.SetSize(25.f);
	texteA.SetFont(cursiveFont);
	texteA.SetColor(sf::Color::Black);

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()));
	fenetre.SetView(vue);
	Page pays;
	Bouton valider;

	valider.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png",
			"le_voyage_de_barbulle/img/histoire/bouton_f.png");
	valider.redimensionner(0.5);
	valider.placer((fenetre.GetWidth() / 2.3), ((fenetre.GetHeight()) / 1.6));
	valider.placerTexte(texteV);

	Bouton annuler;
	annuler.initBouton("le_voyage_de_barbulle/img/histoire/bouton_n.png",
				"le_voyage_de_barbulle/img/histoire/bouton_f.png");
	annuler.redimensionner(0.5);
	annuler.placer((fenetre.GetWidth() / 2.3), ((fenetre.GetHeight()) / 1.3));
	annuler.placerTexte(texteA);
	JeuPerou::creerPieces(fenetre,
			"le_voyage_de_barbulle/img/sprite/piece_1.png",
			"le_voyage_de_barbulle/img/sprite/piece_1_p.png",
			"le_voyage_de_barbulle/img/sprite/piece_2.png",
			"le_voyage_de_barbulle/img/sprite/piece_2_p.png",
			"le_voyage_de_barbulle/img/sprite/piece_3.png",
			"le_voyage_de_barbulle/img/sprite/piece_3_p.png",
			"le_voyage_de_barbulle/img/sprite/piece_5.png",
			"le_voyage_de_barbulle/img/sprite/piece_5_p.png");
	///TEXTES/////////////////
	sf::Font MyFont;
	if (!MyFont.LoadFromFile(
			"le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
		cerr << "Erreur lors du chargement de la police";

	sf::String gagne("Nous pouvons y aller, tu as payé ton ticket !", MyFont,
			40.f);
	gagne.Move(fenetre.GetWidth() / 2 - gagne.GetRect().Right / 2,
			fenetre.GetHeight() / 2 - gagne.GetRect().Top / 2);
	gagne.SetColor(sf::Color::Blue);

	sf::String
			instructions(
					"Pour voyager en bus tu dois payer ton ticket pour cela, tu dois sélectionner et déplacer les bonnes pieces sur la gauche dans le carré payé",
					MyFont, 40.f);
	instructions.Move(fenetre.GetWidth() / 2 - gagne.GetRect().Right / 2,
			fenetre.GetHeight() / 2 - gagne.GetRect().Top / 2);
	instructions.SetColor(sf::Color::Black);

	int sommeDem = 7;
	int sommeTot = 0;
	///AFFICHAGE FENETRE////////////////////////////////
	sf::Event event;

	while (fenetre.IsOpened() && (ecranSuivant == JEU_PEROU)) {

		while (fenetre.GetEvent(event)) {
			// # Instanciation de tous les éc fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();
			else if (event.Type == sf::Event::KeyReleased && event.Key.Code
					== sf::Key::Escape)
				fenetre.Close();
			else if (event.Type == sf::Event::MouseMoved)
				mouseMove = true;
			else if (event.Type == sf::Event::MouseButtonPressed
					&& (event.MouseButton.Button == sf::Mouse::Left)) {
				lache = true;
			}
		}

		fenetre.Clear(sf::Color(255, 255, 255));

		fenetre.Draw(fond);
		fenetre.Draw(inst);
		valider.drawMe(fenetre);
		fenetre.Draw(texteV);
		annuler.drawMe(fenetre);
		fenetre.Draw(texteA);
		pays.dessinerPage(fenetre);

		// -- pieces de 1

		if ((autoriseBouger(val1_1)) && val1_1.estClique(fenetre)) {
			val1_1.setABouger(true);
		}

		if ((autoriseBouger(val1_2)) && val1_2.estClique(fenetre))
			val1_2.setABouger(true);

		if ((autoriseBouger(val1_3)) && val1_3.estClique(fenetre))
			val1_3.setABouger(true);


		if ((autoriseBouger(val2_3)) && val2_3.estClique(fenetre))
			val2_3.setABouger(true);


		if ((autoriseBouger(val3_2)) && val3_2.estClique(fenetre))
			val3_2.setABouger(true);

		// -- piece de 5
		if ((autoriseBouger(val5_1)) && val5_1.estClique(fenetre))
			val5_1.setABouger(true);

		val1_1.deplacer(fenetre, mouseMove, lache);
		val1_1.drawMe(fenetre);

		val1_2.deplacer(fenetre, mouseMove, lache);
		val1_2.drawMe(fenetre);

		val1_3.deplacer(fenetre, mouseMove, lache);
		val1_3.drawMe(fenetre);


		val2_3.deplacer(fenetre, mouseMove, lache);
		val2_3.drawMe(fenetre);

		val3_2.deplacer(fenetre, mouseMove, lache);
		val3_2.drawMe(fenetre);

		val5_1.deplacer(fenetre, mouseMove, lache);
		val5_1.drawMe(fenetre);



		if (valider.estClique(fenetre) && entree && !val1_1.estClique(fenetre)&& !val1_2.estClique(fenetre)
				&& !val1_3.estClique(fenetre) && !val2_3.estClique(fenetre)&& !val3_2.estClique(fenetre)&& !val5_1.estClique(fenetre)) {
			if (inZone(fenetre, val5_1)) {
				sommeTot = sommeTot + val5_1.getValeur();
			}

			if (inZone(fenetre, val3_2)) {
				sommeTot += val3_2.getValeur();
			}

			if (inZone(fenetre, val2_3)) {
				sommeTot += val2_3.getValeur();
			}


			if (inZone(fenetre, val1_3)) {
				sommeTot += val1_3.getValeur();
			}
			if (inZone(fenetre, val1_2)) {
				sommeTot += val1_2.getValeur();
			}
			if (inZone(fenetre, val1_1)) {
				sommeTot += val1_1.getValeur();
			}
			cout << sommeTot << endl;
			if (sommeTot != sommeDem)
			{
				val1_1.placer((fenetre.GetWidth() * 8 / 12), (fenetre.GetHeight() * 9 / 11));
				val1_2.placer((fenetre.GetWidth() * 9 / 12), (fenetre.GetHeight() * 9 / 11));
				val1_3.placer((fenetre.GetWidth() * 10 / 12),(fenetre.GetHeight() * 9 / 11));
				val2_3.placer((fenetre.GetWidth() * 10 / 12),(fenetre.GetHeight() * 8 / 11));
				val5_1.placer((fenetre.GetWidth() * 8 / 12), (fenetre.GetHeight() * 8 / 11));
				val3_2.placer((fenetre.GetWidth() * 9 / 12), (fenetre.GetHeight() * 8 / 11));
				mouseMove = false;
				lache = true;
				entree = true;
				sommeTot =0;
			}
			else
			{
			entree = false;
			 boolgagner=true;
			}

		}

		if (annuler.estClique(fenetre) && !boolgagner && !val1_1.estClique(fenetre)&& !val1_2.estClique(fenetre)
				&& !val1_3.estClique(fenetre) && !val2_3.estClique(fenetre)&& !val3_2.estClique(fenetre)&& !val5_1.estClique(fenetre)
				)
		{
			val1_1.placer((fenetre.GetWidth() * 8 / 12), (fenetre.GetHeight() * 9 / 11));
			val1_2.placer((fenetre.GetWidth() * 9 / 12), (fenetre.GetHeight() * 9 / 11));
			val1_3.placer((fenetre.GetWidth() * 10 / 12),(fenetre.GetHeight() * 9 / 11));
			val2_3.placer((fenetre.GetWidth() * 10 / 12),(fenetre.GetHeight() * 8 / 11));
			val5_1.placer((fenetre.GetWidth() * 8 / 12), (fenetre.GetHeight() * 8 / 11));
			val3_2.placer((fenetre.GetWidth() * 9 / 12), (fenetre.GetHeight() * 8 / 11));
			mouseMove = false;
			lache = true;
			entree = true;
			sommeTot =0;
		}

		if ( boolgagner)
		{
		ecranSuivant = PEROUGAGNE;
		PoleSud_Porte::poncho.setTrouve(true);
		Clock.Reset();
		}

		fenetre.Display();

		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left)
				&& pays.menuActif(fenetre)&& !val1_1.estClique(fenetre)&& !val1_2.estClique(fenetre)&& !val1_3.estClique(fenetre) && !val2_3.estClique(fenetre)&& !val3_2.estClique(fenetre)&& !val5_1.estClique(fenetre))
			ecranSuivant = pays.changerEcran(fenetre, JEU_PEROU, JEU_PEROU,PEROU);
	}

	return ecranSuivant;

}

bool JeuPerou::autoriseBouger(Piece & obj) {

	if (&obj == &val1_1) {
		if (!(val1_3.estBougeable()) && !(val1_2.estBougeable())

				&& !(val2_3.estBougeable())
				&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
			return true;
		else
			return false;
	}

	else if (&obj == &val1_2) {
		if (!(val1_1.estBougeable()) && !(val1_3.estBougeable())
				&& !(val2_3.estBougeable())
				&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
			return true;
		else
			return false;
	}

	else if (&obj == &val1_3) {
		if (!(val1_1.estBougeable()) && !(val1_2.estBougeable())
				&& !(val2_3.estBougeable())
				&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
			return true;
		else
			return false;
	}


	else if (&obj == &val2_3) {
		if (!(val1_1.estBougeable()) && !(val1_2.estBougeable())
				&& !(val1_3.estBougeable())
				&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
			return true;
		else
			return false;
	}



	else if (&obj == &val3_2) {
		if (!(val1_1.estBougeable()) && !(val1_2.estBougeable())
				&& !(val1_3.estBougeable())
				 && !(val2_3.estBougeable())
				&& !(val5_1.estBougeable()))
			return true;
		else
			return false;
	}

	else if (&obj == &val5_1)// val5_1
	{
		if (!(val1_1.estBougeable()) && !(val1_2.estBougeable())
				&& !(val1_3.estBougeable())
			 && !(val2_3.estBougeable())
				 && !(val3_2.estBougeable()))
			return true;
		else
			return false;
	} else
		return false;
}

bool JeuPerou::inZone(sf::RenderWindow &fenetre, Piece piece) {

	float posY = piece.getPosY();
	float posX = piece.getPosX();

	if (((posX >= fenetre.GetWidth()*2.8 / 37) && (posX <= fenetre.GetWidth()*13.4/37))&&((posY>=fenetre.GetHeight()*14/23)&&(posY<=fenetre.GetHeight()*21.3/23)) ) {

			cout<<"position piece:"<<posX<<","<<posY<<endl;
		return true;

	} else
		return false;
}

int JeuPerou::inZoneCalculeSomme(sf::RenderWindow &fenetre, int somme,
		Piece piece) {
	if (inZone(fenetre, piece)) {
		somme = somme + piece.getValeur();
		cout << piece.getValeur();
		return somme;
	} else
		return somme;
}
