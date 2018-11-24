#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class InputName
{
public:
	InputName();
	~InputName();

	void INPUTNAME(RenderWindow *window);
	sf::String yourname;
	string name;
	sf::Text player;
	sf::Font font;
private:
	Text YourName;
	Text Title1;
	Text Title2;
	int Blink = 0;
	int delay = 0;
};
