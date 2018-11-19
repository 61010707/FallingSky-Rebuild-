#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(1024,1024),"Falling Sky[Remaster]",Style::Default);
	while (window.isOpen())
	{
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
		window.clear();

		window.display();
	}
	return 0;
}