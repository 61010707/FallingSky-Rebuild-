#include "Player.h"

Player::Player(String PlayerPath, Vector2u SpriteCount) :
	animation(SpriteCount), move()
{
	this->PlayerPath = PlayerPath;
	this->SpriteCount = SpriteCount;

	Vector2f Origin = Vector2f(Texture.getSize().x / (SpriteCount.x*2.0f), Texture.getSize().y / 2.0f);

	Sprite.setScale(Scale);
	Sprite.setOrigin(0.0f, 0.0f);
	Sprite.setTextureRect(IntRect(0, 0, 16, 28));
	Sprite.setPosition(512, 512);
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
	move.KeyboardMove(&Sprite, Scale);
}

void Player::draw(RenderWindow * window)
{
	window->draw(Sprite);
}