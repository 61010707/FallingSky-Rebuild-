#include<SFML/Graphics.hpp>
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
	RenderWindow window(VideoMode(512, 512), "Falling Sky[Remaster]", Style::Default);
	View view(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 512.f));

	Player *player = new Player("GameAssets/Character/Knight.png", Vector2u(9, 1), 0.5f, Vector2f(3.0f, 3.0f));
	Map mainmap("GameAssets/Map/MapMain/walls.png");
	Enermy aooni("GameAssets/Monster/aooni.png", Vector2u(4, 4), 0.3f, Vector2f(1.1f, 1.1f));
	aooni.sprite.setPosition(Vector2f(player->sprite.getPosition().x - 50.f, player->sprite.getPosition().y - 50.f));
	Object *object = new Object("GameAssets/Map/MapCollision/walls_collisionWall.png");
	Vector2f PlayerPos;
	Clock clock;
	vector<Object> objects;

	float Deltatime;
	while (window.isOpen())
	{
		Deltatime = clock.restart().asSeconds();
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
		if (object->CheckCollision(&player->sprite)) { player->sprite.setPosition(PlayerPos.x, PlayerPos.y); }
		else { PlayerPos = player->sprite.getPosition(); }

		aooni.Update(Deltatime, 0.15f, &player->sprite);
		window.setView(view);
		window.clear();

		mainmap.Draw(&window);

		player->draw(&window);
		aooni.Draw(window);
		window.display();
	}
	return 0;
}