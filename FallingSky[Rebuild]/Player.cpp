#include "Player.h"



Player::Player(String PlayerPath, Vector2i SpriteCount)
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

void Player::Update()
{
	CreateSprite();
}

void Player::draw(RenderWindow * window)
{
	window->draw(Sprite);
}
