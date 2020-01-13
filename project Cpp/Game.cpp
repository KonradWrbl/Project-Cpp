#include "Game.h"
#include "MainScreen.h"
#include "CreatorScreen.h"
#include "MenuScreen.h"

Game::Game(Screen * screen):screen(screen)
{
}

void Game::start()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1000), "This is MAZE", sf::Style::Close);
	//this->map.load();

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Enter) {
					switch (this->screen->getIndex()) {
					case 0 :
						this->changeScreen(new MainScreen);
						break;
					case 1 :
						this->changeScreen(new CreatorScreen);
						break;
					case 2 :
						window.close();
					}
				}
				
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
				this->changeScreen(new MenuScreen);
			}

			this->screen->onEvent(event);

			

			
			
		}
		this->screen->draw(&window);
		window.display();
		//this->map.load();
		//window.setSize(sf::Vector2u(this->map.getHeight()*51, this->map.getWidth() * 51));
	}
}

void Game::changeScreen(Screen* s)
{
	this->screen = s;
	this->screen->setOnChangeScreenListener([&](Screen* s) {
		changeScreen(s);
	});
}
