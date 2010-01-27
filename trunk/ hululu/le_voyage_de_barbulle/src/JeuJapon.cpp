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
	sf::Clock Clock2;
	Clock.Reset();
	int ecranSuivant = JEUJAPON; // par défault, celui de l'écran actif
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
	tabCarte.push_back(Carte("le_voyage_de_barbulle/img/japon/hanafuda_02-04.png","le_voyage_de_barbulle/img/japon/hanafuda_02-04C.png", 2, 4, 1) );


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

	// IMAGES ///////////////////////////////////////////////////////////////////////////
	//Bravo

	sf::Sprite Bravo;
	Bravo.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/bravo.png"));
	Bravo.SetPosition((fenetre.GetWidth())/3.5, ((fenetre.GetHeight())/1.25));

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

	//INSTRUCTION ////////////////////////////////////////////////////////////////////////
	sf::Sprite Instruction1;
	Instruction1.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/instruction1.png"));
	Instruction1.SetPosition((fenetre.GetWidth())/5, ((fenetre.GetHeight())/35));

	sf::Sprite Instruction2;
	Instruction2.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/instruction2.png"));
	Instruction2.SetPosition((fenetre.GetWidth())/5, ((fenetre.GetHeight())/35));

	sf::Sprite Instruction3;
	Instruction3.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/instruction3.png"));
	Instruction3.SetPosition((fenetre.GetWidth())/5, ((fenetre.GetHeight())/50));

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// instruction
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 40.f))
	cerr << "Erreur lors du chargement de la police";

	//Texte//////////////////////////////////////////////////////////////////////////////////////
		sf::String text1(L"11111111111");
		text1.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text1.SetColor(sf::Color::Color(120,15,0));
		text1.SetSize(40.f);
		text1.SetFont(MyFont);

		sf::String text2(L"22222222222222222");
		text2.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text2.SetColor(sf::Color::Color(120,15,0));
		text2.SetSize(40.f);
		text2.SetFont(MyFont);

		sf::String text3(L"33333333333333333333");
		text3.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text3.SetColor(sf::Color::Color(120,15,0));
		text3.SetSize(40.f);
		text3.SetFont(MyFont);

		sf::String text4(L"444444444444444444444");
		text4.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text4.SetColor(sf::Color::Color(120,15,0));
		text4.SetSize(40.f);
		text4.SetFont(MyFont);

		sf::String text5(L"5555555555555555555");
		text5.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text5.SetColor(sf::Color::Color(120,15,0));
		text5.SetSize(40.f);
		text5.SetFont(MyFont);

		sf::String text6(L"66666666666666666");
		text6.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text6.SetColor(sf::Color::Color(120,15,0));
		text6.SetSize(40.f);
		text6.SetFont(MyFont);

		sf::String text7(L"77777777777777777");
		text7.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text7.SetColor(sf::Color::Color(120,15,0));
		text7.SetSize(40.f);
		text7.SetFont(MyFont);

		sf::String text8(L"8888888888888");
		text8.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text8.SetColor(sf::Color::Color(120,15,0));
		text8.SetSize(40.f);
		text8.SetFont(MyFont);

		sf::String text9(L"9999999999999");
		text9.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text9.SetColor(sf::Color::Color(120,15,0));
		text9.SetSize(40.f);
		text9.SetFont(MyFont);

		sf::String text10(L"1110000000000");
		text10.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text10.SetColor(sf::Color::Color(120,15,0));
		text10.SetSize(40.f);
		text10.SetFont(MyFont);

		sf::String text11(L"11_11");
		text11.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text11.SetColor(sf::Color::Color(120,15,0));
		text11.SetSize(40.f);
		text11.SetFont(MyFont);

		sf::String text12(L"1212121212");
		text12.Move((fenetre.GetWidth())/2, ((fenetre.GetHeight())/70));
		text12.SetColor(sf::Color::Color(120,15,0));
		text12.SetSize(40.f);
		text12.SetFont(MyFont);


	//COMPTEUR ///////////////////////////////////////////////////////////////////////////

	sf::String nbCarte("4");
	nbCarte.Move((fenetre.GetWidth())/4, (fenetre.GetHeight())/1.25);
	nbCarte.SetColor(sf::Color::Color(120,15,0));

	sf::Sprite Sakura;
	Sakura.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/Sakura.png"));
	Sakura.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/1.3));
	Sakura.Resize(100, 100);

	sf::Sprite Sakura2;
	Sakura2.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/Sakura.png"));
	Sakura2.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/30));
	Sakura2.Resize(100, 100);


	//AIDE //////////////////////////////////////////////////////////////////////////////
	Bouton Barbulle;
	Barbulle.initBouton("le_voyage_de_barbulle/img/japon/barbulle_japon.png","le_voyage_de_barbulle/img/japon/barbulle_japon.png" );
	Barbulle.redimensionner(0.2);
	Barbulle.placer((fenetre.GetWidth())/1.2, ((fenetre.GetHeight())/70));



	// FONT//////////////////////////////////////////////////////////////////////////////


	sf::Event event;

	// # création d'une vue sur la fenêtre
			sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
			fenetre.SetView(vue);



	///AFFICHAGE FENETRE////////////////////////////////
			int nbATrouver=4;
			int courant=1;
			bool lu = false;
			Clock2.Reset();


				while(fenetre.IsOpened() && (ecranSuivant==JEUJAPON))
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
								if(tabCarte[l].estClique(fenetre)){
									// la carte est cliquée
									if (tabCarte[l].getMois()==courant && tabCarte[l].getEtat()==1 && courant!=13){
										tabCarte[l].changerEtat(); // on change son état

										//je décrémente le compteur
											std::ostringstream compteur;
											nbATrouver--;
											// on récupère le nombre d'erreur a trouver dans le flux
											compteur << nbATrouver;
											// on en extrait une chaîne de caractères
											std::string Texte = compteur.str();
											nbCarte.SetText(Texte);
											Clock.Reset();

										}


								}


								tabCarte[l].carteVisible().drawMe(fenetre);

								l++;


							}

							if(Barbulle.estClique(fenetre)){
									if(courant==1){
										fenetre.Draw(text1);
									}
									if(courant==2){
										fenetre.Draw(text2);
									}
									if(courant==3){
										fenetre.Draw(text3);
									}
									if(courant==4){
										fenetre.Draw(text4);
									}
									if(courant==5){
										fenetre.Draw(text5);
									}
									if(courant==6){
										fenetre.Draw(text6);
									}
									if(courant==7){
										fenetre.Draw(text7);
									}
									if(courant==8){
										fenetre.Draw(text8);
									}
									if(courant==9){
										fenetre.Draw(text9);
									}
									if(courant==10){
										fenetre.Draw(text10);
									}
									if(courant==11){
										fenetre.Draw(text11);
									}
									if(courant==12){
										fenetre.Draw(text12);
									}
							}

							if(nbATrouver==0 && Clock.GetElapsedTime()<4)
							{
							fenetre.Draw(Bravo);
							}
							else if(nbATrouver==0 && courant!=13){
								Clock.Reset();
								nbATrouver=4;
								std::ostringstream compteur;
								// on récupère le nombre d'erreur a trouver dans le flux
								compteur << nbATrouver;
								// on en extrait une chaîne de caractères
								std::string Texte = compteur.str();
								nbCarte.SetText(Texte);
								if (courant==1)
									Janvier.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/01V.png"));
								if (courant==2)
									Fevrier.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/02V.png"));
								if (courant==3)
									Mars.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/03V.png"));
								if (courant==4)
									Avril.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/04V.png"));
								if (courant==5)
									Mai.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/05V.png"));
								if (courant==6)
									Juin.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/06V.png"));
								if (courant==7)
									Juillet.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/07V.png"));
								if (courant==8)
									Aout.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/08V.png"));
								if (courant==9)
									Septembre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/09V.png"));
								if (courant==10)
									Octobre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/10V.png"));
								if (courant==11)
									Novembre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/11V.png"));
								if (courant==12)
									Decembre.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/japon/12V.png"));


								courant++;

							}


							pays.dessinerPage(fenetre);
							fenetre.Draw(nbCarte);
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
							fenetre.Draw(Sakura);
							fenetre.Draw(Sakura2);
							Barbulle.drawMe(fenetre);



							//Instructions ///////////////////////////////////////
						if (lu==false) {
							if (Clock2.GetElapsedTime()<4){
								fenetre.Draw(Instruction1);
								}
							else if (Clock2.GetElapsedTime()<8){
								fenetre.Draw(Instruction2);
								}
							else if (Clock2.GetElapsedTime()<12){
								fenetre.Draw(Instruction3);
								}
							else {
								lu=true;
							}
						}
						if(lu==true){
							fenetre.Draw(Instruction3);
						}

							fenetre.Display();

					if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && courant!=13)
							ecranSuivant=pays.changerEcran(fenetre,JEUJAPON,JEUJAPON,HISTOIREJAPON);
					if (courant==13){
						if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre))
							ecranSuivant=pays.changerEcran(fenetre,JEUJAPON,JAPONGAGNE,HISTOIREJAPON);
					}


					if (fenetre.GetInput().IsKeyDown(sf::Key::O))
							ecranSuivant=JEUJAPON;

					if ((fenetre.GetInput().IsKeyDown(sf::Key::Space)))
							ecranSuivant=JEUJAPON;



					}
				return ecranSuivant;
}

