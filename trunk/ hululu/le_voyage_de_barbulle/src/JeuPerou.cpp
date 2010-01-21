/*
 * JeuPerou.cpp
 *
 *  Created on: 5 déc. 2009
 *      Author: talotte&antho
 */
#include "JeuPerou.h"

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
void JeuPerou::placerFond(sf::RenderWindow* fenetre,sf::Image img)
{
	fond.SetImage(img);
	fond.SetPosition(0.f,0.f);
	fenetre->Draw(fond);

}

void JeuPerou::creerPieces(sf::RenderWindow* fenetre,const std::string & piece1,const std::string & piece2,const std::string & piece5,
		const std::string & piece3)
{

	val1_1.setValeur(1); val1_1.initPiece(fenetre,piece1); val1_1.placerPiece(1106,493);
	val1_2.setValeur(1); val1_2.initPiece(fenetre,piece1); val1_2.placerPiece(1006,493);
	val1_3.setValeur(1); val1_3.initPiece(fenetre,piece1); val1_3.placerPiece(906,493);
	val2_1.setValeur(2); val2_1.initPiece(fenetre,piece2); val2_1.placerPiece(806,493);
	val3_1.setValeur(3); val3_1.initPiece(fenetre,piece3); val3_1.placerPiece(806,650);
	val2_2.setValeur(2); val2_2.initPiece(fenetre,piece2); val2_2.placerPiece(1106,592);
	val2_3.setValeur(2); val2_3.initPiece(fenetre,piece2); val2_3.placerPiece(1006,592);
	val5_1.setValeur(5); val5_1.initPiece(fenetre,piece5); val5_1.placerPiece(906,592);
	val3_2.setValeur(3); val3_2.initPiece(fenetre,piece3); val3_2.placerPiece(806,592);


}

int JeuPerou::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = 5;

	//IMAGES////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// # image de fond
		sf::Sprite fond ;
		fond.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/perou/jeuPerou1.png"));
		fond.SetPosition(0.f, 0.f);
		fond.Resize((fenetre.GetWidth()), (fenetre.GetHeight()));

//		sf::Sprite back_icon ;
//		back_icon.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/back_icon.png"));
//		back_icon.SetPosition((fenetre.GetWidth()-100),(fenetre.GetHeight()-100));
//		back_icon.Resize(30,30);

		// # création d'une vue sur la fenêtre
		sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
		fenetre.SetView(vue);


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
							}

					fenetre.Clear(sf::Color(255, 255, 255));
					fenetre.Draw(fond);
//					fenetre.Draw(back_icon);
					JeuPerou::creerPieces( &fenetre,"le_voyage_de_barbulle/img/sprite/piece1.png","le_voyage_de_barbulle/img/sprite/piece2.png","le_voyage_de_barbulle/img/sprite/piece5.png",
							"le_voyage_de_barbulle/img/sprite/piece3.png");

				//dessin de la fenêtre
				 fenetre.Display();

			}

	return ecranSuivant;

}

