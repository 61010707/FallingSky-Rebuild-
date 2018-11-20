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
	void animationLayer(Sprite *sprite,float DeltaTime,float SwitchTime);
	void KeyPress();
	void EnermyMove(Sprite *player,Sprite *Enermy);
	void UVrectCalculate(Sprite &sprite, Vector2u frame);
private:
	float TotalTime = 0.0f;
	IntRect UVrect;
	Vector2u frame = Vector2u(0, 0);
	Vector2u Moving = SpriteCount;
	Vector2u Size;
	Vector2u SpriteCount;
};
