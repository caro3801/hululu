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


// distance parcouru (en pixel) par le Sprite à chaque "pas"
#define PAS_PX 10


int main()
{
	sf::RenderWindow fenetre(sf::VideoMode::GetMode(0), "Test animation personnage", sf::Style::Fullscreen);


	// on charge une image
	sf::Image garcon_img;
	if (!garcon_img.LoadFromFile("img/sprite/sprite_g_walk.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}

	// on créai le sprite du garçon
	sf::Sprite garcon_sp;
	garcon_sp.SetColor(sf::Color(255, 255, 255, 255));

	// position du sprite
	garcon_sp.SetX(50.f);
	garcon_sp.SetY( fenetre.GetHeight() / 2.f); // centre le sprite

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
	int px = 0, // depuis le point x= 0
		lx = 100, // sur largeur 100
		py = 200,
		ly = 200*2;
	garcon_sp.SetSubRect(sf::IntRect(px, py, lx, ly));


	// Pour que le programme ne se termine pas :)
	while(fenetre.IsOpened() and true)
	{
		sf::Event event;
		while (fenetre.GetEvent(event))
		{


			// calcul primitif du taux de rafraichissement
		    float fps = fenetre.GetFrameTime();

			// # fermeture de la fenetre
		    // si echap ou fermeture manuelle
			if (event.Type == sf::Event::Closed)
				fenetre.Close();

			if (event.Key.Code == sf::Key::Escape)
				fenetre.Close();


			// # deplacement du Sprite
			//fps = 1; // annule l'effet du FPS (commenter sinon)
			if (fenetre.GetInput().IsKeyDown(sf::Key::Left))
			{
				// on deplace le sprite de -10 pixel, vers la gauche
				garcon_sp.Move(-PAS_PX * fps, 0);

				// on change la partie visible du sprite
				// on montre le personage de profile vers la gauche
				if(px < 100*5) px += 100;
				else px = 0;
				py = 0;
				lx = px + 100;
				ly = 200;
			}
			if (fenetre.GetInput().IsKeyDown(sf::Key::Right))
			{
				garcon_sp.Move(PAS_PX * fps, 0);

				// on change la partie visible du sprite
				// on montre le personage de profile vers la droite
				if(px < 100*5) px += 100;
				else px = 0;
				py = 200;
				lx = px + 100;
				ly = 200*2;

			}

			garcon_sp.SetSubRect(sf::IntRect(px, py, lx, ly));

		}

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















