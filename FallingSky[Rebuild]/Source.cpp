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
	// init - Class Constructor
	RenderWindow window(VideoMode(1280, 720), "Falling Sky [ReComponent]", Style::Default);
	Clock clock, clock1, spawn, Isborn, count;
	Collision pixelcollision;
	Enermy *aooni = new Enermy("GameAssets/Monster/aooni.png", Vector2u(4, 4), 1.1f, Vector2f(1.f, 1.f));
	Font font;
	HighScore highscore;
	Map mainmap("GameAssets/Map/MapMain/Map.png");
	MapSprite item1, item2, item3;
	MapSprite item4, item5, item6;
	MapSprite item7, item8, item9;
	Music BGM;
	Music music;
	Music step;
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
	Player *player = new Player("GameAssets/Character/Knight.png", Vector2u(9, 1), 1.0f, Vector2f(3.0f, 3.0f));
	RectangleShape fade(Vector2f(8400.f, 8400.f));
	Sprite animationMap;
	Text E;
	Text name;
	Text text;
	Texture animationtex;
	Time timefade; 
	Time spawntime;
	Time isborn;
	Time timecount;
	View view(Vector2f(0.0f, 0.0f), Vector2f(1280.0f / 1.5f, 720.0f / 1.5f));
	// init - variable
	srand(static_cast<unsigned int>(time(NULL)));
	bool drawText = false;
	bool iT1 = true; 
	bool iT2 = true;
	bool iT3 = true;
	bool iT4 = true;
	bool iT5 = true;
	bool iT6 = true;
	bool iT7 = true;
	bool iT8 = true;
	bool iT9 = true;
	bool SpawnState = false;
	float Deltatime = 0.0f;
	float TotalTime = 0.f, SwitchTime = 0.2f;
	FloatRect interSect;
	int EndGameCount = 0;
	int randtime = 0;
	int transparency = 0;
	Vector2f DeltaDistance;
	Vector2f PlayerPos, EnermyPos, OldPlayerPos;
	Vector2i mapframe = Vector2i(0, 0);
	//init - object setting
	animationMap.setScale(3.f, 3.f);
	animationMap.setTexture(animationtex);
	animationMap.setTextureRect(IntRect(0, 0, animationtex.getSize().x, animationtex.getSize().y / 3));
	
	animationtex.loadFromFile("GameAssets/Map/MapAnimation/Animation.png");
	
	aooni->sprite.setPosition(Vector2f(0.0f, 0.0f));
	
	BGM.openFromFile("GameAssets/BGM/BGm.wav");
	BGM.play();
	BGM.setLoop(true);
	BGM.setVolume(50);
	
	E.setCharacterSize(20);
	E.setFillColor(Color(255, 255, 255, 255));
	E.setFont(font);
	E.setString("Press E");
	
	font.loadFromFile("GameAssets/FONT/Pspimpdeed.ttf");
	
	music.openFromFile("GameAssets/BGM/Walk.wav");
	music.play();
	music.setLoop(true);
	music.setVolume(100);
	
	name.setCharacterSize(80);
	name.setFillColor(Color(255, 255, 255, 80));
	name.setFont(font);
	name.setString("Pasawee	laearun   61010707");
	
	text.setCharacterSize(50);
	text.setFont(font);
	//init - End

	//Game Loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed: window.close(); break;
			case Event::KeyPressed:
				OldPlayerPos = player->sprite.getPosition();
				switch (event.key.code) {
				case Keyboard::C: { window.close(); break; }
				default: break;
				}
			default:  break;
			}
		}
	}
	//Update
	//Update
	//Game Loop
	return 0;
}