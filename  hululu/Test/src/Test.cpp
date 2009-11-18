//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

int main()
{
	cout << "Je vais ouvrir une fenetre !" << endl;

	// a partir de maintenant je n'utilise plus sf:: (cf using namespace)

	Window App(VideoMode(800, 600, 32), "Je suis vraiment une fenetre sexy");

	// pour pas que le programme ne se termine pas :)
	// on attent, si Running passe a false, on passe la boucle et on termine

	// cette methode s'appelle le *polling* (le fait d'attendre ds une boucle)
	// nous on a deja utilise des *callback*
	// rappellez vous les fameux headers !
	bool Running = true;
	while (Running)
	{
		// met juste a jour l'afficahge de la fenetre
	    App.Display();
	}



	return 0;
}
