#include "plansza.h"
#include <iostream>
using namespace std;

Plansza::Plansza(sf::Vector2f position){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			sf::RectangleShape pole = sf::RectangleShape(sf::Vector2f(32,32));
			pole.setPosition(position.x+38*i,position.y+38*j);
			pole.setFillColor(sf::Color(176,196,222));
			pole.setOutlineThickness(2);
			pole.setOutlineColor(sf::Color(40,28,142));
			pola[i][j] = pole;
		}
	}
}

void Plansza::create(sf::RenderTarget& target){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			target.draw(pola[i][j]);
		}	
	}
}

