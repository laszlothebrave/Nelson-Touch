#ifndef STATEK_H
#define STATEK_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Statek{	

public:

	Statek(int dlugosc,int pozycja);
	void draw(sf::RenderTarget& target);
	void rotate();
	
public:
	
	sf::RectangleShape statek;
	sf::Texture texture;

	int pozycja;
	int dlugosc;
	bool postawiony;

};
#endif
