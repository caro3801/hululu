/*
 * JeuJapon.cpp
 *
 *  Created on: 15 déc. 2009
 *      Author: pollet
 */
#include <iostream>
#include <sstream>
using namespace std;

#include "JeuJapon.h"
#include "Page.h"
#include "HistoireJapon.h"
#include "Person2D.h"
#include "Mapmonde.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "DefineEcrans.h"
#include <vector>

#include "Carte.h"


JeuJapon::JeuJapon() {
	// TODO Auto-generated constructor stub
}

JeuJapon::~JeuJapon() {
	// TODO Auto-generated destructor stub
}


int JeuJapon::run(sf::RenderWindow &fenetre)
{
	/////Déclaration/////////////////////////////
	sf::Clock Clock; //Horloge
	Clock.Reset();
	int ecranSuivant = 6; // par défault, celui de l'écran actif
	Page pays;


	vector<Carte> tabCarte;


	// Declaration CARTES //////////////////////
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-01.png","le_voyage_de_barbulle/img/japon/hanafuda_09-01C.png", 9, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-01.png","le_voyage_de_barbulle/img/japon/hanafuda_03-01C.png", 3, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-03.png","le_voyage_de_barbulle/img/japon/hanafuda_02-03C.png", 2, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-01.png","le_voyage_de_barbulle/img/japon/hanafuda_01-01C.png", 1, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-01.png","le_voyage_de_barbulle/img/japon/hanafuda_12-01C.png", 12, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-01.png","le_voyage_de_barbulle/img/japon/hanafuda_06-01C.png", 6, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-02.png","le_voyage_de_barbulle/img/japon/hanafuda_07-02C.png", 7, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-01.png","le_voyage_de_barbulle/img/japon/hanafuda_10-01C.png", 10, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-02.png","le_voyage_de_barbulle/img/japon/hanafuda_02-02C.png", 2, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-04.png","le_voyage_de_barbulle/img/japon/hanafuda_03-04C.png", 3, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-01.png","le_voyage_de_barbulle/img/japon/hanafuda_04-01C.png", 4, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-01.png","le_voyage_de_barbulle/img/japon/hanafuda_08-01C.png", 8, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-02.png","le_voyage_de_barbulle/img/japon/hanafuda_10-02C.png", 10, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-03.png","le_voyage_de_barbulle/img/japon/hanafuda_04-03C.png", 4, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-04.png","le_voyage_de_barbulle/img/japon/hanafuda_04-04C.png", 4, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-02.png","le_voyage_de_barbulle/img/japon/hanafuda_11-02C.png", 11, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-02.png","le_voyage_de_barbulle/img/japon/hanafuda_05-02C.png", 5, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-03.png","le_voyage_de_barbulle/img/japon/hanafuda_01-03C.png", 1, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-02.png","le_voyage_de_barbulle/img/japon/hanafuda_09-02C.png", 9, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-04.png","le_voyage_de_barbulle/img/japon/hanafuda_05-04C.png", 5, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-03.png","le_voyage_de_barbulle/img/japon/hanafuda_07-03C.png", 7, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-02.png","le_voyage_de_barbulle/img/japon/hanafuda_06-02C.png", 6, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-04.png","le_voyage_de_barbulle/img/japon/hanafuda_01-04C.png", 1, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-04.png","le_voyage_de_barbulle/img/japon/hanafuda_10-04C.png", 10, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-01.png","le_voyage_de_barbulle/img/japon/hanafuda_11-01C.png", 11, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-03.png","le_voyage_de_barbulle/img/japon/hanafuda_06-03C.png", 6, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-04.png","le_voyage_de_barbulle/img/japon/hanafuda_11-04C.png", 11, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_01-02.png","le_voyage_de_barbulle/img/japon/hanafuda_01-02C.png", 1, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-01.png","le_voyage_de_barbulle/img/japon/hanafuda_09-01C.png", 9, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-02.png","le_voyage_de_barbulle/img/japon/hanafuda_08-02C.png", 8, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-01.png","le_voyage_de_barbulle/img/japon/hanafuda_07-01C.png", 7, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-01.png","le_voyage_de_barbulle/img/japon/hanafuda_02-01C.png", 2, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_04-02.png","le_voyage_de_barbulle/img/japon/hanafuda_04-02C.png", 4, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_07-04.png","le_voyage_de_barbulle/img/japon/hanafuda_07-04C.png", 7, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-03.png","le_voyage_de_barbulle/img/japon/hanafuda_12-03C.png", 12, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_10-03.png","le_voyage_de_barbulle/img/japon/hanafuda_10-03C.png", 10, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-03.png","le_voyage_de_barbulle/img/japon/hanafuda_08-03C.png", 8, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_11-03.png","le_voyage_de_barbulle/img/japon/hanafuda_11-03C.png", 11, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-03.png","le_voyage_de_barbulle/img/japon/hanafuda_05-03C.png", 5, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-03.png","le_voyage_de_barbulle/img/japon/hanafuda_03-03C.png", 3, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_06-04.png","le_voyage_de_barbulle/img/japon/hanafuda_06-04C.png", 6, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_09-03.png","le_voyage_de_barbulle/img/japon/hanafuda_09-03C.png", 9, 3, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_08-04.png","le_voyage_de_barbulle/img/japon/hanafuda_08-04C.png", 8, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_03-02.png","le_voyage_de_barbulle/img/japon/hanafuda_03-02C.png", 3, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-02.png","le_voyage_de_barbulle/img/japon/hanafuda_12-02C.png", 12, 2, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_05-01.png","le_voyage_de_barbulle/img/japon/hanafuda_05-01C.png", 5, 1, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_12-04.png","le_voyage_de_barbulle/img/japon/hanafuda_12-04C.png", 12, 4, 1) );
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-04.png","le_voyage_de_barbulle/img/japon/hanafuda_02-01C.png", 2, 4, 1) );


	// PLACEMENT CARTE
	int R1=0;
	int R2=0;
	int R3=0;
	int R4=0;
	int R5=0;
	int R6=0;

	int i=0;

	while (i<48){
		if (i<8){
		tabCarte[i].placer((fenetre.GetWidth()/2)+R1, (fenetre.GetHeight()/8));
		R1=R1+70;
		i++;
		}
		else if (i>7 and i<16){
		tabCarte[i].placer((fenetre.GetWidth()/2)+R2, (fenetre.GetHeight()/8)+100);
		R2=R2+70;
		i++;
		}
		else if (i>15 and i<24){
		tabCarte[i].placer((fenetre.GetWidth()/2)+R3, (fenetre.GetHeight()/8)+200);
		R3=R3+70;
		i++;
		}
		else if (i>23 and i<32){
		tabCarte[i].placer((fenetre.GetWidth()/2)+R4, (fenetre.GetHeight()/8)+300);
		R4=R4+70;
		i++;
		}
		else if (i>31 and i<40){
		tabCarte[i].placer((fenetre.GetWidth()/2)+R5, (fenetre.GetHeight()/8)+400);
		R5=R5+70;
		i++;
		}
		else {
		tabCarte[i].placer((fenetre.GetWidth()/2)+R6, (fenetre.GetHeight()/8)+500);
		R6=R6+70;
		i++;
		}

		}

	// MOIS /////////////////////////////////////////////////////////////////////////////

	sf::Sprite Janvier;
	Janvier.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/01.png"));
	Janvier.SetPosition((fenetre.GetWidth())/9, (fenetre.GetHeight())/4);
	int E=60;

	sf::Sprite Fevrier;
	Fevrier.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/02.png"));
	Fevrier.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Mars;
	Mars.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/03.png"));
	Mars.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Avril;
	Avril.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/04.png"));
	Avril.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Mai;
	Mai.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/05.png"));
	Mai.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Juin;
	Juin.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/06.png"));
	Juin.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/4)+E);
	E=0;

	sf::Sprite Juillet;
	Juillet.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/07.png"));
	Juillet.SetPosition((fenetre.GetWidth())/3.5, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Aout;
	Aout.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/08.png"));
	Aout.SetPosition((fenetre.GetWidth())/3.5, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Septembre;
	Septembre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/09.png"));
	Septembre.SetPosition((fenetre.GetWidth())/3.5, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Octobre;
	Octobre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/10.png"));
	Octobre.SetPosition((fenetre.GetWidth())/3.5, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Novembre;
	Novembre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/11.png"));
	Novembre.SetPosition((fenetre.GetWidth())/3.5, ((fenetre.GetHeight())/4)+E);
	E+=60;

	sf::Sprite Decembre;
	Decembre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/12.png"));
	Decembre.SetPosition((fenetre.GetWidth())/3.5, ((fenetre.GetHeight())/4)+E);
	E+=60;


	//Janvier.Resize((fenetre.GetWidth())/4, (fenetre.GetHeight())/4);

	// FONT//////////////////////////////////////////////////////////////////////////////


	sf::Event event;

	// # création d'une vue sur la fenêtre
			sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
			fenetre.SetView(vue);



	///AFFICHAGE FENETRE////////////////////////////////

				while(fenetre.IsOpened() && (ecranSuivant==6))
					{
						while (fenetre.GetEvent(event)) {
								    // # Instanciation de tous les écrans fermeture de la fenetre
									// si echap ou fermeture manuelle
									if (event.Type == sf::Event::Closed)
										fenetre.Close();
									else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
										fenetre.Close();
								}

							fenetre.Clear(sf::Color(255, 200, 122));


							int l=0;
							while (l<48){
								if(tabCarte[l].estClique(fenetre)) // la carte est cliquée
								tabCarte[l].changerEtat(); // on change son état
								tabCarte[l].carteVisible().drawMe(fenetre);
								l++;
							}






							pays.dessinerPage(fenetre);
							fenetre.Draw(Janvier);
							fenetre.Draw(Fevrier);
							fenetre.Draw(Mars);
							fenetre.Draw(Avril);
							fenetre.Draw(Mai);
							fenetre.Draw(Juin);
							fenetre.Draw(Juillet);
							fenetre.Draw(Aout);
							fenetre.Draw(Septembre);
							fenetre.Draw(Octobre);
							fenetre.Draw(Novembre);
							fenetre.Draw(Decembre);
							fenetre.Display();


					if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
							ecranSuivant=pays.changerEcran(fenetre,JEUJAPON,JAPON,MAPPEMONDE) ;

					if (fenetre.GetInput().IsKeyDown(sf::Key::O))
							ecranSuivant=JEUJAPON;

					if ((fenetre.GetInput().IsKeyDown(sf::Key::Space)))
							ecranSuivant=JEUJAPON;



					}
				return ecranSuivant;
}

