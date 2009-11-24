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
	sf::RenderWindow fenetre(sf::VideoMode(800, 600, 32),  "Test animation personnage");

	// on charge une image
	sf::Image garcon_img;
	if (!garcon_img.LoadFromFile("img/sprite/sprite_g_walk.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}

	Person2D garcon_sp(100.f, 200.f, 100, 6, 4);
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
	// float largeur  = garcon_sp.GetSize().x;
	// float hauteur = garcon_sp.GetSize().y;

	// clipage du sprite
	// c-à-d on n'affiche que les partie du sprite qui nous intérèsse
	garcon_sp.initClip();


	// Pour que le programme ne se termine pas :)
	sf::Event event;
	while(fenetre.IsOpened())
	{
		fenetre.GetEvent(event);

		// # fermeture de la fenetre
		// si echap ou fermeture manuelle
		if (event.Type == sf::Event::Closed)
			fenetre.Close();

		if (event.Key.Code == sf::Key::Escape)
			fenetre.Close();


		// # deplacement du Sprite

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Left)) or ( garcon_sp.inMoveTo(Person2D::LEFT) ) )
			garcon_sp.walk(Person2D::LEFT, 1000);

		if( (fenetre.GetInput().IsKeyDown(sf::Key::Right)) or ( garcon_sp.inMoveTo(Person2D::RIGHT) ) )
			garcon_sp.walk(Person2D::RIGHT, 1000);


		// efface l'ecran
		fenetre.Clear(sf::Color(255, 255, 255));

		// on dessine le Sprite sur la fenetre de rendu
		fenetre.Draw(garcon_sp);

		// toujour pour actualiser le rendu (et en fin de boucle surtout) !
		fenetre.Display();

	}

	if(fenetre.IsOpened())
		fenetre.Close();

	return 0;
}















