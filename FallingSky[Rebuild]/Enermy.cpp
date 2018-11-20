#include "Enermy.h"

Enermy::Enermy(String EnermyPath, Vector2u SpriteCount) :
	EnermyAnimation(SpriteCount)
{
	this->SpriteCount = SpriteCount;
	CreateSprite(EnermyPath);
	sprite.setScale(1.5f, 1.5f);
}

Enermy::~Enermy()
{
}

void Enermy::Update()
{
}

void Enermy::animation(float DeltaTime, float SwitchTime, Sprite *Player)
{
	EnermyAnimation.animationLayer(&sprite, DeltaTime, SwitchTime);
	EnermyAnimation.EnermyMove(Player, &sprite);
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