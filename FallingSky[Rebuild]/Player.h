#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Player
{
public:
	Player(String PlayerPath, Vector2i SpriteCount);
	~Player();

	void CreateSprite();
	void Update();
	void draw(RenderWindow* window);
private:
	String PlayerPath;
	Vector2i SpriteCount;
	Texture Texture;
	Sprite Sprite;
};
