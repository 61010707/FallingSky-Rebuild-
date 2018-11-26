#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<SFML/Graphics.hpp>
#include<algorithm>
#include<iomanip>
using namespace std;
using namespace sf;
class HighScore
{
public:
	HighScore();
	~HighScore();
	void ReadFile(RenderWindow &window);
	void WriteFile(string name, int Score);
private:
	vector<pair<int, string>> scoreboard;
};
