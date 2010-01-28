/*
 * Mapmonde.cpp
 *
 *  Created on: 10 déc. 2009
 *      Author: pirhoo
 */

#include <iostream>
using namespace std;

// LIB SFML/////////////////////////////
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Mapmonde.h"
#include "Person2D.h"
#include "Collision.h"
#include "Bouton.h"
#include "Musique.h"

#include "DefineEcrans.h"


int Mapmonde::run(sf::RenderWindow &fenetre)
{
	bool derriere = false;
	int ecranSuivant = MAPPEMONDE; // par défault, celui de l'écran actif
	bool colj = false;
	bool colt = false;
	bool colc = false;
	bool colp = false;
	bool coli = false;
	bool colpo = false;
	bool cola = false; //Pour gerer les collisions de

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
	sf::Sprite SpriteCarte(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/mapemonde_fond.png"));
	SpriteCarte.SetPosition(0.f, 0.f);
	SpriteCarte.Resize(fenetre.GetWidth(), fenetre.GetHeight());

	sf::Sprite titre(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/titreMap.png"));
	titre.SetPosition(fenetre.GetWidth()/2 - titre.GetSize().x/2, 0.f);

	// # image de marque pays canada non actif
	sf::Sprite canada_na(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays.png"));
	canada_na.SetPosition(((90*SpriteCarte.GetSize().x)/1000),((146*SpriteCarte.GetSize().y)/650));

	// # image de marque pays canada actif
	sf::Sprite canada_a(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"));
	canada_a.SetPosition(((90*SpriteCarte.GetSize().x)/1000),((146*SpriteCarte.GetSize().y)/650));


	// # image de marque pays japon non actif
	sf::Sprite japon_na(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays.png"));
	japon_na.SetPosition(((840*SpriteCarte.GetSize().x)/1000),((170*SpriteCarte.GetSize().y)/650));

	// # image de marque pays japon actif
	sf::Sprite japon_a(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"));
	japon_a.SetPosition(((840*SpriteCarte.GetSize().x)/1000),((170*SpriteCarte.GetSize().y)/650));


	// # image de marque pays tanzanie non actif
	sf::Sprite tanzanie_na(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays.png"));
	tanzanie_na.SetPosition(((519*SpriteCarte.GetSize().x)/1000),((405*SpriteCarte.GetSize().y)/650));
	//tanzanie_na.Resize(30,30);
	// # image de marque pays tanzanie actif
	sf::Sprite tanzanie_a(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"));
	tanzanie_a.SetPosition(((519*SpriteCarte.GetSize().x)/1000),((405*SpriteCarte.GetSize().y)/650));
	//tanzanie_a.Resize(30,30);

	// # image de marque pays australie non actif
	sf::Sprite australie_na(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays.png"));
	australie_na.SetPosition(((878*SpriteCarte.GetSize().x)/1000),((485*SpriteCarte.GetSize().y)/650));

	// # image de marque pays australie actif
	sf::Sprite australie_a(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"));
	australie_a.SetPosition(((878*SpriteCarte.GetSize().x)/1000),((485*SpriteCarte.GetSize().y)/650));

	// # image de marque pays perou non actif
	sf::Sprite perou_na(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays.png"));
	perou_na.SetPosition(((151*SpriteCarte.GetSize().x)/1000),((369*SpriteCarte.GetSize().y)/650));

	// # image de marque pays perou actif
	sf::Sprite perou_a(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"));
	perou_a.SetPosition(((151*SpriteCarte.GetSize().x)/1000),((369*SpriteCarte.GetSize().y)/650));

	// # image de marque pays  italie non actif
	sf::Sprite italie_na(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays.png"));
	italie_na.SetPosition(((475*SpriteCarte.GetSize().x)/1000),((175*SpriteCarte.GetSize().y)/650));

	// # image de marque pays  italie actif
	sf::Sprite italie_a(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"));
	italie_a.SetPosition(((475*SpriteCarte.GetSize().x)/1000),((175*SpriteCarte.GetSize().y)/650));

	// # image de marque pays pole non actif
	sf::Sprite pole_na(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays.png"));
	pole_na.SetPosition(((620*SpriteCarte.GetSize().x)/1000), SpriteCarte.GetSize().y - 80 );

	// # image de marque pays pole actif
	sf::Sprite pole_a(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"));
	pole_a.SetPosition(((620*SpriteCarte.GetSize().x)/1000), SpriteCarte.GetSize().y - 80);

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// instruction
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard_BOLD.ttf", 25.f))
		cerr << "Erreur lors du chargement de la police";

	//textes pour chacun des pays
	sf::String texte_canada("Canada: ce pays n'est encore pas disponible...",MyFont,20.f);
	texte_canada.Move(canada_a.GetPosition().x - texte_canada.GetRect().GetWidth()/2 + 60, canada_a.GetPosition().y - 30);
	texte_canada.SetColor(sf::Color(40,66,89));

	//.Move(.GetPosition().x - texte_.GetRect().GetWidth()/2  , .GetPosition().y - 30);

	sf::String texte_perou("Appuie sur Espace pour aller au Perou",MyFont,20.f);
	texte_perou.Move(perou_a.GetPosition().x - texte_perou.GetRect().GetWidth()/2  , perou_a.GetPosition().y + 30);
	texte_perou.SetColor(sf::Color(40,66,89));

	sf::String texte_italie("Appuie sur Espace pour aller en Italie",MyFont,20.f);
	texte_italie.Move(italie_a.GetPosition().x - texte_italie.GetRect().GetWidth()/2  , italie_a.GetPosition().y - 30);
	texte_italie.SetColor(sf::Color(40,66,89));

	sf::String texte_tanzanie("Tanzanie: ce pays n'est pas encore disponible...", MyFont,20.f);
	texte_tanzanie.Move(tanzanie_a.GetPosition().x - texte_tanzanie.GetRect().GetWidth()/2  , tanzanie_a.GetPosition().y + 30);
	texte_tanzanie.SetColor(sf::Color(40,66,89));

	sf::String texte_pole("Appuie sur Espace pour aller en Antarctique",MyFont,20.f);
	texte_pole.Move(pole_a.GetPosition().x - texte_pole.GetRect().GetWidth()/2 -20  , pole_a.GetPosition().y + 30);
	texte_pole.SetColor(sf::Color(40,66,89));

	sf::String texte_japon("Appuie sur Espace pour aller au Japon",MyFont,20.f);
	texte_japon.Move(japon_a.GetPosition().x - texte_japon.GetRect().GetWidth()/2  , japon_a.GetPosition().y - 30);
	texte_japon.SetColor(sf::Color(40,66,89));

	sf::String texte_australie("Appuie sur Espace pour aller en Australie",MyFont,20.f);
	texte_australie.Move(australie_a.GetPosition().x - texte_australie.GetRect().GetWidth()/2  , australie_a.GetPosition().y - 30);
	texte_australie.SetColor(sf::Color(40,66,89));

	// # image garçon
	Person2D garcon_sp(50.f, 100.f, fenetre.GetWidth()/15, 6, 4); // le personnage parcoud 1/10 de la largeur de la fenêtre à chaque pas

	// positione le garçon dans le vide horizontalement, à gauche de la fenêtre
	// mais au centre, verticalement
	garcon_sp.SetPosition(-100.f, ( fenetre.GetHeight() - garcon_sp.getHeightCase() ) / 2.f);

	// charge l'image
	garcon_sp.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/sprite/sprite_g_walk_petit.png")); // la taille du personnage dépend de la fenêtre

	// clipage du sprite
	// c-à-d on n'affiche que les partie du sprite qui nous intérèssent
	garcon_sp.initClip();

	// # image Barbule
	Person2D barbule_sp(50.f, 100.f, fenetre.GetWidth()/15, 6, 4);
	barbule_sp.SetColor(sf::Color(255, 255, 255, 255));
	barbule_sp.SetPosition(-100.f, ( fenetre.GetHeight() - garcon_sp.getHeightCase() - 20 ) / 2.f);
	barbule_sp.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/sprite/sprite_monstre_petit.png"));
	barbule_sp.initClip();


	// RENDU/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);


	// Pour que le programme ne se termine pas :)
	sf::Event event;
	while(fenetre.IsOpened() && (ecranSuivant == MAPPEMONDE) )
	{
		// EVENEMENTS //////////////////////////////////////////
		while (fenetre.GetEvent(event)) {
		    // # Instanciation de tous les éc fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close ();
			else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
				fenetre.Close();
		}


		// ANIMATIONS //////////////////////////////////////////
		// # on avance le bonhome vers la droite pour commencer
		 if( ( garcon_sp.GetPosition().x < 50.f) and not garcon_sp.inMoveTo(Person2D::RIGHT) ) { // initialise le mouvement
				garcon_sp.walk(Person2D::RIGHT, 450);
				barbule_sp.walk(Person2D::RIGHT, 450);
		 }
		 else if(garcon_sp.inMoveTo(Person2D::RIGHT)) {// poursuit le mouvement
				garcon_sp.walk(Person2D::RIGHT, 450);
				barbule_sp.walk(Person2D::RIGHT, 450);
		 }


		 if( ( garcon_sp.GetPosition().x > fenetre.GetWidth()-garcon_sp.GetSize().x) and not garcon_sp.inMoveTo(Person2D::LEFT) ) { // initialise le mouvement
				garcon_sp.walk(Person2D::LEFT, 450);
				barbule_sp.walk(Person2D::LEFT, 450);
		 }
		 else if(garcon_sp.inMoveTo(Person2D::LEFT)) {
				garcon_sp.walk(Person2D::LEFT, 450);
				barbule_sp.walk(Person2D::LEFT, 450);
		 }

		 if( ( garcon_sp.GetPosition().y < 0.f) and not garcon_sp.inMoveTo(Person2D::BOTTOM) ) { // initialise le mouvement
				garcon_sp.walk(Person2D::BOTTOM, 450);
				barbule_sp.walk(Person2D::BOTTOM, 450);
		 }
		 else if(garcon_sp.inMoveTo(Person2D::BOTTOM)) {
				garcon_sp.walk(Person2D::BOTTOM, 450);
				barbule_sp.walk(Person2D::BOTTOM, 450);
		 }

		 if( ( garcon_sp.GetPosition().y > fenetre.GetWidth()-garcon_sp.GetSize().y) and not garcon_sp.inMoveTo(Person2D::TOP) ) { // initialise le mouvement
				garcon_sp.walk(Person2D::TOP, 450);
				barbule_sp.walk(Person2D::TOP, 450);
		 }
		 else if(garcon_sp.inMoveTo(Person2D::TOP)) {
				garcon_sp.walk(Person2D::TOP, 450);
				barbule_sp.walk(Person2D::TOP, 450);
		 }


		if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) || ( garcon_sp.inMoveTo(Person2D::LEFT) ) ) {
			garcon_sp.walk(Person2D::LEFT, 450);
			barbule_sp.walk(Person2D::LEFT, 450);
			derriere=false;
			colj=Collision::cercleTest(garcon_sp,japon_a);
			colc=Collision::cercleTest(garcon_sp,canada_a);
			colt=Collision::cercleTest(garcon_sp,tanzanie_a);
			colp=Collision::cercleTest(garcon_sp,perou_a);
			cola=Collision::cercleTest(garcon_sp,australie_a);
			coli=Collision::cercleTest(garcon_sp,italie_a);
			colpo=Collision::cercleTest(garcon_sp,pole_a);
		}

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Right)) || ( garcon_sp.inMoveTo(Person2D::RIGHT) ) ) {
			garcon_sp.walk(Person2D::RIGHT, 450);
			barbule_sp.walk(Person2D::RIGHT, 450);
			derriere=false;
			colj=Collision::cercleTest(garcon_sp,japon_a);
			colc=Collision::cercleTest(garcon_sp,canada_a);
			colt=Collision::cercleTest(garcon_sp,tanzanie_a);
			colp=Collision::cercleTest(garcon_sp,perou_a);
			cola=Collision::cercleTest(garcon_sp,australie_a);
			coli=Collision::cercleTest(garcon_sp,italie_a);
			colpo=Collision::cercleTest(garcon_sp,pole_a);
		}

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Up)) || ( garcon_sp.inMoveTo(Person2D::TOP) ) ) {
			garcon_sp.walk(Person2D::TOP, 450) ;
			barbule_sp.walk(Person2D::TOP, 450);
			derriere=false;
			colj=Collision::cercleTest(garcon_sp,japon_a);
			colc=Collision::cercleTest(garcon_sp,canada_a);
			colt=Collision::cercleTest(garcon_sp,tanzanie_a);
			colp=Collision::cercleTest(garcon_sp,perou_a);
			cola=Collision::cercleTest(garcon_sp,australie_a);
			coli=Collision::cercleTest(garcon_sp,italie_a);
			colpo=Collision::cercleTest(garcon_sp,pole_a);
		}

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Down)) || ( garcon_sp.inMoveTo(Person2D::BOTTOM) ) ) {
			garcon_sp.walk(Person2D::BOTTOM, 450);
			barbule_sp.walk(Person2D::BOTTOM, 450);
			derriere=true;
			colj=Collision::cercleTest(garcon_sp,japon_a);
			colc=Collision::cercleTest(garcon_sp,canada_a);
			colt=Collision::cercleTest(garcon_sp,tanzanie_a);
			colp=Collision::cercleTest(garcon_sp,perou_a);
			cola=Collision::cercleTest(garcon_sp,australie_a);
			coli=Collision::cercleTest(garcon_sp,italie_a);
			colpo=Collision::cercleTest(garcon_sp,pole_a);
		}


	//	fenetre.Clear(sf::Color(255, 255, 255));

		// CARTE
		fenetre.Draw(SpriteCarte) ;

		// INSTRUCTIONS

		//ITALIE
		if(coli)  {
			fenetre.Draw(texte_italie);
			fenetre.Draw(italie_a);
			if (fenetre.GetInput().IsKeyDown(sf::Key::Space))
					ecranSuivant=ITALIE;
		}
		else	fenetre.Draw(italie_na);

		//CANADA
		if(colc) {
			fenetre.Draw(canada_a);
			fenetre.Draw(texte_canada);
		}
		else	fenetre.Draw(canada_na);

		//JAPON
		if(colj) {
			fenetre.Draw(texte_japon);
			fenetre.Draw(japon_a);
			if (fenetre.GetInput().IsKeyDown(sf::Key::Space))
				ecranSuivant=JAPON;
		}
		else	fenetre.Draw(japon_na);

		//PEROU
		if(colp) {
			fenetre.Draw(perou_a);
			fenetre.Draw(texte_perou);
			if (fenetre.GetInput().IsKeyDown(sf::Key::Space))
					ecranSuivant=PEROU;
		}
		else	fenetre.Draw(perou_na);

		//TANZANIE
		if(colt) {
			fenetre.Draw(tanzanie_a);
			fenetre.Draw(texte_tanzanie);
		}
		else	fenetre.Draw(tanzanie_na);

		//AUSTRALIE
		if(cola) {
			fenetre.Draw(australie_a);
			fenetre.Draw(texte_australie);

			if (fenetre.GetInput().IsKeyDown(sf::Key::Space))
					ecranSuivant=AUSTRALIE_INTRO;
		}
		else	fenetre.Draw(australie_na);

		//POLE
		if(colpo) {
			fenetre.Draw(pole_a);
			fenetre.Draw(texte_pole);
			if (fenetre.GetInput().IsKeyDown(sf::Key::Space))
					ecranSuivant=POLESUD_PORTE;
		}
		else	fenetre.Draw(pole_na);


		// GARÇON ET BARBULLE
		if(derriere) {
			fenetre.Draw(barbule_sp);
			fenetre.Draw(garcon_sp);
		}
		else {
			fenetre.Draw(garcon_sp);
			fenetre.Draw(barbule_sp);
		}

		fenetre.Draw(titre);
		// toujours pour actualiser le rendu (et en fin de boucle surtout) !
		fenetre.Display();

	}

	return  ecranSuivant;
}

