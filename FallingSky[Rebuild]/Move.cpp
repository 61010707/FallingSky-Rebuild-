#include "Move.h"

Move::Move()
{
}

Move::~Move()
{
}

void Move::KeyboardMove(Sprite *sprite)
{
	SpeedCharacter = Vector2f(0.0f, 0.0f);

	Vector2f SpriteScale = sprite->getScale();

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		SpeedCharacter.y = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		SpeedCharacter.x = -speed;
		SpriteScale.x = -(SpriteScale.x);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		SpeedCharacter.y = speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		cout << "D" << endl;
		SpeedCharacter.x = speed;
		if (SpriteScale.x < 0.0f)
		{
			SpriteScale.x = -(SpriteScale.x);
		}
	}
	sprite->setScale(SpriteScale);
	sprite->move(SpeedCharacter);
}