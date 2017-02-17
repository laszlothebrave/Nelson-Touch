#include "gra.h"

using namespace std;

Plansza::Plansza(sf::Vector2f pozycja,sf::Vector2f rozmiar):pozycja(pozycja),rozmiar(rozmiar){
	rozmiarPola.x = rozmiar.x / 11;
	rozmiarPola.y = rozmiar.y / 11;

	if (!font.loadFromFile("fonts/timesi.ttf")){
		cout << "nie ma";
	}

	for(int j=0;j<11;j++){
		for(int i=0;i<11;i++){
			if (i==0 && j!=0){
				sf::Text text = createTextField(i, j);
				polaTekstowe.push_back(text);
			}
			else if (i!=0 && j==0){
				sf::Text text = createTextField(i, j);
				polaTekstowe.push_back(text);
			}
			else if (i!=0 && j!=0){
				sf::RectangleShape pole = createField(i, j);
				pola[i][j] = pole;
				
			}
			mapa[i][j] = Pole::woda;	
		}
	}
}

void Plansza::create(sf::RenderTarget& target){
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			target.draw(pola[i][j]);
		}	
	}
	char ch = 'A';
	for (int i = 0; i < polaTekstowe.size(); i++){
		if (i == 10) ch = '1';
		string string;
		string.push_back(ch);
		polaTekstowe[i].setFont(font);
		if (i == polaTekstowe.size() - 1){
			polaTekstowe[i].setString("10");
		}else polaTekstowe[i].setString(string);
		ch++;
		target.draw(polaTekstowe[i]);
		}
	}

sf::RectangleShape Plansza::createField(int i, int j){
	sf::RectangleShape pole = sf::RectangleShape(sf::Vector2f(rozmiarPola.x-2, rozmiarPola.y-2));
	pole.setFillColor(sf::Color(34, 189, 184));
	pole.setOutlineThickness(2);
	pole.setPosition(pozycja.x + rozmiarPola.x * i, pozycja.y + rozmiarPola.y * j);
	pole.setOutlineColor(sf::Color(7, 23, 67));
	return pole;
}

sf::Text Plansza::createTextField(int i, int j){
	sf::Text text;
	text.setCharacterSize(28);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(7, 23, 67));
	text.setPosition(pozycja.x + rozmiarPola.x * i + (rozmiarPola.x - text.getCharacterSize()), pozycja.y + rozmiarPola.y * j);
	return text;
}

bool Plansza::checkField(sf::Vector2i index){
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			if (mapa[i][j] == Plansza::statek) return false;
		}
	}
	return true;
}

