#include "MenuScreen.h"
#include "MainScreen.h"

MenuScreen::MenuScreen() :selectedItemIndex(0)
{
	if (!font.loadFromFile("arial.ttf")) {
		//handle error
	}

	

	menu[0].setFont(this->font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Find!");
	menu[0].setPosition(sf::Vector2f(2000 / 2, 1000 / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(this->font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Creator");
	menu[1].setPosition(sf::Vector2f(2000 / 2, 1000 / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(this->font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(2000 / 2, 1000 / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

void MenuScreen::draw(sf::RenderWindow* window)
{
	sf::RectangleShape rect;
	rect.setSize({ 2000.0f, 1000.0f });
	rect.setFillColor(sf::Color(11, 11, 11));
	window->draw(rect);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) window->draw(menu[i]);

}

void MenuScreen::onEvent(sf::Event event)
{
	switch (event.type) {
	case sf::Event::KeyReleased:
		switch (event.key.code) {
		case sf::Keyboard::Up:
			this->MoveUp();
			break;
		case sf::Keyboard::Down:
			this->MoveDown();
			break;
		}
	}
}

void MenuScreen::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuScreen::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int MenuScreen::getIndex()
{
	return this->selectedItemIndex;
}
