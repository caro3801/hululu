/*
 * JeuItalie.h
 *
 *  Created on: 15 déc. 2009
 *      Author: sophie
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ecran.h"

#ifndef JEUITALIE_H_
#define JEUITALIE_H_

class JeuItalie : public Ecran {

public:
	JeuItalie();
	virtual ~JeuItalie();
	virtual int run(sf::RenderWindow &fenetre);

	bool erreur1Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize);
	bool erreur2Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize);
	bool erreur3Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize);
	bool erreur4Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize);
	bool erreur5Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize);
	bool erreur6Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize);
	bool erreur7Trouvee(sf::RenderWindow &fenetre,float rapX,float rapY,sf::Sprite imgEResize);

	void dessineMarque(sf::RenderWindow &fenetre, bool er1, bool er2,
			bool er3, bool er4, bool er5, bool er6, bool er7, float posImgX,
			float posImgY);
	void afficherAide(sf::RenderWindow &fenetre, bool er1, bool er2,
			bool er3, bool er4, bool er5, bool er6, bool er7, float posImgX,
			float posImgY, float tailleX, float tailleY);
};

#endif /* JEUITALIE_H_ */
