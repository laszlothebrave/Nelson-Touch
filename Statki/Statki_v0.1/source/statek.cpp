#include "statek.h"

Statek::Statek(int dlugosc, int pozycja) :dlugosc(dlugosc),postawiony(false){
	statek = sf::RectangleShape(sf::Vector2f(26 + 34 * (dlugosc - 1), 26));
	statek.setPosition(430, 128+pozycja*34);

	if (texture.loadFromFile("img/s3.png"))
	{
		statek.setTexture(&texture);
	}
	else{
		statek.setFillColor(sf::Color(29, 165, 79));
		statek.setOutlineColor(sf::Color(10, 10, 10));
		statek.setOutlineThickness(2);
	}
}

void Statek::draw(sf::RenderTarget& target){
	target.draw(statek);
}

void Statek::rotate(){
	sf::Vector2f tmp = sf::Vector2f(statek.getSize().y, statek.getSize().x);
	statek.setSize(tmp);
}