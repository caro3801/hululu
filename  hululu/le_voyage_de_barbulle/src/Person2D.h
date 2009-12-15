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
		// directions possibles
		enum moveDirection {LEFT,RIGHT,TOP,BOTTOM};

		Person2D(const float widthCase=0.f, const float heightCase=0.f, const int stepLenght=0.f, const int nbCaseX=1.f, const int nbCaseY=1.f, const bool canGoOut=true);
		// re-construteur
		void create(const float widthCase=0.f, const float heightCase=0.f, const int stepLenght=0.f, const int nbCaseX=1.f, const int nbCaseY=1.f, const bool canGoOut=true);
		void initClip();

		// accesseurs
		inline float getWidthCase() { return widthCase; }
		inline float getHeightCase() { return heightCase; }
		inline int getNbCaseX() { return nbCaseX; }
		inline int getNbCaseY() { return nbCaseY; }
		inline int getActiveLeftCase() { return activeLeftCase; }
		inline int getActiveTopCase() { return activeTopCase; }
		inline int getActiveBottomCase() { return activeBottomCase; }
		inline int getActiveRightCase() { return activeRightCase; }
		inline int getStepLenght(){ return stepLenght; }

		void setWidthCase(float width);
		void setHeightCase(float height);
		void setNbCaseX(int nb);
		void setNbCaseY(int nb);
		void setStepLenght(int lenght);
		void setCanGoOut(bool);

		void walk(moveDirection direction, float interval);
		bool inMoveTo(moveDirection direction);
		bool readyToMove(float interval);

	protected:
		// un Sprite est composé de plusieurs cases
		// ces cases représentent les états successifs (visuellement) du sprite

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
		int activeTopCase;
		int activeBottomCase;
		int stepLenght; // distance parcouru à chaque pas
		sf::Clock timeSinceLastRefresh; // temps écoulé depuis le dernier *refresh*

		bool canGoOut;
};

#endif /* PERSON2D_H_ */
