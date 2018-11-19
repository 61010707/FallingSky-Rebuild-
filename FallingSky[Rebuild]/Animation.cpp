#include "Animation.h"

Animation::Animation(Vector2u SprtieCount)
{
	this->SpriteCount = SprtieCount;
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

void Animation::animation(Sprite *sprite, float DeltaTime, float SwitchTime)
{
	sprite->setOrigin(8.0f,14.0f);
	TotalTime += DeltaTime;

	if (TotalTime > SwitchTime)
	{
		TotalTime -= SwitchTime;
		frame.x++;
		if (frame.x > SpriteCount.x - 1)
		{
			frame.x = 0;
		}
		UVrectCalculate(*sprite, frame);
		sprite->setTextureRect(UVrect);
	}
}