#include "Object.h"



Object::Object(String objectPath):MapObject()
{
	MapObject.Create(objectPath);
}


Object::~Object()
{
}
