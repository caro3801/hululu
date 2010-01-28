/*
 * Musique.cpp
 *
 *  Created on: 26 janv. 2010
 *      Author: pirhoo
 */

#include <SFML/Audio.hpp>
#include "Musique.h"

Musique::Musique(string chemin) {
	_chemin = chemin;
	_charge = false;
}

Musique::~Musique() {
	// TODO Auto-generated destructor stub
}

void Musique::Lecture()
{
	if(!_charge)
	{
		_charge = true;
		if( this->OpenFromFile(_chemin) )
			this->Play();
	}
	else this->Play();
}

void Musique::ChargerFichier()
{
	this->OpenFromFile(_chemin);
}

