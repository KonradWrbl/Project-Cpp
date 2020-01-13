#include "CreatorScreen.h"
#include <iostream>
#include <fstream>
#include <vector>

CreatorScreen::CreatorScreen()
{
	setRandomSize();
	setMazeTab();
	saveToFile();
}

void CreatorScreen::draw(sf::RenderWindow* window)
{
	sf::RectangleShape back;
	back.setSize({ 2000.0f, 1000.0f });
	back.setFillColor(sf::Color(11, 11, 11));
	window->draw(back);
	sf::RectangleShape rect;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 15; j++) {
			rect.setSize({ 50.0f, 50.0f });
			rect.setPosition({ i * 51.0f + (window->getSize().x - 20 * 51.0f) / 2, j * 51.0f + (window->getSize().y - 15 * 51.0f) / 2 });
			rect.setFillColor(sf::Color(51, 51, 51));
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

void CreatorScreen::saveToFile()
{
	std::ofstream file;
	file.open("maze.txt", std::ofstream::out | std::ofstream::trunc);
	int h = getMapHeight(), w = getMapWidth();
	file << h << ' ' << w << "\n";
	for (int i = 0; i < getMapWidth(); i++) {
		for (int j = 0; j < getMapHeight(); j++) {
			if (getMazeTab(i, j)==1) file << 'B';
			else file << 'C';
		}
		file << "\n";
	}
	file.close();
}

void CreatorScreen::setRandomSize()
{
	srand(time(NULL));
	this->height = rand() % 17 + 3;
	this->width = rand() % 30 + 3;
}

void CreatorScreen::setMazeTab()
{
	int height = getMapHeight();
	int width = getMapWidth();
	this->mazeMap.resize(width);
	for (int i = 0; i < width; i++) {
		this->mazeMap[i].resize(height);
		//this->mazeMap[i].push_back(std::vector<bool>());
		for (int j = 0; j < height; j++) {
			this->mazeMap[i][j] = floor(rand()%3);
		}
	}
}

int CreatorScreen::getMapWidth()
{
	return this->width;
}

int CreatorScreen::getMapHeight()
{
	return this->height;
}

bool CreatorScreen::getMazeTab(int x, int y)
{
	return this->mazeMap[x][y];
}