#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

////////////////////////////////////////////////////////////
//	Class describing screens of the app
////////////////////////////////////////////////////////////
class Screen
{
public:
	virtual void draw(sf::RenderWindow*) = 0;
	virtual void onEvent(sf::Event event) = 0;

	////////////////////////////////////////////////////////////
	//	Setter of screen when it's changed.
	////////////////////////////////////////////////////////////
	void setOnChangeScreenListener(std::function<void(Screen*)> l);
	virtual int getIndex() = 0;
	
protected:
	std::function<void(Screen*)> onChangeScreenListener;
	
};

