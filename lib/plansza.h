#ifndef PLANSZA_H
#define PLANSZA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Plansza
{

	public :
	Plansza(){}
	Plansza(sf::Vector2f position);
	void create(sf::RenderTarget& target);
	
	public :
	sf::RectangleShape pola[10][10]; 
	
	
};
#endif

