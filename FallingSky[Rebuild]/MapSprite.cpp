#include "MapSprite.h"

MapSprite::MapSprite()
{
	sprite.setScale(4.f, 4.f);
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