#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"MapSprite.h"
#include"Collision.h"
using namespace std;
using namespace sf;
class Object
{
public:
	Object(String objectPath);
	~Object();

	bool CheckCollision(Sprite *object1);
private:
	MapSprite MapObject;
	Collision collision;
};

