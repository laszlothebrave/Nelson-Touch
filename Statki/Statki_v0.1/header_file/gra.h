#ifndef GRA_H
#define GRA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "plansza.h"
#include "statek.h"
class Gra{
	public: 
	
	Gra();
	void start();

	private :
		
	void processEvents();
	void update();
	void render();
	sf::Vector2i getMousePosition();
	void setStatek();
	bool sprawdzPole(sf::Vector2i);
	void draw();
	int shipClicked();
	sf::Vector2f getIndex();
private:
		
	sf::RenderWindow window;	
	Plansza plansza;
};
#endif
