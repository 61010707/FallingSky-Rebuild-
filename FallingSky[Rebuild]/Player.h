#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Animation.h"
#include"Move.h"
#include"Object.h"
using namespace std;
using namespace sf;
class Player
{
public:
	Player(String PlayerPath, Vector2u SpriteCount, float Speed, Vector2f Scale);
	~Player();

	void CreateSprite();
	void draw(RenderWindow* window);
	void Update(float DeltaTime, float SwitchTime);
	Sprite Sprite;
private:
	Animation animation;
	IntRect UVrect;
	Move move;
	String PlayerPath;
	Texture Texture;
	Vector2f Scale;
	Vector2u SpriteCount;
	
};
