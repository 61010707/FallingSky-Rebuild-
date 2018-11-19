#include "Move.h"



Move::Move()
{
}


Move::~Move()
{
}

void Move::KeyboardMove(Sprite *sprite,Vector2f Scale)
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
		sprite->setScale(-3.0f,3.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		SpeedCharacter.y = speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		cout << "D" << endl;
		SpeedCharacter.x = speed;
		sprite->setScale(3.0f, 3.0f);
	}
	cout << Scale.x << endl;
	sprite->move(SpeedCharacter);
	
	
}
