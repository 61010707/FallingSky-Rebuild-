#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Animation.h"
#include"Move.h"
using namespace std;
using namespace sf;
class Player
{
public:
	Player(String PlayerPath, Vector2u SpriteCount);
	~Player();

	void CreateSprite();
	void draw(RenderWindow* window);
	void Update(float DeltaTime, float SwitchTime);

private:
	Animation animation;
	IntRect UVrect;
	Move move;
	Sprite Sprite;
	String PlayerPath;
	Texture Texture;
	Vector2f Scale = Vector2f(3.0f, 3.0f);
	Vector2u SpriteCount;
};
