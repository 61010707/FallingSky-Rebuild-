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
	std::string name;
	sf::Text player;
	sf::Font font;
private:
};

