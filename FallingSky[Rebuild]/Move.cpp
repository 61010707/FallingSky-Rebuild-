#include "Move.h"



Move::Move()
{
}


Move::~Move()
{
}

void Move::KeyboardMove(Sprite *sprite)
{
	SpeedCharacter = Vector2f(0.0f,0.0f);

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		cout << "W" << endl;
		SpeedCharacter.y = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		cout << "A" << endl;
		SpeedCharacter.x = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		cout << "S" << endl;
		SpeedCharacter.y = speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		cout << "D" << endl;
		SpeedCharacter.x = speed;
	}
	sprite->move(SpeedCharacter);
	
}
