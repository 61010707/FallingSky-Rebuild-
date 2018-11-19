#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Animation
{
public:
	Animation(Vector2i SprtieCount);
	~Animation();

	void animation(Sprite &sprite, float DeltaTime, float SwitchTime);
private:
	IntRect UVrect;
	float TotalTime = 0.0f;
	Sprite sprite;
	Vector2u Size;
	Vector2i SpriteCount;
};
