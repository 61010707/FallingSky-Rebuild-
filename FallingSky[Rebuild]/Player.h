#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Animation.h"
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
	Sprite Sprite;
	String PlayerPath;
	Texture Texture;
	Vector2u SpriteCount;
};
