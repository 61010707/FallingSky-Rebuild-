#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
class Collision
{
public:
	Collision();
	~Collision();
	Uint8 GetPixel(const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y);
	Uint8* GetMask(const sf::Texture* tex);
	Uint8* CreateMask(const sf::Texture* tex, const sf::Image& img);

	bool PixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit);
private:
	map<const sf::Texture*, sf::Uint8*> Bitmasks;
};
