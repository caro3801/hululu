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

	// creation de la fenetre de 800px par 600px, profondeur de 32 bits pour les pixels
	// et enfin le titre
	Window fenetre(VideoMode(800, 600, 32), "Je suis vraiment un TITRE sexy");

	// pour pas que le programme ne se termine pas :)
	// on attent, si Running passe a false, on passe la boucle et on termine

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


	while(fenetre.IsOpened())
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


		}

		// toujour pour actualiser le rendu (et en fin de boucle surtout) !
		fenetre.Display();
	}

	cout << "Hop hop, la boucle c'est fini !" << endl;


	return 0;
}
