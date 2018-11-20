#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"MapSprite.h"
using namespace std;
using namespace sf;
class Map
{
public:
	Map(String MainMapPath);
	~Map();
	void Update();
	void MapCollision();
	void Draw(RenderWindow*window);
private:

	MapSprite MainMap;
	String CollisionMapPath;
	String MainMapPath;
};
