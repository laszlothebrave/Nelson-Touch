#include "gra.h"


Statek::Statek(int dlugosc, int pozycja) :dlugosc(dlugosc),postawiony(false){
	statek = sf::RectangleShape(sf::Vector2f(26 + 34 * (dlugosc - 1), 26));
	statek.setPosition(430, 128+pozycja*34);
	statek.setOrigin(statek.getSize().x / 2, statek.getSize().y / 2);
	statek.setPosition(statek.getPosition().x + statek.getOrigin().x, statek.getPosition().y + statek.getOrigin().y);
	if (texture.loadFromFile("img/s" + to_string(dlugosc) + ".png"))
		statek.setTexture(&texture);
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
	statek.rotate(90);
}

void Statek::setPosition(sf::Vector2f vector){
	statek.setOrigin(statek.getSize().x / 2, statek.getSize().y / 2);
	statek.setPosition(vector + statek.getOrigin());
}

int Statek::height(){
	if ((int)statek.getRotation() % 180 == 0)
		return 1;
		return dlugosc;
}

int Statek::width(){
	if ((int)statek.getRotation() % 180 != 0)
		return 1;
		return dlugosc;
}

bool Statek::checkField(sf::Vector2i vector, Plansza::Pole mapa[11][11]){
	for (int i = vector.x - 1; i <= vector.x + 1; i++)
		for (int j = vector.y - 1; j <= vector.y + 1; j++){
			if (i > 10 || j > 10) continue;
			if (mapa[j][i] != Plansza::woda)return false;
			}
	return true;
}

bool Statek::setStatek(sf::Vector2i index, Plansza::Pole mapa[11][11]){
	int licznik = 0;

	for (int i = 0; i < width(); i++)
		for (int j = 0; j < height(); j++)
			if (checkField(sf::Vector2i(index.x + i, index.y + j), mapa))
				pozycjaNaPlanszy[licznik++] = sf::Vector2i(index.x + i, index.y + j);
			else return false;
	
	if (index.x+width()>11 || index.y+height()>11) return false;
	for (int i = 0; i < dlugosc; i++)
		mapa[pozycjaNaPlanszy[i].y][pozycjaNaPlanszy[i].x] = Plansza::statek;
	
	return true;
}

void Statek::clearFields(Plansza::Pole mapa[11][11]){
	for (int i = 0; i < dlugosc; i++)
		mapa[pozycjaNaPlanszy[i].y][pozycjaNaPlanszy[i].x] = Plansza::woda;
}