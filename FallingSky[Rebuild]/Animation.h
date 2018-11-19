#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Animation
{
public:
	Animation(Vector2u SprtieCount);
	~Animation();

	void animation(Sprite *sprite, float DeltaTime, float SwitchTime, bool CheckKey);
	void KeyPress();
	void UVrectCalculate(Sprite &sprite, Vector2u frame);
private:
	float TotalTime = 0.0f;
	IntRect UVrect;
	Sprite sprite;
	Vector2u frame = Vector2u(0, 0);
	Vector2u Size;
	Vector2u SpriteCount;
	Vector2u Moving = SpriteCount;
};
