/*
 * ItalieGagne.cpp
 *
 *  Created on: 28 janv. 2010
 *      Author: anthony
 */

#include "ItalieGagne.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ecran.h"

#include "Page.h"
#include "Bouton.h"
#include "AccueilPays.h"
#include "DefineEcrans.h"
#include "PoleSud_Porte.h"

ItalieGagne::ItalieGagne() {
	// TODO Auto-generated constructor stub

}

ItalieGagne::~ItalieGagne() {
	// TODO Auto-generated destructor stub
}


int ItalieGagne::run(sf::RenderWindow &fenetre)
{
	int ecranSuivant = ITALIEGAGNE;
	sf::Clock Clock;
	Clock.Reset();
	Page pays;



	// FONT//////////////////////////////////////////////////////////////////////////
	sf::Event event;

	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	sf::Sprite Conservateur;
	Conservateur.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/conservateur_content.png"));
	Conservateur.SetPosition((fenetre.GetWidth())/9, ((fenetre.GetHeight())/2));
//	Sakura.Resize(400, 400);

	sf::Sprite Barbulle;
	Barbulle.SetImage(Ecran::MonManager.GetImage("le_voyage_de_barbulle/img/italie/barbulle_italie.png"));
	Barbulle.SetPosition((fenetre.GetWidth())/6.5, ((fenetre.GetHeight())/8));
	Barbulle.Scale(0.75, 0.75);

	//Objet gagné /////////////////////////////////////////////////////////////////////////////

	PoleSud_Porte::blason.initDessin("le_voyage_de_barbulle/img/objets/blason.png");
	PoleSud_Porte::blason.placerDessin((fenetre.GetWidth())/2, ((fenetre.GetHeight())/4));



	// FONT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// instruction
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("le_voyage_de_barbulle/img/font/Cursive_standard.ttf", 80.f))
	cerr << "Erreur lors du chargement de la police";

	//Texte//////////////////////////////////////////////////////////////////////////////////////
	sf::String text(L"Bravo, tu as trouvé un Objet.");
	text.Move((fenetre.GetWidth())/30, ((fenetre.GetHeight())/1.9));
	text.SetColor(sf::Color::Color(120,15,0));
	text.SetSize(80.f);
	text.SetFont(MyFont);

	////////////////////////////////

			while(fenetre.IsOpened() && (ecranSuivant == ITALIEGAGNE))
			{
				while (fenetre.GetEvent(event)) {
					// # Instanciation de tous les éc fermeture de la fenetre
					// si echap ou fermeture manuelle
					if (event.Type == sf::Event::Closed)
						fenetre.Close();
					else if (event.Type==sf::Event::KeyReleased && event.Key.Code == sf::Key::Escape)
						fenetre.Close();
				}



				fenetre.Clear(sf::Color(255, 200, 122));

				fenetre.Draw(Conservateur);
				fenetre.Draw(Barbulle);
				fenetre.Draw(text);
				pays.dessinerPage(fenetre);
				PoleSud_Porte::blason.setTrouve(true);
				PoleSud_Porte::blason.dessinerObjet(fenetre);
				fenetre.Display();

				if (fenetre.GetInput().IsMouseButtonDown(sf::Mouse::Left) && pays.menuActif(fenetre) )
					ecranSuivant=pays.changerEcran(fenetre,ITALIEGAGNE,MAPPEMONDE,ITALIEGAGNE) ; //ecranSuivant = HistoireJapon (5), ecranCourant = Japon (3),
																		   //ecranPrecedent = Mapmonde (1)

				if (fenetre.GetInput().IsKeyDown(sf::Key::O))
					ecranSuivant=MAPPEMONDE;

			}



	return ecranSuivant;
}
