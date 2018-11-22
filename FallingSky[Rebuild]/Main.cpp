#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>
#include"Player.h"
#include"Animation.h"
#include"Map.h"
#include"Object.h"
#include"Enermy.h"
#include"Collision.h"
#include"MapSprite.h"
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
	Player *player = new Player("GameAssets/Character/Knight.png", Vector2u(9, 1), 0.7f, Vector2f(3.0f, 3.0f));
	Map mainmap("GameAssets/Map/MapMain/Map.png");
	Enermy *aooni = new Enermy("GameAssets/Monster/aooni.png", Vector2u(4, 4), 0.7f, Vector2f(1.f, 1.f));
	aooni->sprite.setPosition(Vector2f(0.0f, 0.0f));
	Object *object = new Object("GameAssets/Map/MapCollision/MapCollision.png");
	Collision pixelcollision;
	vector<Object> objects;
	Vector2f PlayerPos, EnermyPos,OldPlayerPos;
	Vector2f DeltaDistance;
	Clock clock, clock1, spawn, Isborn, count;
	Time time, spawntime, isborn, timecount;
	float Deltatime;

	FloatRect interSect;
	//---------------------//
	Music music, BGM, step;
	music.openFromFile("GameAssets/BGM/Walk.wav");
	music.setVolume(100);
	music.play();
	music.setLoop(true);

	BGM.openFromFile("GameAssets/BGM/BGm.wav");
	BGM.setVolume(50);
	BGM.play();
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
	item1.Create("GameAssets/ITEM/item1Sprite.png"); item1.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item1.GetSize().x, item1.GetSize().y)));
	item2.Create("GameAssets/ITEM/item2Sprite.png"); item2.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item2.GetSize().x, item2.GetSize().y)));
	item3.Create("GameAssets/ITEM/item3Sprite.png"); item3.sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(item3.GetSize().x, item3.GetSize().y)));

	Font font;
	font.loadFromFile("GameAssets/FONT/Pspimpdeed.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(50);

	Text name;
	name.setFont(font);
	name.setCharacterSize(80);
	name.setString("Pasawee	laearun   61010707");
	name.setFillColor(Color(255, 255, 255, 85));

	while (window.isOpen())
	{
		Deltatime = clock.restart().asSeconds();
		time = clock1.getElapsedTime();
		timecount = count.getElapsedTime();
		
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
				/*		case sf::Event::Resized:
							ResizeView(window, view);
							break;*/
			case Event::KeyPressed:
				OldPlayerPos = player->sprite.getPosition();
				switch (event.key.code)
				{
					
				case Keyboard::C: { window.close(); break; }
				case Keyboard::O: {player->sprite.setPosition(OldPlayerPos.x , OldPlayerPos.y-10); }
				case Keyboard::K: {player->sprite.setPosition(OldPlayerPos.x - 10, OldPlayerPos.y); }
				case Keyboard::L: {player->sprite.setPosition(OldPlayerPos.x , OldPlayerPos.y-10); }
				case Keyboard::SemiColon: {player->sprite.setPosition(OldPlayerPos.x + 10, OldPlayerPos.y); }

				default: break;
				}
			default:
				break;
			}
		}
		TotalTime += Deltatime;
		if (TotalTime > SwitchTime)
		{
			TotalTime -= SwitchTime;
			mapframe.y++;
			if (mapframe.y > 2) { mapframe.y = 0; }
			animationMap.setTextureRect(IntRect(Vector2i(0, mapframe.y*(animationtex.getSize().y / 3)), Vector2i(animationtex.getSize().x, animationtex.getSize().y / 3)));
		}
		view.setCenter(PlayerPos);
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
		}
		if (SpawnState == false)
		{
			Isborn.restart();
			spawntime = spawn.getElapsedTime();
			if (spawntime.asSeconds() > 10.0f) { aooni->EnermyMove.speed += 0.01f; SpawnState = true; }
		}
		else
		{
			spawn.restart();
			isborn = Isborn.getElapsedTime();
			if (isborn.asSeconds() > 30.0f) { SpawnState = false; }
		}

		if (SpawnState == true)
		{
			if (DeltaDistance.x < -700.0f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x - 700.f, PlayerPos.y); }
			else if (DeltaDistance.x > 700.f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x + 700.f, PlayerPos.y); }
			else if (DeltaDistance.y < -380.f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y - 350.f); }
			else if (DeltaDistance.y > 380.f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y + 285.f); }
			else { music.setVolume(100); }
		}
		else { aooni->sprite.setPosition(0, 0); music.setVolume(0); }
		//------------------------------------------------------------------------------------------------------------------------//
		aooni->Update(Deltatime, 0.15f, &player->sprite);

		window.setView(view);
		name.setPosition(PlayerPos.x - 370, PlayerPos.y - 50);
		text.setPosition(PlayerPos.x + 370, PlayerPos.y - 250);
		String Timer = to_string(timecount.asSeconds());
		text.setString(Timer);
		window.clear();

		mainmap.Draw(&window);
		window.draw(animationMap);
		item1.draw(&window); item2.draw(&window); item3.draw(&window);
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
		window.draw(fade);

		window.display();

		//sleep(milliseconds(5));
	}
	return 0;
}