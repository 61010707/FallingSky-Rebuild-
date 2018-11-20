#include "Object.h"

Object::Object(String objectPath) :MapObject(), collision()
{
	MapObject.Create(objectPath);
}

Object::~Object()
{
}

bool Object::CheckCollision(Sprite * object1)
{
	return collision.PixelPerfectTest(*object1, MapObject.sprite, -100);
}