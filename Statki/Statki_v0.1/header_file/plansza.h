#ifndef PLANSZA_H
#define PLANSZA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include "statek.h"

using namespace std;

class Plansza
{
	
	public :
		Plansza(){}
		Plansza(sf::Vector2f position);
		void create(sf::RenderTarget& target);
		bool isMapaFull();
	
	public :
		enum Pole{woda,statek,trafiony,zatopiony, pudlo};
		Pole mapa[11][11];
		vector<Statek*> statki;
		vector<sf::Text> polaTekstowe;
		sf::RectangleShape pola[11][11]; 
		sf::Vector2f pozycja;
		sf::Font font;
		sf::Vector2i mousePosition;
		sf::Vector2i mousePosition_2;
		int isHold;
	
	private :
		sf::RectangleShape createField(int i,int j);
		sf::Text createTextField(int i, int j);
	};
#endif

