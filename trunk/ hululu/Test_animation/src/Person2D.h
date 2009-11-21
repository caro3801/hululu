/*
 * Person2D.h
 *
 *  Created on: 21 nov. 2009
 *      Author: pirhoo
 */

#ifndef PERSON2D_H_
	#define PERSON2D_H_

	#include <SFML/System.hpp>
	#include <SFML/Window.hpp>
	#include <SFML/Graphics.hpp>

class Person2D : public sf::Sprite
{
	// cette classe est une classe fille de Sprite
	// elle a pour but de simplifier et standardiser l'usage d'un Sprite
	// lorsque ce dernier représente un personage en 2D

	public:
		Person2D(const float widthCase=0.f, const float heightCase=0.f, const int stepLenght=0.f, const int nbCaseX=1.f, const int nbCaseY=1.f);
		// re-construteur
		void create(const float widthCase=0.f, const float heightCase=0.f, const int stepLenght=0.f, const int nbCaseX=1.f, const int nbCaseY=1.f);
		void initClip();

		// accesseurs
		float getWidthCase();
		float getHeightCase();
		int getNbCaseX();
		int getNbCaseY();
		inline int getActiveLeftCase() { return activeLeftCase; }
		inline int getActiveRightCase() { return activeRightCase; }
		int getStepLenght();

		void setWidthCase(float width);
		void setHeightCase(float height);
		void setNbCaseX(int nb);
		void setNbCaseY(int nb);
		void setStepLenght(int lenght);

		void walkLeft(float interval);
		void walkRight(float interval);


	protected:
		// un Sprite est composé de plusieurs cases
		// ces cases représentent les états succéssifs (visuellement) du sprite

		// pour conventioner la création des Sprites, on fixe:
			// - première ligne, mouvement de face (montant)
			// - deuxième ligne, mouvement vers la droite
			// - troisème ligne, mouvement vers la gauche
			// - quatrième ligne, mouvement de dos (descendant)

		float widthCase; // largeur d'une case de Sprite
		float heightCase; // hauteur d'une case de Sprite

		int nbCaseX; // nombre de case horizontalement
		int nbCaseY; // nombre de case verticalement

		int activeLeftCase;
		int activeRightCase;

		int stepLenght; // distance parcouru à chaque pas
};

#endif /* PERSON2D_H_ */
