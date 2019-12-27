#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class MenuScreen :public Screen
{
public:
	MenuScreen();

	virtual void draw(sf::RenderWindow*) override;
	virtual void onEvent(sf::Event event) override;
	void MoveUp();
	void MoveDown();
	virtual int getIndex() override;

private:

	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

