#include "statek.h"

Statek::Statek(int dlugosc, int pozycja) :dlugosc(dlugosc){
	postawiony = false;
	dlugoscV = sf::Vector2f(26 + 34 * (dlugosc - 1),26);
	statek = sf::RectangleShape(dlugoscV);
	statek.setPosition(430, 128+pozycja*34);
	statek.setFillColor(sf::Color(29, 165, 79));
	statek.setOutlineThickness(2);
	statek.setOutlineColor(sf::Color(10, 10, 10));
}