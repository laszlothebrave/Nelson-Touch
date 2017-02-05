#ifndef GRA_H
#define GRA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "plansza.h"

class Gra{
	public: 
	
	Gra();
	void start();

	private :
		
	void processEvents();
	void update();
	void render();
	
	private:
		
	sf::RenderWindow window;	
	Plansza plansza;
};

#endif
