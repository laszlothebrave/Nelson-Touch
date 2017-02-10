#ifndef STATEK_H
#define STATEK_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Statek{	
	public:

	Statek(int dlugosc,int pozycja);
	
	int pozycja;
	int dlugosc;
	sf::Vector2f dlugoscV;
	
	int wsp[2][4];
	bool postawiony;

	sf::RectangleShape statek;
	
	void draw(sf::RenderTarget& target){
		target.draw(statek);
	}
};
#endif
