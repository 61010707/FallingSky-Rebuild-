#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Player.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1024, 1024), "Falling Sky[Remaster]", Style::Default);
	Player player("GameAssets/Character/Knight.png", Vector2i(9, 1));
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

		player.Update(Deltatime,0.2f);

		window.clear();

		player.draw(&window);

		window.display();
	}
	return 0;
}