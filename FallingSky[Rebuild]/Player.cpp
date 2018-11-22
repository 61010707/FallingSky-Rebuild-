#include "Player.h"

Player::Player(String PlayerPath, Vector2u SpriteCount, float Speed, Vector2f Scale) :
	animation(SpriteCount), move(Speed, Scale)
{
	this->PlayerPath = PlayerPath;
	this->SpriteCount = SpriteCount;
	this->Scale = Scale;
	Vector2f Origin = Vector2f(Texture.getSize().x / (SpriteCount.x*2.0f), Texture.getSize().y / 2.0f);

	sprite.setScale(Scale);
	sprite.setOrigin(0.0f, 0.0f);
	sprite.setTextureRect(IntRect(0, 0, 16, 28));
	sprite.setPosition(120, 350);
	CreateSprite();
}

Player::~Player()
{
}

void Player::CreateSprite()
{
	Texture.loadFromFile(PlayerPath);
	sprite.setTexture(Texture);
}

void Player::Update(float DeltaTime, float SwitchTime)
{
	animation.animation(&sprite, DeltaTime, SwitchTime, true);
	move.KeyboardMove(&sprite);
	
}

void Player::draw(RenderWindow * window)
{
	window->draw(sprite);
}