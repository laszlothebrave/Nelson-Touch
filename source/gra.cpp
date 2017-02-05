#include "gra.h"

Gra::Gra():window(sf::VideoMode(800,600),"Statki v.0.1"){
	plansza = Plansza(sf::Vector2f(128,128));
}

void Gra::processEvents(){
	sf::Event event;
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window.close();
	}
}

void Gra::update(){
	
}

void Gra::render(){
	window.clear();
	plansza.create(window);
	window.display();
}

void Gra::start(){
	while(window.isOpen()){
		processEvents();
		update();
		render();	
	}
}
