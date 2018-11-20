#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Animation.h"
#include"Move.h"
using namespace std;
using namespace sf;
class Enermy
{
public:
	Enermy(String EnermyPath, Vector2u SpriteCount, float speed, Vector2f Scale);
	~Enermy();

	void Update(float DeltaTime, float SwitchTime, Sprite *Player);
	void animation(float DeltaTime, float SwitchTime, Sprite *Player);
	void MoveMent(Sprite *Player);
	void Collision();
	void CreateSprite(String EnermyPath);
	void Draw(RenderWindow& window);
	Sprite sprite;
private:
	Texture texture;
	Vector2u SpriteCount;
	Animation EnermyAnimation;
	Move EnermyMove;
};
