#ifndef GRA_H
#define GRA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "plansza.h"
#include "statek.h"
#include <vector>

class Gra{
	public: 
	
	Gra();
	void start();

	private :
		
	void processEvents();
	void update();
	void render();
	void createShips();
	int indexOfClickedShip();
	sf::Vector2f getIndex();
	sf::Vector2f getMousePosition();
	sf::Vector2i indexOfFieldMouseOn();
	bool isVectorInsideRect(sf::Vector2f vector, sf::Vector2f position, sf::Vector2f size);
	
	private:	

	int isHold;
	sf::RenderWindow window;	
	Plansza plansza;
	vector<Statek*> statki;

};
#endif
