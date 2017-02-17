#ifndef STATEK_H
#define STATEK_H

#include "gra.h"

class Statek{	

public:

	Statek(int ,int);

	void draw(sf::RenderTarget&);
	void setPosition(sf::Vector2f);
	bool checkField(sf::Vector2i, Plansza::Pole mapa[11][11]);
	bool setStatek(sf::Vector2i, Plansza::Pole mapa[11][11]);
	void clearFields(Plansza::Pole mapa[11][11]);
	int height();
	int width();
	void rotate();

public:
	
	sf::RectangleShape statek;
	sf::Texture texture;
	sf::Vector2i pozycjaNaPlanszy[4];
	
	int pozycja;
	int dlugosc;
	bool postawiony;
	
};
#endif
