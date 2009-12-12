#ifndef _COLLISION_H
#define	_COLLISION_H

/*
 * File:   collision.h
 * Author:  WIKI SFML (Nick) COLLISIONS -  Modifications ajoutées
 *
 * Created on 12 December 2009, 16:35
 */

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Collision {
public:

    ~Collision();

static bool cercleTest(const sf::Sprite& Object1, const sf::Sprite& Object2);

static float MinValue(float a, float b, float c, float d);

static float MaxValue(float a, float b, float c, float d);

private:
	Collision();
}
