/*
 * JeuPerou.cpp
 *
 *  Created on: 5 déc. 2009
 *      Author: talotte&antho
 */
#include "JeuPerou.h"
#include "Page.h"
#include "DefineEcrans.h"
#include <iostream>
#include <sstream>
using namespace std;

JeuPerou::JeuPerou()
{
estLance = false;
}

JeuPerou::~JeuPerou()
{
}

void JeuPerou::lancer()
{
	estLance=true;
}
void JeuPerou::placerFond(sf::RenderWindow &fenetre,sf::Image img)
{
	fond.SetImage(img);
	fond.SetPosition(0.f,0.f);
	fenetre.Draw(fond);

}

void JeuPerou::creerPieces(sf::RenderWindow &fenetre,const std::string & piece1,const std::string & piece2,const std::string & piece3, const std::string & piece5)
{

	val1_1.setValeur(1); val1_1.initBouton(piece1,piece1); val1_1.redimensionner(0.75); val1_1.placer((fenetre.GetWidth()*8/12),(fenetre.GetHeight()*9/11));val1_1.decalageSouris(val1_1.getTailleX(),val1_1.getTailleY());
	val1_2.setValeur(1); val1_2.initBouton(piece1,piece1); val1_2.redimensionner(0.75); val1_2.placer((fenetre.GetWidth()*9/12),(fenetre.GetHeight()*9/11));val1_2.decalageSouris(25.0,25.0);
	val1_3.setValeur(1); val1_3.initBouton(piece1,piece1); val1_3.redimensionner(0.75); val1_3.placer((fenetre.GetWidth()*10/12),(fenetre.GetHeight()*9/11));val1_3.decalageSouris(25.0,25.0);
	val2_1.setValeur(2); val2_1.initBouton(piece2,piece2); val2_1.redimensionner(0.75); val2_1.placer((fenetre.GetWidth()*8/12),(fenetre.GetHeight()*7/11));val2_1.decalageSouris(25.0,25.0);
	val3_1.setValeur(3); val3_1.initBouton(piece3,piece3); val3_1.redimensionner(0.75); val3_1.placer((fenetre.GetWidth()*9/12),(fenetre.GetHeight()*7/11));val3_1.decalageSouris(25.0,25.0);
	val2_2.setValeur(2); val2_2.initBouton(piece2,piece2); val2_2.redimensionner(0.75); val2_2.placer((fenetre.GetWidth()*10/12),(fenetre.GetHeight()*7/11));val2_2.decalageSouris(25.0,25.0);
	val2_3.setValeur(2); val2_3.initBouton(piece2,piece2); val2_3.redimensionner(0.75); val2_3.placer((fenetre.GetWidth()*10/12),(fenetre.GetHeight()*8/11));val2_3.decalageSouris(25.0,25.0);
	val5_1.setValeur(5); val5_1.initBouton(piece5,piece5); val5_1.redimensionner(0.75); val5_1.placer((fenetre.GetWidth()*8/12),(fenetre.GetHeight()*8/11));val5_1.decalageSouris(25.0,25.0);
	val3_2.setValeur(3); val3_2.initBouton(piece3,piece3); val3_2.redimensionner(0.75); val3_2.placer((fenetre.GetWidth()*9/12),(fenetre.GetHeight()*8/11));val3_2.decalageSouris(25.0,25.0);
}

bool JeuPerou::detectePiecePayes(sf::RenderWindow &fenetre, float posImgX,float posImgY) {
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

	bool mouseMove = false;
	bool lache = true;


	//Booléen pour savoir si la souris est en mouvement: utile pour déplacer des objets a la souris
	//bool detect=false;
	int total=13;

	//IMAGES////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
	sf::Sprite fond ;
	fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/jeuPerou1.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);
	Page pays;


	JeuPerou::creerPieces( fenetre,"le_voyage_de_barbulle/img/sprite/piece_1.png","le_voyage_de_barbulle/img/sprite/piece_2.png","le_voyage_de_barbulle/img/sprite/piece_3.png","le_voyage_de_barbulle/img/sprite/piece_5.png");
	///TEXTES/////////////////
	sf::Font MyFont;
		if (!MyFont.LoadFromFile(
				"le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
			cerr << "Erreur lors du chargement de la police";

		sf::String gagne("Nous pouvons y aller, tu as payé ton ticket !",MyFont,40.f);
		gagne.Move(fenetre.GetWidth() / 2 - gagne.GetRect().Right/2,fenetre.GetHeight() / 2 - gagne.GetRect().Top/2);
		gagne.SetColor(sf::Color::Blue);

		sf::String instructions("Pour voyager en bus tu dois payer ton ticket pour cela, tu dois sélectionner et déplacer les bonnes pieces sur la gauche dans le carré payé",MyFont,40.f);
		instructions.Move(fenetre.GetWidth() / 2 - gagne.GetRect().Right/2,fenetre.GetHeight() / 2 - gagne.GetRect().Top/2);
		instructions.SetColor(sf::Color::Black);

	int somme=0;

		///AFFICHAGE FENETRE////////////////////////////////
		sf::Event event;

		while(fenetre.IsOpened() && (ecranSuivant == JEU_PEROU) )
		{

			while (fenetre.GetEvent(event)) {
				// # Instanciation de tous les éc fermeture de la fenetre
				// si echap ou fermeture manuelle
				if (event.Type == sf::Event::Closed)
					fenetre.Close();
				else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
					fenetre.Close();
				else if(event.Type==sf::Event::MouseMoved)
					mouseMove=true;
				else if(event.Type==sf::Event::MouseButtonPressed && (event.MouseButton.Button==sf::Mouse::Left)) {
					lache = true;
				}
			}

//			if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left)&&(total>0)) {
//				//Si on clique sur la fenetre, on regarde la position du clic si elle correspond a une des erreurs
//
//				if (!detect && (detectePiecePayes(fenetre, val1_1.GetPosition().x,
//						val1_1.GetPosition().y) || detectePiecePayes(fenetre, val1_2.GetPosition().x,
//						val1_2.GetPosition().y) || detectePiecePayes(fenetre, val1_3.GetPosition().x,
//						val1_3.GetPosition().y))) {
//					detect = true; //piece detectee
//					total = total - 1; //total restan a trouver
//				}
//				if (!detect && (detectePiecePayes(fenetre, val2_1.GetPosition().x,
//						val2_1.GetPosition().y) || detectePiecePayes(fenetre, val2_2.GetPosition().x,
//						val2_2.GetPosition().y) || detectePiecePayes(fenetre, val2_3.GetPosition().x,
//						val2_3.GetPosition().y))) {
//					detect = true; //piece detectee
//					total = total - 2; //total restan a trouver
//				}
//				if (!detect && (detectePiecePayes(fenetre, val3_1.GetPosition().x,
//						val3_1.GetPosition().y) || detectePiecePayes(fenetre, val3_2.GetPosition().x,
//						val3_2.GetPosition().y))) {
//					detect = true; //piece detectee
//					total = total - 3; //total restan a trouver
//				}
//				if (!detect && (detectePiecePayes(fenetre, val5_1.GetPosition().x,
//						val5_1.GetPosition().y))) {
//					detect = true; //piece detectee
//					total = total - 5; //total restan a trouver
//				}
//			}

			fenetre.Clear( sf::Color(255, 255, 255) );

			fenetre.Draw(fond);
			pays.dessinerPage(fenetre);



			// -- pieces de 1

			if( (autoriseBouger(val1_1)) && val1_1.estClique(fenetre) ) {
				cout << "deplacer" << endl;
				val1_1.setABouger(true);
			}

			if( (autoriseBouger(val1_2)) && val1_2.estClique(fenetre) )
				val1_2.setABouger(true);

			if( (autoriseBouger(val1_3)) && val1_3.estClique(fenetre) )
				val1_3.setABouger(true);

			// -- pieces de 2
			if( (autoriseBouger(val2_1)) && val2_1.estClique(fenetre) )
				val2_1.setABouger(true);

			if( (autoriseBouger(val2_2)) && val2_2.estClique(fenetre) )
				val2_2.setABouger(true);

			if( (autoriseBouger(val2_3)) && val2_3.estClique(fenetre) )
				val2_3.setABouger(true);

			// -- pieces de 3
			if( (autoriseBouger(val3_1)) && val3_1.estClique(fenetre) )
				val3_1.setABouger(true);

			if( (autoriseBouger(val3_2)) && val3_2.estClique(fenetre) )
				val3_2.setABouger(true);

			// -- piece de 5
			if( (autoriseBouger(val5_1)) && val5_1.estClique(fenetre) )
				val5_1.setABouger(true);

			val1_1.deplacer(fenetre,mouseMove,lache);
			val1_1.drawMe(fenetre);

			val1_2.deplacer(fenetre,mouseMove,lache);
			val1_2.drawMe(fenetre);

			val1_3.deplacer(fenetre,mouseMove,lache);
			val1_3.drawMe(fenetre);

			val2_1.deplacer(fenetre,mouseMove,lache);
			val2_1.drawMe(fenetre);

			val2_2.deplacer(fenetre,mouseMove,lache);
			val2_2.drawMe(fenetre);

			val2_3.deplacer(fenetre,mouseMove,lache);
			val2_3.drawMe(fenetre);

			val3_1.deplacer(fenetre,mouseMove,lache);
			val3_1.drawMe(fenetre);


			val3_2.deplacer(fenetre,mouseMove,lache);
			val3_2.drawMe(fenetre);

			val5_1.deplacer(fenetre,mouseMove,lache);
			val5_1.drawMe(fenetre);

int sommeb = CalculSomme(somme,val1_1);
cout <<sommeb;
		/*	inZoneCalculSomme(fenetre,val1_1,somme);
			inZoneCalculSomme(fenetre,val1_2,somme);
			inZoneCalculSomme(fenetre,val1_3,somme);
			inZoneCalculSomme(fenetre,val2_1,somme);
			inZoneCalculSomme(fenetre,val2_2,somme);
			inZoneCalculSomme(fenetre,val2_3,somme);
			inZoneCalculSomme(fenetre,val3_1,somme);
			inZoneCalculSomme(fenetre,val3_2,somme);*/

			if(total== 0)	{
				fenetre.Draw(gagne);
				Clock.Reset();
			}
			if(total!= 0)	{
				fenetre.Draw(instructions);
				Clock.Reset();
			}

		 fenetre.Display();

		 if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre))
				ecranSuivant=pays.changerEcran(fenetre,JEU_PEROU,JEU_PEROU,PEROU) ;
	}

	return ecranSuivant;

}

bool JeuPerou::autoriseBouger(Piece & obj) {

	if(&obj == &val1_1) {
		 if(!(val1_3.estBougeable()) && !(val1_2.estBougeable()) && !(val2_1.estBougeable())
						&& !(val2_2.estBougeable()) && !(val2_3.estBougeable()) && !(val3_1.estBougeable())
						&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
					 return true;
				else
						return false;
	}

	else if(&obj == &val1_2) {
		 if(!(val1_1.estBougeable()) && !(val1_3.estBougeable()) && !(val2_1.estBougeable())
						&& !(val2_2.estBougeable()) && !(val2_3.estBougeable()) && !(val3_1.estBougeable())
						&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
					 return true;
				else
						return false;
	}

	else if(&obj == &val1_3) {
		 if(!(val1_1.estBougeable()) && !(val1_2.estBougeable()) && !(val2_1.estBougeable())
						&& !(val2_2.estBougeable()) && !(val2_3.estBougeable()) && !(val3_1.estBougeable())
						&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
					 return true;
				else
						return false;
	}

	else if(&obj == &val2_1) {
		 if(!(val1_1.estBougeable()) && !(val1_2.estBougeable()) && !(val1_3.estBougeable())
						&& !(val2_2.estBougeable()) && !(val2_3.estBougeable()) && !(val3_1.estBougeable())
						&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
					 return true;
				else
						return false;
		}

	else if(&obj == &val2_2) {
		 if(!(val1_1.estBougeable()) && !(val1_2.estBougeable()) && !(val1_3.estBougeable())
						&& !(val2_1.estBougeable()) && !(val2_3.estBougeable()) && !(val3_1.estBougeable())
						&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
					 return true;
				else
						return false;
	}

	else if(&obj == &val2_3) {
		 if(!(val1_1.estBougeable()) && !(val1_2.estBougeable()) && !(val1_3.estBougeable())
						&& !(val2_1.estBougeable()) && !(val2_2.estBougeable()) && !(val3_1.estBougeable())
						&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
					 return true;
				else
						return false;
	}

	else if(&obj == &val3_1) {
		 if(!(val1_1.estBougeable()) && !(val1_2.estBougeable()) && !(val1_3.estBougeable())
						&& !(val2_1.estBougeable()) && !(val2_2.estBougeable()) && !(val2_3.estBougeable())
						&& !(val3_2.estBougeable()) && !(val5_1.estBougeable()))
					 return true;
				else
						return false;
	}

	else if(&obj == &val3_2) {
			 if(!(val1_1.estBougeable()) && !(val1_2.estBougeable()) && !(val1_3.estBougeable())
					&& !(val2_1.estBougeable()) && !(val2_2.estBougeable()) && !(val2_3.estBougeable())
					&& !(val3_1.estBougeable()) && !(val5_1.estBougeable()))
				 return true;
			else
					return false;
		}

	else // val5_1
	{
		 if(!(val1_1.estBougeable()) && !(val1_2.estBougeable()) && !(val1_3.estBougeable())
				&& !(val2_1.estBougeable()) && !(val2_2.estBougeable()) && !(val2_3.estBougeable())
				&& !(val3_1.estBougeable()) && !(val3_2.estBougeable()))
			 return true;
		else
				return false;
	}


//		return (  (!(val1_1.estBougeable()) && !(val1_2.estBougeable())) &&
//			   ( !(val1_3.estBougeable()) && !(val2_1.estBougeable()) ) &&
//			   ( !(val2_2.estBougeable()) && !(val2_3.estBougeable()) ) &&
//			  ( !(val3_1.estBougeable()) && !(val3_2.estBougeable())) );

}

bool JeuPerou::inZone(sf::RenderWindow &fenetre, Piece piece){
	float rapport = fenetre.GetWidth()/fenetre.GetHeight();
	float posX= piece.getPosX();
	float posY= piece.getPosY();
	if (posX>=80*rapport && posX<=385*rapport && posY>=357*rapport && posY<=540*rapport)
		return true;
	else return false;
}

int JeuPerou::CalculSomme(int somme,Piece piece){
	return somme+piece.getValeur();
}

void JeuPerou::inZoneCalculSomme(sf::RenderWindow &fenetre, Piece piece,int somme){
	if (inZone(fenetre,piece))
		somme=CalculSomme(somme,piece);
	cout << somme;
}
