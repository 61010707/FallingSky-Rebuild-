#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class HighScore
{
public:
	HighScore();
	~HighScore();
	void ReadFile(RenderWindow &window);
	void WriteFile(string name,float Score);
private:
	vector<pair<int, string>> scoreboard;
};

