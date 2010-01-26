/*
 * JeuPerou.cpp
 *
 *  Created on: 5 déc. 2009
 *      Author: talotte&antho
 */
#include "JeuPerou.h"
#include "Page.h"
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

	val1_1.setValeur(1); val1_1.initBouton(piece1,piece1); val1_1.redimensionner(0.75); val1_1.placer((fenetre.GetWidth()*8/12),(fenetre.GetHeight()*9/11));val1_1.decalageSouris(25.0,25.0);
	val1_2.setValeur(1); val1_2.initBouton(piece1,piece1); val1_2.redimensionner(0.75); val1_2.placer((fenetre.GetWidth()*9/12),(fenetre.GetHeight()*9/11));val1_2.decalageSouris(25.0,25.0);
	val1_3.setValeur(1); val1_3.initBouton(piece1,piece1); val1_3.redimensionner(0.75); val1_3.placer((fenetre.GetWidth()*10/12),(fenetre.GetHeight()*9/11));val1_3.decalageSouris(25.0,25.0);
	val2_1.setValeur(2); val2_1.initBouton(piece2,piece2); val2_1.redimensionner(0.75); val2_1.placer((fenetre.GetWidth()*8/12),(fenetre.GetHeight()*7/11));val2_1.decalageSouris(25.0,25.0);
	val3_1.setValeur(3); val3_1.initBouton(piece3,piece3); val3_1.redimensionner(0.75); val3_1.placer((fenetre.GetWidth()*9/12),(fenetre.GetHeight()*7/11));val3_1.decalageSouris(25.0,25.0);
	val2_2.setValeur(2); val2_2.initBouton(piece2,piece2); val2_2.redimensionner(0.75); val2_2.placer((fenetre.GetWidth()*10/12),(fenetre.GetHeight()*7/11));val2_2.decalageSouris(25.0,25.0);
	val2_3.setValeur(2); val2_3.initBouton(piece2,piece2); val2_3.redimensionner(0.75); val2_3.placer((fenetre.GetWidth()*10/12),(fenetre.GetHeight()*8/11));val2_3.decalageSouris(25.0,25.0);
	val5_1.setValeur(5); val5_1.initBouton(piece5,piece5); val5_1.redimensionner(0.75); val5_1.placer((fenetre.GetWidth()*8/12),(fenetre.GetHeight()*8/11));val5_1.decalageSouris(25.0,25.0);
	val3_2.setValeur(3); val3_2.initBouton(piece3,piece3); val3_2.redimensionner(0.75); val3_2.placer((fenetre.GetWidth()*9/12),(fenetre.GetHeight()*8/11));val3_2.decalageSouris(25.0,25.0);
}

int JeuPerou::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 6;
	sf::Clock Clock; //Horloge
	Clock.Reset();
	bool mouseMove = false;
	//Booléen pour savoir si la souris est en mouvement: utile pour déplacer des objets a la souris

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


		JeuPerou::creerPieces( fenetre,"le_voyage_de_barbulle/img/sprite/piece1.png","le_voyage_de_barbulle/img/sprite/piece2.png","le_voyage_de_barbulle/img/sprite/piece3.png","le_voyage_de_barbulle/img/sprite/piece5.png");
	///AFFICHAGE FENETRE////////////////////////////////
		sf::Event event;
			while(fenetre.IsOpened())
				{
					while (fenetre.GetEvent(event)) {
							    // # Instanciation de tous les écrans fermeture de la fenetre
								// si echap ou fermeture manuelle
								if (event.Type == sf::Event::Closed)
									fenetre.Close();
								else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
									fenetre.Close();
								//Si l'evenement est de type: souris en mouvement, mouseMove est vrai (utile pour les boutonMove)
								else if(event.Type==sf::Event::MouseMoved)
									mouseMove=true;
							}

					fenetre.Clear(sf::Color(255, 255, 255));
					fenetre.Draw(fond);
					pays.dessinerPage(fenetre);


					val1_1.deplacer(fenetre,mouseMove);
					val1_1.drawMe(fenetre);
					val1_2.deplacer(fenetre,mouseMove);
					val1_2.drawMe(fenetre);
					val1_3.deplacer(fenetre,mouseMove);
					val1_3.drawMe(fenetre);
					val2_1.deplacer(fenetre,mouseMove);
					val2_1.drawMe(fenetre);
					val3_1.deplacer(fenetre,mouseMove);
					val3_1.drawMe(fenetre);
					val2_2.deplacer(fenetre,mouseMove);
					val2_2.drawMe(fenetre);
					val2_3.deplacer(fenetre,mouseMove);
					val2_3.drawMe(fenetre);
					val5_1.deplacer(fenetre,mouseMove);
					val5_1.drawMe(fenetre);
					val3_2.deplacer(fenetre,mouseMove);
					val3_2.drawMe(fenetre);

				 fenetre.Display();

				 if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
				 			return ecranSuivant=pays.changerEcran(fenetre,6,6,5) ; //ecranSuivant = jeuPerou (5), ecranCourant = Perou (5),
				 																   //ecranPrecedent = Perou (4)

			}

	return ecranSuivant;

}

