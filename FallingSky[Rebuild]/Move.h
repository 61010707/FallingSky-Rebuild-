#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Move
{
public:
	Move(float speed, Vector2f Scale);
	~Move();

	void EnermyMove(Sprite *Player, Sprite *Enermy);
	void KeyboardMove(Sprite *sprite);
	float speed;
private:
	
	Sprite sprite;
	Vector2f Scale;
	Vector2f SpeedCharacter = Vector2f(0.0f, 0.0f);
};
