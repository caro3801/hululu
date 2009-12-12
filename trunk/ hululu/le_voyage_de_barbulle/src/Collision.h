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

#ifndef COLLISION_H_
#define	COLLISION_H_

class Collision {
public:
    virtual ~Collision();
    static bool cercleTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
    static float MinValue(float a, float b, float c, float d);
    static float MaxValue(float a, float b, float c, float d);
private:
    Collision();

};

#endif /*COLLISION_H_ */
