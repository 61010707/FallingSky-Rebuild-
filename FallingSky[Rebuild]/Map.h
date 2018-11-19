#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Map
{
public:
	Map();
	~Map();
private:
	Texture MainMap;
	Texture CollisionMap;

};

