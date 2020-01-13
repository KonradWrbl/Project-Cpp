#include "MainScreen.h"
#include <iostream>

MainScreen::MainScreen()
{
	this->map.load();
	this->tab = this->map.pathFinder();
	this->font.loadFromFile("arial.ttf");
}

void MainScreen::draw(sf::RenderWindow* window)
{
	sf::RectangleShape back;
	back.setSize({ 2000.0f, 1000.0f });
	back.setFillColor(sf::Color(11, 11, 11));
	window->draw(back);
	sf::Text disp("", this->font, 20);
	sf::RectangleShape rect;
	disp.setFillColor(sf::Color(0, 0, 0));
	for (int i = 0; i < this->map.getHeight(); i++) {
		for (int j = 0; j < this->map.getWidth(); j++) {
			sf::Color Nazwa;
			switch (this->map.getAt(i, j)) {
			case State::White:
				Nazwa = sf::Color(220, 220, 220);
				break;
			case State::Black:
				Nazwa = sf::Color(51,51,51);
				break;
			default:
				Nazwa = sf::Color(255, 51, 51);
				break;
			}
			if (this->tab[i][j].isPainted) {
				Nazwa = sf::Color(51, 255, 51);
			}
			rect.setSize({ 50.0f, 50.0f });
			rect.setPosition({ i * 51.0f + (window->getSize().x - this->map.getHeight() * 51.0f) / 2, j * 51.0f + (window->getSize().y - this->map.getWidth() * 51.0f) / 2 });
			rect.setFillColor(Nazwa);
			window->draw(rect);
			disp.setString(std::to_string(this->tab[i][j].dist));
			disp.setPosition({ i * 51.0f + (window->getSize().x - this->map.getHeight() * 51.0f) / 2, j * 51.0f + (window->getSize().y - this->map.getWidth() * 51.0f) / 2 });
			window->draw(disp);
		}
	}
}

void MainScreen::onEvent(sf::Event event)
{
}

int MainScreen::getIndex()
{
	return 0;
}
