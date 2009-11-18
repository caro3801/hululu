//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Test SFML
//============================================================================

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main()
{
	// VOIR LES VERSIONS PRECEDENTES DU FICHIER

	cout << "Je vais ouvrir une fenetre !" << endl;

	// je n'utilise pas obligatoirement sf:: (cf using namespace)
	// c'est juste pour plus de lisibilite
	// la plupart des objets, class et methodes utilisees sont issus de SFML
	// l'auteur de la Doc utilise des conventions de nomage... pas conventionee

	// creation de la fenetre de 400px par 600px, profondeur de 32 bits pour les pixels
	// et enfin le titre
	RenderWindow fenetre(VideoMode(400, 600, 32), "Je suis vraiment un TITRE sexy");


	// nouvel version de la fenetre, mode plein ecran :)
	// fenetre.Create(sf::VideoMode::GetMode(0), "Je suis un TITRE encore plus sexy", sf::Style::Fullscreen);


	// on charge une image
	sf::Image image;
	if (!image.LoadFromFile("bibi.png"))
	{
		cout << "Erreur lors du chargement de l'image.";
	}

	// on va creer un Sprite a partir de l'image
	// qu'est ce qu'un Sprite ?
	// c'est une ou plusieurs images (animee(s) ou non)
	// qui se deplace sur l'ecran
	// generalement pour representer un.... personnage !
	// Tatapoum! Let Go!


	sf::Sprite sprite;
	// le sprite cree ici est un objet blanc et opaque
	sprite.SetColor(sf::Color(255, 255, 255, 255));

	// position du sprite
	sprite.SetX(200.f);
	sprite.SetY(100.f);
	sprite.SetPosition(200.f, 100.f);

	// rotation du sprite
	sprite.SetRotation(0.f);

	// c'est le "centre relatif" de l'objet
	// on se base sur ce centre pour les rotations, les mouvements, etc
	// ici on le positione à 0,0
	sprite.SetCenter(0, 0);




	// On change l'image (texture) source du sprite...
	// c'est l'image chargée plus haut
	sprite.SetImage(image);

	// On récupère les dimensions du sprite
	float largeur  = sprite.GetSize().x;
	float hauteur = sprite.GetSize().y;

	// On redimensionne le sprite
	sprite.Resize(largeur*1, hauteur*1);

	// Retourne le sprite sur les axes X et Y
	// sprite.FlipX(true);
	// sprite.FlipY(true);

	// On récupère la couleur d'un pixel donné du sprite
	sf::Color pixel = sprite.GetPixel(10, 5);

	int px = 0, lx = 32, py = 0, ly = 48;
	sprite.SetSubRect(sf::IntRect(px, py, lx, ly));



	// Pour que le programme ne se termine pas :)
	// on attent, si la fenetre est ouverte

	// cette methode s'appelle le *polling* (le fait d'attendre ds une boucle)
	// nous on a deja utilise des *callback*
	// rappellez vous les fameux headers !

	// GetEvent() c'est une pile d'evenements
	// a chaque fois qu'un evenement survient
	// GetEvent le chope et le fout dans Event
	// Apres il suffit de lire le type de l'evenement
	// ..
	// "Un type d'evenement ? Mais Pierrot, la fievre te monte a la tete ?!"
	// ne me regardez pas comme ca, vous allez comprendre...

	// gestion du temps
	// ces objets la sont compliques
	// je ne m'etend pas
	sf::Clock m_clock;



	while(fenetre.IsOpened() and true) // !! "and false" c'est pour "sauter" parce que je travail plus dessus
	{
		Event event;
		while (fenetre.GetEvent(event))
		{

			// permet de recupere le temps ecoule entre chaque itteration
		    float elapsedTime = m_clock.GetElapsedTime();
		    m_clock.Reset();

			// calcul primitif du taux de rafraichissement
		   cout << "# Taux de rafraichissement: " << (1.f / elapsedTime) << endl;

			// je laisse l'espace de nomage sf pour que vous voyez bien

			// regardez comme c'est bien fait
			// Event c'est une variable du type sf::Event
			// elle a des valeurs contraintes
			// quand elle vaut sf::Event::Closed
			// c'est qu'on a ferme la fenetre !
			if (event.Type == sf::Event::Closed)
				fenetre.Close();

			// pour la gestion des boutons, c'est un peu pareil
			// si un bouton est presse et que c'est echap, alors bingo
			if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
				fenetre.Close();

			// capture d'ecran si bouton F1
			if (event.Key.Code == sf::Key::F1)
			{
			    sf::Image Screen = fenetre.Capture();
			    if(Screen.SaveToFile("screenshot.jpg"))
			    	cout << "Ecran capture dans screenshot.jpg" << endl;
			}


			//# deplacement du Sprite

			if (fenetre.GetInput().IsKeyDown(sf::Key::Left))
			{
				// on deplace le sprite de -10 pixel, vers la gauche
				sprite.Move(-10, 0);

				// on change la partie visible du sprite
				// on montre le personage de profile vers la gauche
				if(px < 32*3) px += 32;
				else px = 0;
				py = 48;
				lx = px + 32;
				ly = 48*2;
			}
			if (fenetre.GetInput().IsKeyDown(sf::Key::Right))
			{
				sprite.Move( 10, 0);

				// on change la partie visible du sprite
				// on montre le personage de profile vers la droite
				if(px < 32*3) px += 32;
				else px = 0;
				py = 48*2;
				lx = px + 32;
				ly = 48*3;
			}
			if (fenetre.GetInput().IsKeyDown(sf::Key::Up))
			{
				sprite.Move(0, -10);

				if(px < 32*3) px += 32;
				else px = 0;
				py = 48*3;
				lx = px + 32;
				ly = 48*4;
			}
			if (fenetre.GetInput().IsKeyDown(sf::Key::Down))
			{
				sprite.Move(0,  10);

				if(px < 32*3) px += 32;
				else px = 0;
				py = 48*0;
				lx = px + 32;
				ly = 48;
			}

			sprite.SetSubRect(sf::IntRect(px, py, lx, ly));

		}

		// efface l'ecran
		// fenetre.Clear(); // couleur noir, par defaut
		fenetre.Clear(sf::Color(255, 255, 255));

		// on dessine le Sprite sur la fenetre de rendu
		fenetre.Draw(sprite);

		// toujour pour actualiser le rendu (et en fin de boucle surtout) !
		fenetre.Display();


	}


	cout << "Hop hop, la boucle c'est fini !" << endl;

	// familiarisez vous dont, c'est tres facile
	// on verifie juste que la fenetre ne soit pas encore ouverte
	// sinon on la ferme ;)
	if(fenetre.IsOpened())
		fenetre.Close();

	return 0;
}
