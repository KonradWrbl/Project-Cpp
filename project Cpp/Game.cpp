#include "Game.h"

Game::Game(std::vector<Screen*> screen):screen(screen)
{
}

void Game::start()
{
	sf::RenderWindow window(sf::VideoMode(1040, 480), "This is MAZE", sf::Style::Close);
	//this->map.load();
	

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(255, 255, 255));
		for (auto& i : this->screen) {
			i->draw(&window);
		}
		window.display();
		//this->map.load();
		//window.setSize(sf::Vector2u(this->map.getHeight()*51, this->map.getWidth() * 51));
	}
}
