/*
 * File:   collision.h
 * Author: WIKI SFML (Nick) COLLISIONS -  Modifications ajoutées
 *
 * Created on 12 December 2009, 16:35
 */
#include <SFML/Graphics.hpp>
#include "Collision.h"

Collision::Collision() {
}

Collision::~Collision() {
}

float Collision::MinValue(float a, float b, float c, float d) {
    float min = a;

    min = (b < min ? b : min);
    min = (c < min ? c : min);
    min = (d < min ? d : min);

    return min;
}

float Collision::MaxValue(float a, float b, float c, float d) {
    float max = a;

    max = (b > max ? b : max);
    max = (c > max ? c : max);
    max = (d > max ? d : max);

    return max;
}

bool Collision::cercleTest(const sf::Sprite& Object1, const sf::Sprite& Object2) {
    //Simplest circle test possible
    //Distance between points <= sum of radius

    float Radius1 = (Object1.GetSize().x + Object1.GetSize().y) / 4;
    float Radius2 = (Object2.GetSize().x + Object2.GetSize().y) / 4;
    float xd = Object1.GetPosition().x - Object2.GetPosition().x;
    float yd = Object1.GetPosition().y - Object2.GetPosition().y;

    return sqrt(xd * xd + yd * yd) <= Radius1 + Radius2;
}

