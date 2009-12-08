//============================================================================
// Name        : Test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Test SFML
//============================================================================

#include <iostream>
using namespace std;

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Person2D.h"

int main()
{

	//sf::RenderWindow fenetre(sf::VideoMode::GetMode(0), "Test animation personnage", sf::Style::Fullscreen);
	sf::RenderWindow fenetre(sf::VideoMode(900, 687, 32),  "Test animation personnage");

//IMAGES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// on charge une image

	//image garcon
	sf::Image garcon_img;

	if (!garcon_img.LoadFromFile("Test_animation/img/sprite/sprite_g_walk_petit.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}
	//image de fond
	sf::Image carte;
	if (!carte.LoadFromFile("Test_animation/img/sprite/mapemondev02.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 sf::Sprite SpriteCarte(carte);
	 SpriteCarte.SetPosition(0.f, 0.f);


	Person2D garcon_sp(50.f, 100.f, 50, 6, 4);
	garcon_sp.SetColor(sf::Color(255, 255, 255, 255));

	// position du sprite
	garcon_sp.SetX(50.f);
	garcon_sp.SetY( ( fenetre.GetHeight() - garcon_sp.getHeightCase() ) / 2.f); // centre le sprite

	// c'est le "centre relatif" de l'objet
	garcon_sp.SetCenter(0, 0);


	// On charge l'image (texture) source du sprite...
	// c'est l'image du garçon chargée plus haut
	garcon_sp.SetImage(garcon_img);

	// On récupère les dimensions du sprite
	 //float largeur  = garcon_sp.GetSize().x;
	 //float hauteur = garcon_sp.GetSize().y;

	// clipage du sprite
	// c-à-d on n'affiche que les partie du sprite qui nous intérèsse
	garcon_sp.initClip();


	// création d'une vue
	sf::View vue(sf::FloatRect(0, 0, fenetre.GetWidth(), fenetre.GetHeight()) );
	fenetre.SetView(vue);

	// les instructions
	sf::Font MyFont;
	if (!MyFont.LoadFromFile("Test_animation/img/font/Cursive_standard.ttf", 50))
	{
		cout << "Erreur lors du chargement de la police";
	}

	sf::String text("Fleches haut, bas, gauche et droite pour deplacer le personnage, touches plus et moins pour \nzoomer. Q, D, Z, S pour deplacer la camera.");
	text.Move(10, 600);
	text.SetColor(sf::Color::Blue);
	text.SetSize(25.f);
	text.SetFont(MyFont);

	// Pour que le programme ne se termine pas :)
	sf::Event event;
	while(fenetre.IsOpened())
	{
        while (fenetre.GetEvent(event))
        {
			// # fermeture de la fenetre
			// si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();

			if (event.Key.Code == sf::Key::Escape)
				fenetre.Close();
        }

		// # deplacement du Sprite

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) or ( garcon_sp.inMoveTo(Person2D::LEFT) ) )
			garcon_sp.walk(Person2D::LEFT, 1000);

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Right)) or ( garcon_sp.inMoveTo(Person2D::RIGHT) ) )
			garcon_sp.walk(Person2D::RIGHT, 1000);

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Up)) or ( garcon_sp.inMoveTo(Person2D::TOP) ) )
			garcon_sp.walk(Person2D::TOP, 1000);

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Down)) or ( garcon_sp.inMoveTo(Person2D::BOTTOM) ) )
			garcon_sp.walk(Person2D::BOTTOM, 1000);

        // Déplace la vue
        float Offset = 200.f * fenetre.GetFrameTime();
        if (fenetre.GetInput().IsKeyDown(sf::Key::Z))    vue.Move( 0,      -Offset);
        if (fenetre.GetInput().IsKeyDown(sf::Key::S))  vue.Move( 0,       Offset);
        if (fenetre.GetInput().IsKeyDown(sf::Key::Q))  vue.Move(-Offset,  0);
        if (fenetre.GetInput().IsKeyDown(sf::Key::D)) vue.Move( Offset,  0);

        // Zoom sur la vue
        if (fenetre.GetInput().IsKeyDown(sf::Key::Add))      vue.Zoom(1.001f);
        if (fenetre.GetInput().IsKeyDown(sf::Key::Subtract)) vue.Zoom(0.999f);

		// efface l'ecran
		//fenetre.Clear(sf::Color(255, 255, 255));
		fenetre.Draw(SpriteCarte) ;
		// on dessine le Sprite sur la fenetre de rendu
		fenetre.Draw(garcon_sp);
		// on dessine les instructions
		fenetre.Draw(text);

		// toujours pour actualiser le rendu (et en fin de boucle surtout) !
		fenetre.Display();

	}

	if(fenetre.IsOpened())
		fenetre.Close();

	return 0;
}
