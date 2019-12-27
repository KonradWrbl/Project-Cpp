#include "Screen.h"

void Screen::setOnChangeScreenListener(std::function<void(Screen*)> l)
{
	this->onChangeScreenListener = l;
}
