#pragma once
#include "Screen.h"
#include "SFML/Graphics.hpp"
#include <vector>

class CreatorScreen:public Screen
{
public:
	CreatorScreen();
	virtual void draw(sf::RenderWindow*) override;
	virtual void onEvent(sf::Event event) override;
	virtual int getIndex() override;
	void saveToFile();
	void setRandomSize();
	void setMazeTab();
	int getMapWidth();
	int getMapHeight();
	bool getMazeTab(int x, int y);
private:
	std::vector<std::vector<int>> mazeMap;
	int width;
	int height;
};

