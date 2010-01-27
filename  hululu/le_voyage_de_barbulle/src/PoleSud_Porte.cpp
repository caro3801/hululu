/*
 * PoleSud_Porte.cpp
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#include "PoleSud_Porte.h"
#include <iostream>
using namespace std;

// WIKI SFML //////////////////////////
#include "BoutonMove.h"
#include "AccueilPays.h"
#include "Page.h"
#include "Bouton.h"
#include "Objet.h"

PoleSud_Porte::PoleSud_Porte() {

}

PoleSud_Porte::~PoleSud_Porte() {
}

Objet PoleSud_Porte::blason;
Objet PoleSud_Porte::weta;
Objet PoleSud_Porte::poncho;
Objet PoleSud_Porte::lampion;

bool PoleSud_Porte::ZoneWeta(sf::RenderWindow &fenetre,float rapportW, float rapportH){
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (posX>=(522*rapportW) && posX<=(730*rapportW) && posY>=(370*rapportH) && posY<=(480*rapportH))
		return true;
	else return false;
}
bool PoleSud_Porte::ZonePoncho(sf::RenderWindow &fenetre,float rapportW, float rapportH){
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (posX>=(654*rapportW) && posX<=(804*rapportW) && posY>=(798*rapportH) && posY<=(1086*rapportH))
		return true;
	else return false;
}
bool PoleSud_Porte::ZoneBlason(sf::RenderWindow &fenetre,float rapportW, float rapportH){
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (posX>=(824*rapportW) && posX<=(986*rapportW) && posY>=(500*rapportH) && posY<=(636*rapportH))
		return true;
	else return false;
}
bool PoleSud_Porte::ZoneLanterne(sf::RenderWindow &fenetre,float rapportW, float rapportH){
	float posX = fenetre.GetInput().GetMouseX();
	float posY = fenetre.GetInput().GetMouseY();
	if (posX>=(982*rapportW) && posX<=(1068*rapportW) && posY>=(650*rapportH) && posY<=(804*rapportH))
		return true;
	else return false;
}

int PoleSud_Porte::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = POLESUD_PORTE;
	sf::Clock Clock;
	Clock.Reset();
	bool mouseMove = false;
	bool lache = true;

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fondplacer
	sf::Sprite fond ;
	fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_sans_objets.png"));
	fond.SetPosition(0.f, 0.f);
	fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// # images de porte
	sf::Sprite porte_blason ;
	porte_blason.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_blason.png"));
	porte_blason.SetPosition(0.f, 0.f);
	porte_blason.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	sf::Sprite porte_weta ;
	porte_weta.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_weta.png"));
	porte_weta.SetPosition(0.f, 0.f);
	porte_weta.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	sf::Sprite porte_lampion ;
	porte_lampion.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_lampion.png"));
	porte_lampion.SetPosition(0.f, 0.f);
	porte_lampion.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	sf::Sprite porte_poncho ;
	porte_poncho.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/porte_poncho.png"));
	porte_poncho.SetPosition(0.f, 0.f);
	porte_poncho.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

	// # images d'emplacement
	sf::Sprite emplacement_vide1 ;
	emplacement_vide1.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/emplacement_vide.png"));
	emplacement_vide1.SetPosition((fenetre.GetWidth()/1.18), fenetre.GetHeight()/10 );

	sf::Sprite emplacement_vide2 ;
	emplacement_vide2.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/emplacement_vide.png"));
	emplacement_vide2.SetPosition((fenetre.GetWidth()/1.18), fenetre.GetHeight()/10 + ((emplacement_vide2.GetSize().y)));

	sf::Sprite emplacement_vide3 ;
	emplacement_vide3.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/emplacement_vide.png"));
	emplacement_vide3.SetPosition((fenetre.GetWidth()/1.18), fenetre.GetHeight()/10 + ((emplacement_vide2.GetSize().y)*2));

	sf::Sprite emplacement_vide4 ;
	emplacement_vide4.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/pole/emplacement_vide.png"));
	emplacement_vide4.SetPosition((fenetre.GetWidth()/1.18), fenetre.GetHeight()/10 + ((emplacement_vide2.GetSize().y)*3));

	poncho.initBouton("le_voyage_de_barbulle/img/objets/poncho_emplacement.png","le_voyage_de_barbulle/img/objets/poncho_a.png");
	poncho.placer(emplacement_vide1.GetPosition().x + 5,emplacement_vide1.GetPosition().y + 2);
	poncho.decalageSouris(poncho.getTailleX()/2,poncho.getTailleY()/2);

	weta.initBouton("le_voyage_de_barbulle/img/objets/weta_emplacement.png","le_voyage_de_barbulle/img/objets/weta_a.png");
	weta.placer(emplacement_vide2.GetPosition().x + 4,emplacement_vide2.GetPosition().y + 10);
	weta.decalageSouris((weta.getTailleX()/1),weta.getTailleY()/2);


	blason.initBouton("le_voyage_de_barbulle/img/objets/blason_emplacement.png","le_voyage_de_barbulle/img/objets/blason_a.png");
	blason.placer(emplacement_vide3.GetPosition().x + 6,emplacement_vide3.GetPosition().y + 7);
	blason.decalageSouris(blason.getTailleX()/2,blason.getTailleY()/2);


	lampion.initBouton("le_voyage_de_barbulle/img/objets/lampion_emplacement.png","le_voyage_de_barbulle/img/objets/lampion_a.png");
	lampion.placer(emplacement_vide4.GetPosition().x + 14,emplacement_vide4.GetPosition().y + 9);
	lampion.decalageSouris(lampion.getTailleX()/2,lampion.getTailleY()/2);
	//definition zones emplacement vide
float rapportW = fond.GetSize().x/2000;
float rapportH = fond.GetSize().y/1614;


 bool ZoneVideWeta = false;
 bool ZoneVidePoncho = false;
 bool ZoneVideBlason = false;
 bool ZoneVideLanterne = false;
 bool dessineBlason = false;
 bool dessinePoncho = false;
 bool dessineWeta = false;
 bool dessineLampion = false;
	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Event event;

	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	////////////////////////////////

	while(fenetre.IsOpened())
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

		fenetre.Clear(sf::Color(255, 255, 255));
		fenetre.Draw(fond);
		pays.dessinerPage(fenetre);
		fenetre.Draw(emplacement_vide1);
		fenetre.Draw(emplacement_vide2);
		fenetre.Draw(emplacement_vide3);
		fenetre.Draw(emplacement_vide4);

		ZoneVideWeta = ZoneWeta(fenetre,rapportW, rapportH);
		ZoneVidePoncho = ZonePoncho(fenetre,rapportW, rapportH);
		ZoneVideBlason = ZoneBlason(fenetre,rapportW,rapportH);
		ZoneVideLanterne = ZoneLanterne(fenetre,rapportW, rapportH);

		if( PoleSud_Porte::poncho.estClique(fenetre) ) {
			cout << "autorise" << endl;
			PoleSud_Porte::poncho.setABouger(true);
		}

		if(  PoleSud_Porte::weta.estClique(fenetre) ) {
			PoleSud_Porte::weta.setABouger(true);
		}

		if( PoleSud_Porte::blason.estClique(fenetre) ) {
			PoleSud_Porte::blason.setABouger(true);
		}

		if( PoleSud_Porte::lampion.estClique(fenetre) ) {
			PoleSud_Porte::lampion.setABouger(true);
		}

		if( !(poncho.estPlace())) {
			PoleSud_Porte::poncho.deplacer(fenetre,mouseMove,lache);
			PoleSud_Porte::poncho.drawMe(fenetre);
		}

		if( !(weta.estPlace())) {
			PoleSud_Porte::weta.deplacer(fenetre,mouseMove,lache);
			PoleSud_Porte::weta.drawMe(fenetre);
		}
		if( !(lampion.estPlace())) {
			PoleSud_Porte::lampion.deplacer(fenetre,mouseMove,lache);
			PoleSud_Porte::lampion.drawMe(fenetre);
		}

		if( !(blason.estPlace())) {
			PoleSud_Porte::blason.deplacer(fenetre,mouseMove,lache);
			PoleSud_Porte::blason.drawMe(fenetre);
			}

		if( (blason.enDeplacement(fenetre) && ZoneVideBlason)) {
			dessineBlason=true;
			blason.setPlace(dessineBlason);
			blason.plusBouger(true);
		}
		if( (lampion.enDeplacement(fenetre) && ZoneVideLanterne)) {
					dessineLampion=true;
					lampion.setPlace(dessineLampion);
					lampion.plusBouger(true);
				}
		if( (poncho.enDeplacement(fenetre) && ZoneVidePoncho)) {
					dessinePoncho=true;
					poncho.setPlace(dessinePoncho);
					poncho.plusBouger(true);
				}

		if( (weta.enDeplacement(fenetre) && ZoneVideWeta)) {
					dessineWeta=true;
					weta.setPlace(dessineWeta);
					weta.plusBouger(true);
				}

		if(blason.estPlace()) {
			blason.placer(-100,-100);
			fenetre.Draw(porte_blason);
		}

		if(lampion.estPlace()) {
			lampion.placer(-100,-100);
			fenetre.Draw(porte_lampion);
		}

		if(poncho.estPlace()) {
			poncho.placer(-100,-100);
			fenetre.Draw(porte_poncho);
		}

		if(weta.estPlace()) {
			weta.placer(-100,-100);
			fenetre.Draw(porte_weta);
		}

		fenetre.Display();

		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			return ecranSuivant=pays.changerEcran(fenetre,POLESUD_PORTE,POLESUD_PORTE,MAPPEMONDE) ;

	}

	return ecranSuivant;

}

bool PoleSud_Porte::autoriseBouger(Objet & obj) {

	if(&obj == &weta)
		return ( !lampion.estBougeable() && !blason.estBougeable() && !poncho.estBougeable() );

	else if(&obj == &lampion)
		return ( !blason.estBougeable() && !poncho.estBougeable() && !weta.estBougeable());

	else if(&obj == &blason)
		return ( !lampion.estBougeable() && !poncho.estBougeable() && !weta.estBougeable());

	else // poncho
		return ( !lampion.estBougeable() && !blason.estBougeable() && !weta.estBougeable());
}