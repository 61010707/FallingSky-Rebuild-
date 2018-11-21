#include "Enermy.h"

Enermy::Enermy(String EnermyPath, Vector2u SpriteCount, float speed, Vector2f Scale) :
	EnermyAnimation(SpriteCount), EnermyMove(speed, Scale)
{
	this->SpriteCount = SpriteCount;
	CreateSprite(EnermyPath);
	sprite.setScale(Scale);
	sprite.setTextureRect(IntRect(0, 0, 64, 126));
}

Enermy::~Enermy()
{
}

void Enermy::Update(float DeltaTime, float SwitchTime, Sprite *Player)
{
	animation(DeltaTime, SwitchTime, Player);
	MoveMent(Player);
}

void Enermy::animation(float DeltaTime, float SwitchTime, Sprite *Player)
{
	EnermyAnimation.animationLayer(&sprite, DeltaTime, SwitchTime);
	EnermyAnimation.EnermyMove(Player, &sprite);
}

void Enermy::MoveMent(Sprite *Player)
{
	EnermyMove.EnermyMove(Player, &sprite);
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