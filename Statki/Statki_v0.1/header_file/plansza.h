#ifndef PLANSZA_H
#define PLANSZA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include "gra.h"

using namespace std;

class Plansza
{
	
	public :
		
		Plansza(){};
		Plansza(sf::Vector2f position, sf::Vector2f rozmiar);

		void create(sf::RenderTarget& target);
		bool checkField(sf::Vector2i w);
		bool isMapaFull();
		
	public :
		
		enum Pole{woda,statek,trafiony,zatopiony, pudlo};
		
		Pole mapa[11][11];
		vector<sf::Text> polaTekstowe;
		sf::RectangleShape pola[11][11]; 
		sf::Vector2f pozycja;
		sf::Vector2f rozmiar;
		sf::Vector2f rozmiarPola;
		sf::Vector2i indexOfClickedField;
		sf::Font font;
		
	private :
		sf::RectangleShape createField(int i,int j);
		sf::Text createTextField(int i, int j);
	};
#endif

