#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Player.h"
#include"Animation.h"
#include"Map.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1024, 1024), "Falling Sky[Remaster]", Style::Default);
	Player player("GameAssets/Character/Knight.png", Vector2u(9, 1), 1.5f, Vector2f(3.0f, 3.0f));
	Map mainmap("GameAssets/Map/MapMain/walls.png");
	Clock clock;
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

		player.Update(Deltatime, 0.15f);

		window.clear();

		mainmap.Draw(&window);

		player.draw(&window);

		window.display();
	}
	return 0;
}