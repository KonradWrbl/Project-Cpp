#pragma once
#include "Screen.h"
#include "SFML/Graphics.hpp"

class CreatorScreen:public Screen
{
public:
	CreatorScreen();
	virtual void draw(sf::RenderWindow*) override;
	virtual void onEvent(sf::Event event) override;
	virtual int getIndex() override;

};

