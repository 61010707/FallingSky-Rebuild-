#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"MapSprite.h"
using namespace std;
using namespace sf;
class Object
{
public:
	Object(String objectPath);
	~Object();
private:
	MapSprite MapObject;
};

