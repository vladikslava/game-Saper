#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Rules {
	int rulesX = 70;
	int rulesY = 200;
	Texture rules;

	Text Title;
	int titleX = 150;
	int titleY = 100;
	int size = 80;
	Font font;
	Color color = Color(Color::Black);
	Color clear = Color(Color(166, 166, 166));
	Sprite rulesText;
	RenderWindow& windowRules;



public:
	Rules(RenderWindow& windowRules) :windowRules(windowRules) {
	}

	~Rules() {}

	void setRules(Texture& rules, Sprite& rulesText, Text& Title);

	void DrawRules();
};