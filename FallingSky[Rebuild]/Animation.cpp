#include "Animation.h"

Animation::Animation(Vector2i SprtieCount)
{
	this->SpriteCount = SprtieCount;
}

Animation::~Animation()
{
}

void Animation::animation(Sprite &sprite, float DeltaTime, float SwitchTime)
{
	this->sprite = sprite;
	Size = sprite.getTexture()->getSize();
	TotalTime += DeltaTime;
	if (DeltaTime >= TotalTime)
	{
		DeltaTime -= TotalTime;
		UVrect.width = Size.x / SpriteCount.x;
		cout << UVrect.width << endl;
	}
}