#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<time.h>
#include"Animation.h"
#include"Collision.h"
#include"Enermy.h"
#include"HighScore.h"
#include"InputName.h"
#include"Map.h"
#include"MapSprite.h"
#include"Menu.h"
#include"Move.h"
#include"Object.h"
#include"Player.h"
using namespace std;
using namespace sf;

int main()
{
	// init
	RenderWindow window(VideoMode(1280,720),"Falling Sky [ReComponent]",Style::Default);
	View view(Vector2f(0.0f, 0.0f), Vector2f(1280.0f / 1.5f, 720.0f / 1.5f));
	Player *player = new Player("GameAssets/Character/Knight.png", Vector2u(9, 1), 1.0f, Vector2f(3.0f, 3.0f));
	Map mainmap("GameAssets/Map/MapMain/Map.png");
	Enermy *aooni = new Enermy("GameAssets/Monster/aooni.png", Vector2u(4, 4), 1.1f, Vector2f(1.f, 1.f));
	
	Object *object = new Object("GameAssets/Map/MapCollision/MapCollision.png");
	Object *objectitem1 = new Object("GameAssets/ITEM/item1Sprite.png");
	Object *objectitem2 = new Object("GameAssets/ITEM/item2Sprite.png");
	Object *objectitem3 = new Object("GameAssets/ITEM/item3Sprite.png");
	Object *objectitem4 = new Object("GameAssets/ITEM/item4-sprite.png");
	Object *objectitem5 = new Object("GameAssets/ITEM/item5-sprite.png");
	Object *objectitem6 = new Object("GameAssets/ITEM/item6-sprite.png");
	Object *objectitem7 = new Object("GameAssets/ITEM/item7-sprite.png");
	Object *objectitem8 = new Object("GameAssets/ITEM/item8-sprite.png");
	Object *objectitem9 = new Object("GameAssets/ITEM/item9-sprite.png");
	Collision pixelcollision;
	Music music;
	Music BGM; 
	Music step;
	RectangleShape fade(Vector2f(8400.f, 8400.f));
	Texture animationtex;
	Sprite animationMap;
	MapSprite item1, item2, item3;
	MapSprite item4, item5, item6;
	MapSprite item7, item8, item9;
	Font font;
	Text text;
	Text name;
	Text E;
	Clock clock, clock1, spawn, Isborn, count;
	Time time, spawntime, isborn, timecount;
	HighScore highscore;
	// init
	aooni->sprite.setPosition(Vector2f(0.0f, 0.0f));
	return 0;
}