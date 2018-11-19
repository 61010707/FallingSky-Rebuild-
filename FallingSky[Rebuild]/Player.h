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
	Player(String PlayerPath, Vector2i SpriteCount);
	~Player();

	void CreateSprite();
	void Update(float DeltaTime, float SwitchTime);
	void draw(RenderWindow* window);
private:
	Animation animation;
	String PlayerPath;
	Vector2i SpriteCount;
	Texture Texture;
	Sprite Sprite;
};
