#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Animation.h"
using namespace std;
using namespace sf;
class Enermy
{
public:
	Enermy(String EnermyPath);
	~Enermy();

	void Update();
	void animation(float DeltaTime,float SwitchTime);
	void Move();
	void Collision();
	void CreateSprite(String EnermyPath);
	void Draw(RenderWindow& window);
	Sprite sprite;
private:
	Texture texture;
	
};

