#include "CreatorScreen.h"

CreatorScreen::CreatorScreen()
{
}

void CreatorScreen::draw(sf::RenderWindow* window)
{
	sf::RectangleShape back;
	back.setSize({ 1040.0f, 480.0f });
	back.setFillColor(sf::Color(11, 11, 11));
	window->draw(back);
	sf::RectangleShape rect;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			rect.setSize({ 50.0f, 50.0f });
			rect.setPosition({ i * 51.0f + (window->getSize().x - 20 * 51.0f) / 2, j * 51.0f + (window->getSize().y - 20 * 51.0f) / 2 });
			rect.setFillColor(sf::Color(51,51,51));
			window->draw(rect);
		}
	}
}

void CreatorScreen::onEvent(sf::Event event)
{
}

int CreatorScreen::getIndex()
{
	return 0;
}
