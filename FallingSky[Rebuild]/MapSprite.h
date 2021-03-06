#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class MapSprite
{
public:
	MapSprite();
	~MapSprite();
	void Create(String TexturePath);
	void draw(RenderWindow*window);
	Vector2u GetSize() { return sprite.getTexture()->getSize(); }
	Sprite sprite;
private:
	Texture texture;
};
