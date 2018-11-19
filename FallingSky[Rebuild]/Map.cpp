#include "Map.h"

Map::Map(String MainMapPath, String CollisionMapPath) :MainMap(), CollisionMap()
{
	this->MainMapPath = MainMapPath;
	this->CollisionMapPath = CollisionMapPath;
	MainMap.Create(MainMapPath);
	CollisionMap.Create(CollisionMapPath);
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
	CollisionMap.Create(CollisionMapPath);
}

void Map::Draw(RenderWindow*window)
{
	CollisionMap.draw(window);
	MainMap.draw(window);
}