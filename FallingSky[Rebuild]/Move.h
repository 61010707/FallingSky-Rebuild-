#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Move
{
public:
	Move();
	~Move();

	void KeyboardMove();
private:
	Sprite sprite;
};

