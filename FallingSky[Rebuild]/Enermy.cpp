#include "Enermy.h"



Enermy::Enermy(String EnermyPath)
{
	CreateSprite(EnermyPath);
}


Enermy::~Enermy()
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
