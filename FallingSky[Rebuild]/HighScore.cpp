#include "HighScore.h"

HighScore::HighScore()
{
	
}

HighScore::~HighScore()
{
}

void HighScore::ReadFile(RenderWindow &window)
{
	ifstream loadFile;
	loadFile.open("example.txt");
	while (!loadFile.eof()) {
		string tempName;
		float tempScore;
		loadFile >> tempName >> tempScore;
		cout << ">> \"" << tempName << "\" " << tempScore << endl;
		scoreboard.push_back({ tempScore,tempName });
	}
	loadFile.close();
	sort(scoreboard.begin(), scoreboard.end(), less<pair<float, string>>());
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed: window.close(); break;
			case Event::KeyPressed:
				switch (event.key.code) {
				case Keyboard::C: { window.close(); break; }
				default: break;
				}
			default:  break;
			}
		}
		
		window.clear();
		int cnt = 0;
		for (vector<pair<float, string>>::iterator i = scoreboard.begin(); i != scoreboard.end(); ++i) {
			++cnt;
			if (cnt > 5) break;
			Font myfont;
			myfont.loadFromFile("GameAssets/FONT/Roboto-Black.ttf");
			Text a, b;
			a.setString(to_string(i->first));
			a.setFont(myfont);
			a.setCharacterSize(40);
			a.setPosition(static_cast<float>( 700),static_cast<float>( 80 + (80 * cnt)));
			window.draw(a);
			b.setString(i->second);
			b.setFont(myfont);
			b.setCharacterSize(40);
			b.setPosition(static_cast<Vector2f>( Vector2i( 300, 80 + (80 * cnt))));
			window.draw(b);
		}
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			break;
		}
		window.display();
	}
}

void HighScore::WriteFile(string name, const float Score)
{
	ofstream myFile;
	myFile.open("example.txt", ios::out | ios::app);
	myFile << "\n" << name << " " << Score;
	myFile.close();
}