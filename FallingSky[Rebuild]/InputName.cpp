#include "InputName.h"

InputName::InputName()
{
}

InputName::~InputName()
{
}

void InputName::INPUTNAME(RenderWindow * window)
{
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
				player.setPosition(200.0f, 100.0f);
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Return) { player.setString(yourname); }
			}
			if (event.type == sf::Event::Closed) window->close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Return)) { break; }
		window->clear();
		window->draw(player);
		window->display();
	}
}