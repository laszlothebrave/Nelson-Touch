#include "gra.h"

Gra::Gra():window(sf::VideoMode(900,600),"Statki v.0.1"),isHold(-1){
		plansza = Plansza(sf::Vector2f(28, 128),sf::Vector2f(11*34,11*34));	
		createShips();
		
}

void Gra::processEvents(){
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2f fieldNameOffsetPos = sf::Vector2f(plansza.pozycja.x + plansza.rozmiarPola.x, plansza.pozycja.y + plansza.rozmiarPola.y);
			sf::Vector2f fieldNameOffsetSize = sf::Vector2f(plansza.rozmiar.x - plansza.rozmiarPola.x, plansza.rozmiar.y - plansza.rozmiarPola.y);
			
			if (isHold != -1)
				if (statki[isHold]->setStatek(indexOfFieldMouseOn(), plansza.mapa) || !isVectorInsideRect(getMousePosition(), fieldNameOffsetPos, fieldNameOffsetSize))
				{
					isHold = -1;
					break;
				}
			if (indexOfClickedShip() != -1)
			{
				isHold = indexOfClickedShip();
				if(isVectorInsideRect(getMousePosition(), fieldNameOffsetPos, fieldNameOffsetSize))
					statki[isHold]->clearFields(plansza.mapa);
			}
		}else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			if (isHold != -1)
				statki[isHold]->rotate();
		}
	}
}

void Gra::update(){
	if (isHold!=-1){
		sf::Vector2f fieldNameOffsetPos = sf::Vector2f(plansza.pozycja.x + plansza.rozmiarPola.x, plansza.pozycja.y + plansza.rozmiarPola.y);
		sf::Vector2f fieldNameOffsetSize = sf::Vector2f(plansza.rozmiar.x - plansza.rozmiarPola.x, plansza.rozmiar.y - plansza.rozmiarPola.y);
		if (isVectorInsideRect(getMousePosition(),fieldNameOffsetPos,fieldNameOffsetSize)){
			statki[isHold]->setPosition(getIndex());
			if ((int)statki[isHold]->statek.getRotation() % 180 != 0){
				statki[isHold]->setPosition(getIndex() + sf::Vector2f(-(statki[isHold]->dlugosc - 1) * 0.5 * plansza.rozmiarPola.x, 
																	   (statki[isHold]->dlugosc - 1) * 0.5 * plansza.rozmiarPola.y));	
			}
		}else
			statki[isHold]->statek.setPosition(getMousePosition());
	}
}

void Gra::render(){
	window.clear(sf::Color(175,177,185));
	plansza.create(window);
	for (int i = 0; i < 10; i++)	
		statki[i]->draw(window);
	window.display();
}

void Gra::start(){
	while(window.isOpen()){
		processEvents();
		update();
		render();	
	}
}

sf::Vector2f Gra::getMousePosition(){
	sf::Vector2f localPosition = (sf::Vector2f)sf::Mouse::getPosition(window);
	return localPosition;
}

void Gra::createShips(){
	int dlugosc = 3;
	int ilosc = 4;
	for (int i = 0; i < 10; i++){
		if (ilosc == 0) { 
			ilosc = dlugosc;
			dlugosc--;
		}
		statki.push_back(new Statek(4-dlugosc, i+1));
		ilosc--;
	}
}

int Gra::indexOfClickedShip(){
	for (int i = 0; i<statki.size(); i++){
		sf::RectangleShape statek = statki[i]->statek;
		if (isVectorInsideRect(getMousePosition()+statek.getOrigin(),statek.getPosition(),statek.getSize()))
			return i;
		}
	return -1;
}

sf::Vector2f Gra::getIndex(){
	sf::Vector2f index;
	index.x = indexOfFieldMouseOn().x * plansza.rozmiarPola.x + plansza.pozycja.x + 3 ;
	index.y = indexOfFieldMouseOn().y * plansza.rozmiarPola.y + plansza.pozycja.y + 3;
	return index;
}

sf::Vector2i Gra::indexOfFieldMouseOn(){
	sf::Vector2f index;
	sf::Vector2f mousePosition = getMousePosition();
	index.x = (mousePosition.x - plansza.pozycja.x ) / plansza.rozmiarPola.x;
	index.y = (mousePosition.y - plansza.pozycja.y ) / plansza.rozmiarPola.y;
	return (sf::Vector2i)index;
}

bool Gra::isVectorInsideRect(sf::Vector2f vector, sf::Vector2f position, sf::Vector2f size){
	return  vector.x >= position.x && vector.x <= position.x + size.x &&
		vector.y >= position.y && vector.y <= position.y + size.y;
}

