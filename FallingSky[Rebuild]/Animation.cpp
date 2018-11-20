#include "Animation.h"

Animation::Animation(Vector2u SprtieCount)
{
	this->SpriteCount = SprtieCount;
	Moving = SpriteCount;
}

Animation::~Animation()
{
}

void Animation::UVrectCalculate(Sprite & sprite, Vector2u frame)
{
	Size = sprite.getTexture()->getSize();
	UVrect.width = Size.x / SpriteCount.x;
	UVrect.height = Size.y / SpriteCount.y;
	UVrect.left = frame.x * UVrect.width;
	UVrect.top = frame.y*UVrect.height;
}

void Animation::animation(Sprite *sprite, float DeltaTime, float SwitchTime, bool CheckKey)
{
	sprite->setOrigin(8.0f, 14.0f);
	TotalTime += DeltaTime;
	if (CheckKey) { KeyPress(); }
	if (TotalTime > SwitchTime)
	{
		TotalTime -= SwitchTime;
		frame.x++;
		if (frame.x > Moving.x - 1) { frame.x = 0; }
		UVrectCalculate(*sprite, frame);
		sprite->setTextureRect(UVrect);
	}
}

void Animation::animationLayer(Sprite * sprite, float DeltaTime, float SwitchTime)
{
	Vector2f Size = Vector2f(static_cast<float>(sprite->getTexture()->getSize().x), static_cast<float>(sprite->getTexture()->getSize().y));
	Vector2f OriginPos = Vector2f(Size.x / (SpriteCount.x * 2), Size.y / (SpriteCount.y * 2));
	sprite->setOrigin(OriginPos);
	TotalTime += DeltaTime;

	if (TotalTime > SwitchTime)
	{
		TotalTime -= SwitchTime;
		frame.x++;
		if (frame.x > 3) { frame.x = 0; }
		UVrectCalculate(*sprite, frame);
		sprite->setTextureRect(UVrect);
	}
}

void Animation::KeyPress()
{
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) { Moving.x = 9; }
	else { Moving.x = 5; }
}

void Animation::EnermyMove(Sprite * player, Sprite * Enermy)
{
	Vector2f PlayerPos = Vector2f(player->getPosition());
	Vector2f EnermyPos = Vector2f(Enermy->getPosition());

	if ((EnermyPos.x - PlayerPos.x) > 10) { frame.y = 1; }
	if ((EnermyPos.y - PlayerPos.y) < -10) { frame.y = 0; }
	if ((EnermyPos.x - PlayerPos.x) < -10) { frame.y = 2; }
	if ((EnermyPos.y - PlayerPos.y) > 10) { frame.y = 3; }
}