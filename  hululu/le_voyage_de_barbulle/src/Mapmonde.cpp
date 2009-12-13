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

#include "Mapmonde.h"
#include "Person2D.h"
#include "Collision.h"
#include "Bouton.h"


int Mapmonde::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = 1; // par défault, celui de l'écran actif
	bool colj, colt, colc, colp, coli, colpo, cola = false; //Pour gerer les collisions de
															//chaque pays
	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image garçon
	sf::Image garcon_img;
	if (!garcon_img.LoadFromFile("le_voyage_de_barbulle/img/sprite/sprite_g_walk_petit.png"))
		cerr << "Erreur lors du chargement de l'image.";

	// # image de fond
	sf::Image carte;
	if (!carte.LoadFromFile("le_voyage_de_barbulle/img/histoire/mapemonde_fond.png"))
		cerr << "Erreur lors du chargement de l'image.";

	// # image de position de pays non actif
	sf::Image imgmp_na;
	if (!imgmp_na.LoadFromFile("le_voyage_de_barbulle/img/histoire/marque_pays.png"))
		cerr << "Erreur lors du chargement de l'image.";

	// # image de position de pays actif
		sf::Image imgmp_a;
		if (!imgmp_a.LoadFromFile("le_voyage_de_barbulle/img/histoire/marque_pays_a.png"))
			cerr << "Erreur lors du chargement de l'image.";

	// SPRITES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image garçon
	Person2D garcon_sp(50.f, 100.f, fenetre.GetWidth()/15, 6, 4); // le personnage parcoud 1/10 de la largeur de la fenêtre à chaque pas
	garcon_sp.SetColor(sf::Color(255, 255, 255, 255));

	// positione le garçon dans le vide horizontalement, à gauche de la fenêtre
	// mais au centre, verticalement
	garcon_sp.SetPosition(-100.f, ( fenetre.GetHeight() - garcon_sp.getHeightCase() ) / 2.f);

	// charge l'image
	garcon_sp.SetImage(garcon_img); // la taille du personnage dépend de la fenêtre
	//garcon_sp.Resize(fenetre.GetWidth()/3, fenetre.GetHeight()/2); /* on ne redimensione pas avec le même indice
																 //   * puisque le sprite à 6 cases en largeur
																 //   * et 4 en hauteur */

	// clipage du sprite
	// c-à-d on n'affiche que les partie du sprite qui nous intérèssent
	garcon_sp.initClip();

	// # image de fond
	sf::Sprite SpriteCarte(carte);
	SpriteCarte.SetPosition(0.f, 0.f);
	SpriteCarte.Resize(fenetre.GetWidth(), fenetre.GetHeight());
	// # image de marque pays canada non actif
	sf::Sprite canada_na(imgmp_na);
	canada_na.SetPosition(((70*SpriteCarte.GetSize().x)/1000),((146*SpriteCarte.GetSize().y)/650));
	//canada_na.Resize(30,30);
	// # image de marque pays canada actif
	sf::Sprite canada_a(imgmp_a);
	canada_a.SetPosition(((70*SpriteCarte.GetSize().x)/1000),((146*SpriteCarte.GetSize().y)/650));
	//canada_a.Resize(30,30);

	// # image de marque pays japon non actif
	sf::Sprite japon_na(imgmp_na);
	japon_na.SetPosition(((840*SpriteCarte.GetSize().x)/1000),((170*SpriteCarte.GetSize().y)/650));
	//japon_na.Resize(30,30);
	// # image de marque pays japon actif
	sf::Sprite japon_a(imgmp_a);
	japon_a.SetPosition(((840*SpriteCarte.GetSize().x)/1000),((170*SpriteCarte.GetSize().y)/650));
	//japon_a.Resize(30,30);

	// # image de marque pays tanzanie non actif
	sf::Sprite tanzanie_na(imgmp_na);
	tanzanie_na.SetPosition(((519*SpriteCarte.GetSize().x)/1000),((405*SpriteCarte.GetSize().y)/650));
	//tanzanie_na.Resize(30,30);
	// # image de marque pays tanzanie actif
	sf::Sprite tanzanie_a(imgmp_a);
	tanzanie_a.SetPosition(((519*SpriteCarte.GetSize().x)/1000),((405*SpriteCarte.GetSize().y)/650));
	//tanzanie_a.Resize(30,30);

	// # image de marque pays australie non actif
	sf::Sprite australie_na(imgmp_na);
	australie_na.SetPosition(((878*SpriteCarte.GetSize().x)/1000),((485*SpriteCarte.GetSize().y)/650));
	//australie_na.Resize(30,30);
	// # image de marque pays australie actif
	sf::Sprite australie_a(imgmp_a);
	australie_a.SetPosition(((878*SpriteCarte.GetSize().x)/1000),((485*SpriteCarte.GetSize().y)/650));
	//australie_a.Resize(30,30);

	// # image de marque pays perou non actif
	sf::Sprite perou_na(imgmp_na);
	perou_na.SetPosition(((151*SpriteCarte.GetSize().x)/1000),((369*SpriteCarte.GetSize().y)/650));
	//perou_na.Resize(30,30);
	// # image de marque pays perou actif
	sf::Sprite perou_a(imgmp_a);
	perou_a.SetPosition(((151*SpriteCarte.GetSize().x)/1000),((369*SpriteCarte.GetSize().y)/650));
	//perou_a.Resize(30,30);

	// # image de marque pays  italie non actif
	sf::Sprite italie_na(imgmp_na);
	italie_na.SetPosition(((475*SpriteCarte.GetSize().x)/1000),((175*SpriteCarte.GetSize().y)/650));
	//italie_na.Resize(30,30);
	// # image de marque pays  italie actif
	sf::Sprite italie_a(imgmp_a);
	italie_a.SetPosition(((475*SpriteCarte.GetSize().x)/1000),((175*SpriteCarte.GetSize().y)/650));
	//italie_a.Resize(30,30);

	// # image de marque pays pole non actif
	sf::Sprite pole_na(imgmp_na);
	pole_na.SetPosition(((619*SpriteCarte.GetSize().x)/1000),((597*SpriteCarte.GetSize().y)/650));
	//pole_na.Resize(30,30);
	// # image de marque pays pole actif
	sf::Sprite pole_a(imgmp_a);
	pole_a.SetPosition(((619*SpriteCarte.GetSize().x)/1000),((597*SpriteCarte.GetSize().y)/650));
	//pole_a.Resize(30,30);

//	Bouton back_icon;
//	back_icon.initBouton()
//	sf::Sprite back_icon ;
//	back_icon.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/back_icon.png"));
//	back_icon.SetPosition((fenetre.GetWidth()-100),(fenetre.GetHeight()-100));
//	back_icon.Resize(50,50);

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// instruction
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50))
		cerr << "Erreur lors du chargement de la police";

	sf::String text("Fleches haut, bas, gauche et droite pour deplacer le personnage.");
	text.Move(10, 600);
	text.SetColor(sf::Color::Blue);
	text.SetSize(25.f);
	text.SetFont(MyFont);

	//textes pour chacun des pays
	sf::String texte_canada("Appuyez sur Espace pour aller au Canada",MyFont,20.f);
	texte_canada.Move( (fenetre.GetHeight()/3),(fenetre.GetWidth()/3));
	texte_canada.SetColor(sf::Color::Blue);

	sf::String texte_perou("Appuyez sur Espace pour aller au Perou",MyFont,18.f);
	texte_perou.Move( (fenetre.GetHeight()/3),(fenetre.GetWidth()/3));
	texte_perou.SetColor(sf::Color::Blue);

	sf::String texte_italie("Appuyez sur Espace pour aller en Italie",MyFont,18.f);
	texte_italie.Move( (fenetre.GetHeight()/3),(fenetre.GetWidth()/3));
	texte_italie.SetColor(sf::Color::Blue);

	sf::String texte_tanzanie("Appuyez sur Espace pour aller en Tanzanie",MyFont,18.f);
	texte_tanzanie.Move( (fenetre.GetHeight()/3),(fenetre.GetWidth()/3));
	texte_tanzanie.SetColor(sf::Color::Blue);

	sf::String texte_pole("Appuyez sur Espace pour aller en Antarctique",MyFont,18.f);
	texte_pole.Move( (fenetre.GetHeight()/3),(fenetre.GetWidth()/3));
	texte_pole.SetColor(sf::Color::Blue);

	sf::String texte_japon("Appuyez sur Espace pour aller au Japon",MyFont,18.f);
	texte_japon.Move( (fenetre.GetHeight()/3),(fenetre.GetWidth()/3));
	texte_japon.SetColor(sf::Color::Blue);

	sf::String texte_australie("Appuyez sur Espace pour aller en Australie",MyFont,18.f);
	texte_australie.Move( (fenetre.GetHeight()/3),(fenetre.GetWidth()/3));
	texte_australie.SetColor(sf::Color::Blue);

	// RENDU/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # création d'une vue sur la fenêtre
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	// Pour que le programme ne se termine pas :)
	sf::Event event;
	while(fenetre.IsOpened())
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
		 }
		 else if(garcon_sp.inMoveTo(Person2D::RIGHT)) {// poursuit le mouvement
				garcon_sp.walk(Person2D::RIGHT, 450);
		 }


		if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) || ( garcon_sp.inMoveTo(Person2D::LEFT) ) ) {
			garcon_sp.walk(Person2D::LEFT, 450);
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
			colj=Collision::cercleTest(garcon_sp,japon_a);
			colc=Collision::cercleTest(garcon_sp,canada_a);
			colt=Collision::cercleTest(garcon_sp,tanzanie_a);
			colp=Collision::cercleTest(garcon_sp,perou_a);
			cola=Collision::cercleTest(garcon_sp,australie_a);
			coli=Collision::cercleTest(garcon_sp,italie_a);
			colpo=Collision::cercleTest(garcon_sp,pole_a);
		}


	//	fenetre.Clear(sf::Color(255, 255, 255));

		fenetre.Draw(SpriteCarte) ;
		// on dessine le Sprite sur la fenetre de rendu
		fenetre.Draw(garcon_sp);
		fenetre.Draw(back_icon);
		// on dessine les instructions
		fenetre.Draw(text);

		//ITALIE
		if(coli)  {
			fenetre.Draw(texte_italie);
			fenetre.Draw(italie_a);
			if (fenetre.GetInput().IsKeyDown(sf::Key::Space))
					return ecranSuivant=2;
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
		}
		else	fenetre.Draw(japon_na);

		//PEROU
		if(colp) {
			fenetre.Draw(perou_a);
			fenetre.Draw(texte_perou);
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
		}
		else	fenetre.Draw(australie_na);

		//POLE
		if(colpo) {
			fenetre.Draw(pole_a);
			fenetre.Draw(texte_pole);
		}
		else	fenetre.Draw(pole_na);

		// toujours pour actualiser le rendu (et en fin de boucle surtout) !
		fenetre.Display();

	}

	return  ecranSuivant;
}

