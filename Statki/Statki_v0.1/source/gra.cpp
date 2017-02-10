#include "gra.h"
#include <iostream>

#define WYPISZ(x) std::cout << #x << "=" << x << "\n";
Gra::Gra():window(sf::VideoMode(900,600),"Statki v.0.1"){
		plansza = Plansza(sf::Vector2f(28, 128));	
}

void Gra::processEvents(){
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				sf::Vector2i w = getMousePosition();
				plansza.mousePosition.x = (w.x - plansza.pozycja.x) / 34;
				plansza.mousePosition.y = (w.y - plansza.pozycja.y) / 34;
				if (plansza.isHold != -1){
					plansza.isHold = -1;
					break;
				}
				int index = shipClicked();
				if (index>=0){
				plansza.isHold = index;
				}
			}
		}
	}

void Gra::update(){
	if (plansza.isHold!=-1){
		if (28 < getMousePosition().x &&
			28 + 11*34 > getMousePosition().x
			&& 128 < getMousePosition().y &&
				128 + 11 * 34 > getMousePosition().y){
				plansza.statki[plansza.isHold]->statek.setPosition(getIndex());
			
		}else
		plansza.statki[plansza.isHold]->statek.setPosition((sf::Vector2f)getMousePosition());
		
	}
}

void Gra::render(){
	window.clear(sf::Color(175,177,185));
	plansza.create(window);
	for (int i = 0; i < 10; i++){	
		plansza.statki[i]->draw(window);
	}
	window.display();
}

void Gra::start(){
	draw();
	while(window.isOpen()){
		processEvents();
		update();
		render();	
		
	}
}

sf::Vector2i Gra::getMousePosition(){
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	return localPosition;
}

void Gra::setStatek(){

}

bool Gra::sprawdzPole(sf::Vector2i index){
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			if (plansza.mapa[i][j] == Plansza::statek) return false;
		}
	}
	return true;
}
void Gra::draw(){
	plansza.statki[0] = new Statek(1, 1);
	plansza.statki[1] = new Statek(1, 2);
	plansza.statki[2] = new Statek(1, 3);
	plansza.statki[3] = new Statek(1, 4);
	plansza.statki[4] = new Statek(2, 5);
	plansza.statki[5] = new Statek(2, 6);
	plansza.statki[6] = new Statek(2, 7);
	plansza.statki[7] = new Statek(3, 8);
	plansza.statki[8] = new Statek(3, 9);
	plansza.statki[9] = new Statek(4, 10);
}

int Gra::shipClicked(){
	for (int i = 0; i<plansza.statki.size(); i++){
		if (plansza.statki[i]->statek.getPosition().x < getMousePosition().x &&
			plansza.statki[i]->statek.getPosition().x + plansza.statki[i]->statek.getSize().x > getMousePosition().x){
			if (plansza.statki[i]->statek.getPosition().y < getMousePosition().y &&
				plansza.statki[i]->statek.getPosition().y + plansza.statki[i]->statek.getSize().y > getMousePosition().y)
				return i;
			}
		}
	return -1;
}

sf::Vector2f Gra::getIndex(){
	sf::Vector2i w = getMousePosition();
	plansza.mousePosition.x = (w.x - plansza.pozycja.x) / 34;
	plansza.mousePosition.y = (w.y - plansza.pozycja.y) / 34;
	w.x = plansza.mousePosition.x * 34 + plansza.pozycja.x+3;
	w.y = plansza.mousePosition.y * 34 + plansza.pozycja.y+3;
	return (sf::Vector2f)w;
}