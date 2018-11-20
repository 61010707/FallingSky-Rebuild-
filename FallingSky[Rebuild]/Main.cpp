#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>
#include"Player.h"
#include"Animation.h"
#include"Map.h"
#include"Object.h"
#include"Enermy.h"
#include<vector>
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(840, 840), "Falling Sky[Remaster]", Style::Default);
	View view(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 512.f));
	Player *player = new Player("GameAssets/Character/Knight.png", Vector2u(9, 1), 0.8f, Vector2f(3.0f, 3.0f));
	Map mainmap("GameAssets/Map/MapMain/walls.png");
	Enermy *aooni = new Enermy("GameAssets/Monster/aooni.png", Vector2u(4, 4), 0.81f, Vector2f(1.4f, 1.4f));
	aooni->sprite.setPosition(Vector2f(300.0f, 300.0f));
	Object *object = new Object("GameAssets/Map/MapCollision/walls_collisionWall.png");

	vector<Object> objects;
	Vector2f PlayerPos, EnermyPos;
	Vector2f DeltaDistance;
	Clock clock, clock1;
	Time time;
	float Deltatime;
	Text text;
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

	while (window.isOpen())
	{
		Deltatime = clock.restart().asSeconds();
		time = clock1.getElapsedTime();
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		view.setCenter(PlayerPos);
		player->Update(Deltatime, 0.15f);
		DeltaDistance = Vector2f(EnermyPos.x - PlayerPos.x, EnermyPos.y - PlayerPos.y);
		//cout << DeltaDistance.x << "  " << DeltaDistance.y << endl;

		if (DeltaDistance.x < -380.0f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x - 285.f, PlayerPos.y); }
		else if (DeltaDistance.x > 380.f) { aooni->sprite.setPosition(PlayerPos.x + 285.f, PlayerPos.y); }
		else if (DeltaDistance.y < -380.f) { aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y - 300.f); }
		else if (DeltaDistance.y > 380.f) { aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y + 285.f); }
		else
		{
			music.setVolume(100);
		}
		if (object->CheckCollision(&aooni->sprite)) { aooni->sprite.setPosition(EnermyPos.x, EnermyPos.y); }
		else { EnermyPos = aooni->sprite.getPosition(); }
		if (object->CheckCollision(&player->sprite)) { player->sprite.setPosition(PlayerPos.x, PlayerPos.y); }
		else { PlayerPos = player->sprite.getPosition(); }

		aooni->Update(Deltatime, 0.15f, &player->sprite);
		window.setView(view);
		window.clear();

		mainmap.Draw(&window);

		player->draw(&window);
		aooni->Draw(window);
		window.display();
	}
	return 0;
}