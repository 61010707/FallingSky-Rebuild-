#include "MapSprite.h"

MapSprite::MapSprite()
{
	sprite.setScale(3.f, 3.f);
}

MapSprite::~MapSprite()
{
}

void MapSprite::Create(String TexturePath)
{
	texture.loadFromFile(TexturePath);
	sprite.setTexture(texture);
}

void MapSprite::draw(RenderWindow * window)
{
	window->draw(sprite);
}