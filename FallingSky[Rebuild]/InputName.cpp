#include "InputName.h"

InputName::InputName()
{
}

InputName::~InputName()
{
}

void InputName::INPUTNAME(RenderWindow * window)
{
	YourName.setString("Name :  ");
	YourName.setCharacterSize(60);
	YourName.setPosition(window->getSize().x / 2 - 300, window->getSize().y / 2);
	YourName.setFont(font);

	Title1.setString(" What's your name ? ");
	Title1.setCharacterSize(80);
	Title1.setPosition(window->getSize().x / 2 - 370, window->getSize().y - 700);
	Title1.setFont(font);

	Title2.setString("  Press Enter ");
	Title2.setCharacterSize(40);
	Title2.setPosition(window->getSize().x / 2 - 150, window->getSize().y - 100);
	Title2.setFont(font);

	yourname.clear();
	name = {};
	player.setString(yourname);
	font.loadFromFile("GameAssets/FONT/Roboto-Black.ttf");
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode == '\b') { yourname.erase(yourname.getSize() - 1, 1); player.setFont(font); player.setString(yourname); }
				else {
					yourname += static_cast<char>(event.text.unicode); name += static_cast<char>(event.text.unicode);
					if ((event.text.unicode <= 128)) { player.setFont(font); player.setString(yourname); }
				}
				player.setCharacterSize(60);
				player.setPosition(window->getSize().x / 2 - 100, window->getSize().y / 2);
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Return) { player.setString(yourname); }
			}
			if (event.type == sf::Event::Closed) window->close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Return)) { break; }
		Blink += 1;
		window->clear();
		window->draw(player);
		window->draw(Title1);
		if (Blink >= 300) {
			window->draw(Title2);
			delay += 1; if (delay >= 300) { Blink = 0; delay = 0; }
		}

		window->draw(YourName);

		window->display();
	}
}