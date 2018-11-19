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

	void KeyboardMove(Sprite *sprite, Vector2f Scale);
private:
	Sprite sprite;
	Vector2f SpeedCharacter = Vector2f(0.0f, 0.0f);
	float speed = 2.0f;
};
