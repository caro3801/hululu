/*
 * GagneJeu.cpp
 *
 *  Created on: 27 janv. 2010
 *      Author: pollet
 */

#include "GagneJeu.h"

// WIKI SFML //////////////////////////
#include "Bouton.h"
#include "AccueilPays.h"
#include "Page.h"
#include "PoleSud_Porte.h"
#include "DefineEcrans.h"

GagneJeu::GagneJeu() {
	// TODO Auto-generated constructor stub

}

GagneJeu::~GagneJeu() {
	// TODO Auto-generated destructor stub
}

int GagneJeu::run(sf::RenderWindow &fenetre) {

	int ecranSuivant = GAGNE_JEU;
	sf::Clock Clock;
	Clock.Reset();

	//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Page pays;

	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Font cursiveFont;
		if (!cursiveFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 50.f))
					cerr << "Erreur lors du chargement de la police" << endl;

	sf::String text("Bravo, tu as ajoute tous les objets ! \n Je vais pouvoir rentrer chez moi ! \n Merci !");
			text.Move(fenetre.GetWidth()/10,fenetre.GetHeight()/1.8);
			text.SetColor(sf::Color::Blue);
			text.SetSize(22.f);
			text.SetFont(cursiveFont);
	sf::Event event;

	sf::Sprite monstre(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/histoire/monstre_gagne.png"));
		monstre.SetPosition(fenetre.GetWidth()/3,fenetre.GetHeight()/2);

	// # création d'une vue sur la fenêtre - !! Puisqu'une vue a été créee sur l'ecran précédent (Mapemonde) obligé de recréer une vue
	//pour toutes les fenetres suivantes, ou images et sprites ne s'affichent pas!
	//a voir pour trouver une autre solution : suppression vue ? re-definition de la vue par defaut ?
	//ou on crée une autre vue a chaque fois.


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
				}
		fenetre.Clear(sf::Color(255, 255, 255));
		pays.dessinerPage(fenetre);
		fenetre.Draw(text);
		fenetre.Draw(monstre);
		fenetre.Display();

		if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) && Clock.GetElapsedTime() > 1)
			return ecranSuivant=pays.changerEcran(fenetre,GAGNE_JEU,MENU_0,MENU_0) ; //ecranSuivant = jeuItalie (4), ecranCourant = Italie (2),
																   //ecranPrecedent = Mapmonde (1)

	}

	return ecranSuivant;

}
