#include "Move.h"

Move::Move(float speed, Vector2f Scale)
{
	this->speed = speed;
	this->Scale = Scale;
}

Move::~Move()
{
}

void Move::EnermyMove(Sprite *player, Sprite *Enermy)
{
	Vector2f PlayerPos = Vector2f(player->getPosition());
	Vector2f EnermyPos = Vector2f(Enermy->getPosition());

	if (EnermyPos.x > PlayerPos.x) { SpeedCharacter.x = -speed; }
	else if (EnermyPos.x < PlayerPos.x) { SpeedCharacter.x = speed; }
	else { SpeedCharacter.x = 0.0f; }

	if (EnermyPos.y > PlayerPos.y) { SpeedCharacter.y = -speed; }
	else if (EnermyPos.y < PlayerPos.y) { SpeedCharacter.y = speed; }
	else { SpeedCharacter.y = 0.0f; }
	Enermy->move(SpeedCharacter);
}

void Move::KeyboardMove(Sprite *sprite)
{
	SpeedCharacter = Vector2f(0.0f, 0.0f);

	Vector2f SpriteScale = Scale;

	if (Keyboard::isKeyPressed(Keyboard::W)) { SpeedCharacter.y = -speed; }
	if (Keyboard::isKeyPressed(Keyboard::A)) { SpeedCharacter.x = -speed; SpriteScale.x = -(SpriteScale.x); }
	if (Keyboard::isKeyPressed(Keyboard::S)) { SpeedCharacter.y = speed; }
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		SpeedCharacter.x = speed;
		if (SpriteScale.x < 0.0f) { SpriteScale.x = -(SpriteScale.x); }
	}
	sprite->setScale(SpriteScale);
	sprite->move(SpeedCharacter);
}