#include "Player.h"

Player::Player(String PlayerPath, Vector2u SpriteCount) :
	animation(SpriteCount)
{
	this->PlayerPath = PlayerPath;
	this->SpriteCount = SpriteCount;
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
}

void Player::draw(RenderWindow * window)
{
	window->draw(Sprite);
}