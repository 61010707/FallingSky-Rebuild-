#include "Map.h"

Map::Map(String MainMapPath) :MainMap()
{
	this->MainMapPath = MainMapPath;
	Update();
}

Map::~Map()
{
}

void Map::Update()
{
	MainMap.Create(MainMapPath);
}

void Map::MapCollision()
{
}

void Map::Draw(RenderWindow*window)
{
	MainMap.draw(window);
}