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
	RenderWindow window(VideoMode(840, 840), "Falling Sky[Remaster]", Style::Default);

	View view(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 512.f));
	Player *player = new Player("GameAssets/Character/Knight.png", Vector2u(9, 1), 0.6f, Vector2f(3.0f, 3.0f));
	Map mainmap("GameAssets/Map/MapMain/Map.png");
	Enermy *aooni = new Enermy("GameAssets/Monster/aooni.png", Vector2u(4, 4), 0.35f, Vector2f(1.f, 1.f));
	aooni->sprite.setPosition(Vector2f(300.0f, 300.0f));
	Object *object = new Object("GameAssets/Map/MapCollision/MapCollision.png");
	Collision pixelcollision;
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
	int transparency = 0;
	RectangleShape fade(Vector2f(8400.f, 8400.f));
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
				/*		case sf::Event::Resized:
							ResizeView(window, view);
							break;*/
			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::C:
				{
					window.close();
					break;
				}
				default:
					break;
				}
			default:
				break;
			}
		}
		view.setCenter(PlayerPos);
		player->Update(Deltatime, 0.15f);
		DeltaDistance = Vector2f(EnermyPos.x - PlayerPos.x, EnermyPos.y - PlayerPos.y);

		if (object->CheckCollision(&aooni->sprite)) { aooni->sprite.setPosition(EnermyPos.x, EnermyPos.y); }
		else { EnermyPos = aooni->sprite.getPosition(); }
		if (object->CheckCollision(&player->sprite)) { player->sprite.setPosition(PlayerPos.x, PlayerPos.y); }
		else { PlayerPos = player->sprite.getPosition(); }
		if (pixelcollision.PixelPerfectTest(player->sprite, aooni->sprite, 0))
		{
		}

		if (DeltaDistance.x < -380.0f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x - 285.f, PlayerPos.y); }
		else if (DeltaDistance.x > 380.f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x + 285.f, PlayerPos.y); }
		else if (DeltaDistance.y < -380.f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y - 300.f); }
		else if (DeltaDistance.y > 380.f) { music.setVolume(0); aooni->sprite.setPosition(PlayerPos.x, PlayerPos.y + 285.f); }
		else { music.setVolume(100); }

		aooni->Update(Deltatime, 0.15f, &player->sprite);
		window.setView(view);
		window.clear();

		mainmap.Draw(&window);

		player->draw(&window);
		aooni->Draw(window);

		if (time.asSeconds() > 1.0f)
		{
			if (transparency < 213)
			{
				transparency += 20;
			}

			fade.setFillColor(Color(0, 0, 0, transparency));
			clock1.restart();
		}

		window.draw(fade);
		window.display();
	}
	return 0;
}