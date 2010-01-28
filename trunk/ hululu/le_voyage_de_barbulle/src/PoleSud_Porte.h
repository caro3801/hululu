/*
 * PoleSud_Porte.h
 *
 *  Created on: 25 janv. 2010
 *      Author: sophie
 */

#ifndef POLESUD_PORTE_H_
#define POLESUD_PORTE_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Ecran.h"
#include "Musique.h"
#include "DefineEcrans.h"
#include "Objet.h"


class PoleSud_Porte : public Ecran {
public:

	PoleSud_Porte();
	virtual ~PoleSud_Porte();
	virtual int run(sf::RenderWindow &fenetre);
	bool autoriseBouger(Objet & obj);


	bool ZoneWeta(sf::RenderWindow &fenetre,float rapportW, float rapportH);
	bool ZonePoncho(sf::RenderWindow &fenetre,float rapportW, float rapportH);
	bool ZoneBlason(sf::RenderWindow &fenetre,float rapportW, float rapportH);
	bool ZoneLanterne(sf::RenderWindow &fenetre,float rapportW, float rapportH);

	static Objet blason;
	static Objet lampion;
	static Objet weta;
	static Objet poncho;

private:
	unsigned int etape;
};

#endif /* POLESUD_PORTE_H_ */
