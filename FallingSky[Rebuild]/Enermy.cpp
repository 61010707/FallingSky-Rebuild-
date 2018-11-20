#include "Enermy.h"



Enermy::Enermy(String EnermyPath)
{
	CreateSprite(EnermyPath);
}


Enermy::~Enermy()
{
}

void Enermy::Update()
{
}

void Enermy::animation(float DeltaTime, float SwitchTime)
{
}

void Enermy::Move()
{
}

void Enermy::Collision()
{
}

void Enermy::CreateSprite(String EnermyPath)
{
	texture.loadFromFile(EnermyPath);
	sprite.setTexture(texture);
}

void Enermy::Draw(RenderWindow & window)
{
	window.draw(sprite);
}
