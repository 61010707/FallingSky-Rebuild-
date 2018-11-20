#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Move
{
public:
	Move(float speed,Vector2f Scale);
	~Move();

	void KeyboardMove(Sprite *sprite);
private:
	float speed;
	Sprite sprite;
	Vector2f Scale;
	Vector2f SpeedCharacter = Vector2f(0.0f, 0.0f);
};
