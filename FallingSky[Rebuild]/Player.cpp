#include "Player.h"

Player::Player(String PlayerPath, Vector2u SpriteCount) :
	animation(SpriteCount), move()
{
	this->PlayerPath = PlayerPath;
	this->SpriteCount = SpriteCount;

	Sprite.setScale(Scale);
}

Player::~Player()
{
}

void Player::CreateSprite()
{
	Texture.loadFromFile(PlayerPath);
	Sprite.setTexture(Texture);
}

void Player::Update(float DeltaTime, float SwitchTime)
{
	CreateSprite();
	animation.animation(&Sprite, DeltaTime, SwitchTime);
	move.KeyboardMove(&Sprite);
}

void Player::draw(RenderWindow * window)
{
	window->draw(Sprite);
}