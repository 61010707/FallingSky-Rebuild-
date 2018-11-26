#include"Animation.h"
#include"Collision.h"
#include"Enermy.h"
#include"HighScore.h"
#include"InputName.h"
#include"Map.h"
#include"MapSprite.h"
#include"Object.h"
#include"Player.h"
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<vector>
using namespace std;
using namespace sf;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(1024, 840);
}
int main()
{
	RenderWindow window(VideoMode(1280, 720), "Falling Sky[Remaster]", Style::Default);

	View view(Vector2f(0.0f, 0.0f), Vector2f(1280.0f / 1.5f, 720.0f / 1.5f));

	srand(time(NULL));

	Player *player = new Player("GameAssets/Character/Knight.png", Vector2u(9, 1), 1.0f, Vector2f(3.0f, 3.0f));

	Map mainmap("GameAssets/Map/MapMain/Map.png");

	Enermy *aooni = new Enermy("GameAssets/Monster/aooni.png", Vector2u(4, 4), 1.1f, Vector2f(1.f, 1.f));
	aooni->sprite.setPosition(Vector2f(0.0f, 0.0f));

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
	Vector2f PlayerPos, EnermyPos, OldPlayerPos;
	Vector2f DeltaDistance;
	float Deltatime;
	int randtime;
	FloatRect interSect;
	//---------------------//
	Music music, BGM, step;
	music.openFromFile("GameAssets/BGM/Walk.wav");
	music.setVolume(100);
	//music.play();
	music.setLoop(true);

	BGM.openFromFile("GameAssets/BGM/BGm.wav");
	BGM.setVolume(50);
	//BGM.play();
	BGM.setLoop(true);

	int transparency = 0;
	RectangleShape fade(Vector2f(8400.f, 8400.f));
	bool SpawnState = false;

	Texture animationtex;
	animationtex.loadFromFile("GameAssets/Map/MapAnimation/Animation.png");

	Sprite animationMap;
	animationMap.setTexture(animationtex);
	animationMap.setTextureRect(IntRect(0, 0, animationtex.getSize().x, animationtex.getSize().y / 3));
	animationMap.setScale(3.f, 3.f);

	float TotalTime = 0.f, SwitchTime = 0.2f;
	Vector2i mapframe = Vector2i(0, 0);

	MapSprite item1, item2, item3;
	MapSprite item4, item5, item6;
	MapSprite item7, item8, item9;

	Font font;
	font.loadFromFile("GameAssets/FONT/Pspimpdeed.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(50);

	Text name;
	name.setFont(font);
	name.setCharacterSize(80);
	name.setString("Pasawee	laearun   61010707");
	name.setFillColor(Color(255, 255, 255, 80));

	Text E;
	E.setFont(font);
	E.setCharacterSize(20);
	E.setString("Press E");
	E.setFillColor(Color(255, 255, 255, 255));

	Clock clock, clock1, spawn, Isborn, count;
	Time time, spawntime, isborn, timecount;
	bool drawText = false;
	bool iT1 = true, iT2 = true, iT3 = true, iT4 = true, iT5 = true, iT6 = true, iT7 = true, iT8 = true, iT9 = true;

	HighScore highscore;

	Texture firstpage;
	firstpage.loadFromFile("GameAssets/page/main.png");
	Sprite FirstPage;
	FirstPage.setTexture(firstpage);
	FirstPage.setScale(.35f, .35f);
	FirstPage.setOrigin(firstpage.getSize().x / 2, firstpage.getSize().y / 2);

	Texture diedpage;
	diedpage.loadFromFile("GameAssets/page/Died.png");
	Sprite DiedPage;
	DiedPage.setTexture(diedpage);
	DiedPage.setScale(.4f, .4f);
	Vector2f DiedSize = static_cast<Vector2f>(DiedPage.getTexture()->getSize());
	DiedPage.setOrigin(DiedSize.x / 2, DiedSize.y / 2);

	Texture SurvirTex;
	SurvirTex.loadFromFile("GameAssets/page/survior.png");
	Sprite SurviorSprite;
	SurviorSprite.setTexture(SurvirTex);
	SurviorSprite.setScale(.35f, .35f);
	Vector2f SurviorSize = static_cast<Vector2f>(SurviorSprite.getTexture()->getSize());
	SurviorSprite.setOrigin(SurviorSize.x / 2, SurviorSize.y / 2);
	bool isSurvior = false;
	int GameState = 0;

	SoundBuffer bufferIntro;
	bufferIntro.loadFromFile("GameAssets/BGM/intro.WAV");
	Sound Intro;
	Intro.setBuffer(bufferIntro);
	Intro.setLoop(true);
	Intro.play();

	SoundBuffer bufferDied;
	bufferDied.loadFromFile("GameAssets/BGM/died.WAV");
	Sound Died;
	Died.setBuffer(bufferDied);

	SoundBuffer bufferDead;
	bufferDead.loadFromFile("GameAssets/BGM/Dead.WAV");
	Sound Dead;
	Dead.setBuffer(bufferDead);
	Dead.setLoop(true);

	SoundBuffer bufferPickup;
	bufferPickup.loadFromFile("GameAssets/BGM/pickup.WAV");
	Sound Pickup;
	Pickup.setBuffer(bufferPickup);
	{FirstMenu:
	view.setCenter(FirstPage.getPosition());
	window.setView(view);
	player->SetPosition(Vector2f(120, 350));
	aooni->sprite.setPosition(Vector2f(-250, -250));
	SpawnState = false;
	GameState = 0;
	sleep(milliseconds(90));
	while (GameState == 0)
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed: window.close(); break;
			default:  break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Return)) {
			GameState = 1;
			break;
		}

		window.clear();
		window.draw(FirstPage);
		window.display();
		sleep(microseconds(300));
	}
	}

	view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
	view.setSize(1280, 720);
	window.setView(view);
	highscore.ReadFile(window);

	randtime = rand() % 3 + 1;
	int EndGameCount = 0;

	if (randtime == 1)
	{
		item1.Create("GameAssets/ITEM/item1Sprite.png"); item1.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item1.GetSize().x, item1.GetSize().y)));
		item2.Create("GameAssets/ITEM/item2Sprite.png"); item2.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item2.GetSize().x, item2.GetSize().y)));
		item3.Create("GameAssets/ITEM/item3Sprite.png"); item3.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item3.GetSize().x, item3.GetSize().y)));
	}

	if (randtime == 2) {
		item4.Create("GameAssets/ITEM/item4-sprite.png"); item4.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item4.GetSize().x, item4.GetSize().y)));
		item5.Create("GameAssets/ITEM/item5-sprite.png"); item5.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item5.GetSize().x, item5.GetSize().y)));
		item6.Create("GameAssets/ITEM/item6-sprite.png"); item6.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item6.GetSize().x, item6.GetSize().y)));
	}
	if (randtime == 3) {
		item7.Create("GameAssets/ITEM/item7-sprite.png"); item7.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item7.GetSize().x, item7.GetSize().y)));
		item8.Create("GameAssets/ITEM/item8-sprite.png"); item8.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item8.GetSize().x, item8.GetSize().y)));
		item9.Create("GameAssets/ITEM/item9-sprite.png"); item9.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item9.GetSize().x, item9.GetSize().y)));
	}

	String Timer;
	InputName input;
	input.INPUTNAME(&window);
	bool isDied = false;
	Intro.pause();
	BGM.play();
	music.play();
	clock.restart().Zero;
	count.restart().Zero;
	spawn.restart().Zero;
	spawntime.Zero;
	time.Zero;

	while (window.isOpen())
	{
		Deltatime = clock.restart().asSeconds();
		time = clock1.getElapsedTime();
		timecount = count.getElapsedTime();

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed: window.close(); break;
				/*		case sf::Event::Resized: ResizeView(window, view); break;*/
			case Event::KeyPressed:
				OldPlayerPos = player->sprite.getPosition();
				switch (event.key.code) {
				case Keyboard::C: { window.close(); break; }
				case Keyboard::M: { EndGameCount = 3; break; }
				default: break;
				}
			default:  break;
			}
		}

		TotalTime += Deltatime;
		if (TotalTime > SwitchTime)
		{
			TotalTime -= SwitchTime;  mapframe.y++;
			if (mapframe.y > 2) { mapframe.y = 0; }
			animationMap.setTextureRect(IntRect(Vector2i(0, mapframe.y*(animationtex.getSize().y / 3)), Vector2i(animationtex.getSize().x, animationtex.getSize().y / 3)));
		}
		view.setCenter(PlayerPos);
		view.setSize(1280 / 1.5, 720 / 1.5);
		player->Update(Deltatime, 0.15f);
		DeltaDistance = Vector2f(EnermyPos.x - PlayerPos.x, EnermyPos.y - PlayerPos.y);
		//--------------------------------------------------------------------------------------------------//

		//--------------------------------------------------------------------------------------------------//
		if (object->CheckCollision(&aooni->sprite)) { aooni->sprite.setPosition(EnermyPos.x, EnermyPos.y); }
		else { EnermyPos = aooni->sprite.getPosition(); }

		if (object->CheckCollision(&player->sprite)) { player->sprite.setPosition(PlayerPos.x, PlayerPos.y); }
		else { PlayerPos = player->sprite.getPosition(); }
		if (pixelcollision.PixelPerfectTest(player->sprite, aooni->sprite, 0))
		{
			Died.play();
			Died.setVolume(300);
			isDied = true;
			break;
		}

		input.player.setPosition(PlayerPos.x - 30, PlayerPos.y - 40);
		input.player.setCharacterSize(20);

		if (randtime == 1)
		{
			if (objectitem1->CheckCollision(&player->sprite) && iT1 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20); drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) { EndGameCount += 1; iT1 = false; Pickup.play(); }
			}
			else { E.setPosition(-110, -110); }

			if (objectitem2->CheckCollision(&player->sprite) && iT2 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20);  drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1;  iT2 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }

			if (objectitem3->CheckCollision(&player->sprite) && iT3 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20);  drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1; iT3 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }
		}

		if (randtime == 2)
		{
			if (objectitem4->CheckCollision(&player->sprite) && iT4 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20); drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1; iT4 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }

			if (objectitem5->CheckCollision(&player->sprite) && iT5 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20); drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1; iT5 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }

			if (objectitem6->CheckCollision(&player->sprite) && iT6 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20); drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1; iT6 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }
		}

		if (randtime == 3)
		{
			if (objectitem7->CheckCollision(&player->sprite) && iT7 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20); drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1; iT7 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }

			if (objectitem8->CheckCollision(&player->sprite) && iT8 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20); drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1; iT8 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }

			if (objectitem9->CheckCollision(&player->sprite) && iT9 == true) {
				E.setPosition(PlayerPos.x, PlayerPos.y + 20); drawText = true;
				if (Keyboard::isKeyPressed(Keyboard::E)) {
					EndGameCount += 1; iT9 = false; Pickup.play();
				}
			}
			else { E.setPosition(-110, -110); }
		}

		if (EndGameCount >= 3)
		{
			highscore.WriteFile(input.player.getString(), static_cast<int>(timecount.asSeconds()));
			isSurvior = true;
			break;
		}

		if (SpawnState == false) { Isborn.restart(); spawntime = spawn.getElapsedTime(); if (spawntime.asSeconds() > 10.0f) { aooni->EnermyMove.speed += 0.01f; SpawnState = true; } }
		else { spawn.restart(); isborn = Isborn.getElapsedTime(); if (isborn.asSeconds() > 30.0f) { SpawnState = false; } }
		if (SpawnState == true)
		{
			if (DeltaDistance.x < -700.0f) { aooni->EnermyMove.speed += 0.002f; music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x - 700.f, PlayerPos.y); }
			else if (DeltaDistance.x > 700.f) { aooni->EnermyMove.speed += 0.002f;  music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x + 700.f, PlayerPos.y); }
			else if (DeltaDistance.y < -380.f) { aooni->EnermyMove.speed += 0.002f; music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y - 350.f); }
			else if (DeltaDistance.y > 380.f) { aooni->EnermyMove.speed += 0.002f; music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y + 285.f); }
			else { music.setVolume(100); }
		}

		else { aooni->sprite.setPosition(-110, -110); music.setVolume(0); }
		//------------------------------------------------------------------------------------------------------------------------//
		aooni->Update(Deltatime, 0.15f, &player->sprite);

		window.setView(view);
		name.setPosition(PlayerPos.x - 370, PlayerPos.y - 50);
		text.setPosition(PlayerPos.x + 370, PlayerPos.y - 250);
		Timer = to_string(static_cast<int>(timecount.asSeconds()));
		text.setString(Timer);
		window.clear();
		mainmap.Draw(&window);
		window.draw(animationMap);
		if (randtime == 1) {
			if (iT1 == true) { item1.draw(&window); }
			if (iT2 == true) { item2.draw(&window); }
			if (iT3 == true) { item3.draw(&window); }
		}
		if (randtime == 2) {
			if (iT4 == true) { item4.draw(&window); }
			if (iT5 == true) { item5.draw(&window); }
			if (iT6 == true) { item6.draw(&window); }
		}
		if (randtime == 3) {
			if (iT7 == true) { item7.draw(&window); }
			if (iT8 == true) { item8.draw(&window); }
			if (iT9 == true) { item9.draw(&window); }
		}

		player->draw(&window);
		aooni->Draw(window);

		if (time.asSeconds() > 1.0f)
		{
			transparency += 2;
			fade.setFillColor(Color(0, 0, 0, transparency));
			clock1.restart();
		}
		window.draw(text);
		window.draw(name);
		window.draw(E);
		window.draw(input.player);
		window.draw(fade);

		window.display();
	}

	music.pause();
	BGM.pause();
	if (isDied == true)
	{
		Dead.play();
		Dead.setVolume(300);
		Text PressEnter;
		PressEnter.setFont(font);
		PressEnter.setCharacterSize(40);
		PressEnter.setPosition(DiedPage.getPosition().x - 150, DiedPage.getPosition().y + 150);
		PressEnter.setString("Press Enter to exit");
		while (window.isOpen())
		{
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				GameState = 0;

				goto FirstMenu;
				break;
			}
			view.setCenter(DiedPage.getPosition());
			window.setView(view);
			window.clear();
			window.draw(DiedPage);
			window.draw(PressEnter);
			window.display();
		}
	}

	if (isSurvior == true)
	{
		BGM.play();
		BGM.setVolume(30);
		Text PressEnter;
		PressEnter.setFont(font);
		PressEnter.setCharacterSize(80);
		PressEnter.setPosition(DiedPage.getPosition().x + 20, DiedPage.getPosition().y - 10);
		PressEnter.setString(Timer);
		while (window.isOpen())
		{
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				GameState = 0;
				goto FirstMenu;
				break;
			}
			view.setCenter(SurviorSprite.getPosition());
			window.setView(view);
			window.clear();
			window.draw(SurviorSprite);
			window.draw(PressEnter);
			window.display();
		}
	}
	return 0;
}