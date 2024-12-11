#pra#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Rules {
	int rulesX = 60;
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
	RenderWindow& window;



public:
	Rules(RenderWindow& window) :window(window) {
	}

	~Rules() {}

	void setRules(Texture& rules, Sprite& rulesText, Text& Title) {

		if (!rules.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/images/rules.png")) {
			throw "Невозможно открыть изображение!";
		};
		rulesText.setTexture(rules);
		rulesText.setPosition(rulesX, rulesY);

		if (!font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf")) {
			throw "Невозможно найти шрифт!";
		};

		Title.setFont(font);
		Title.setCharacterSize(size);
		Title.setString(L"САПЁР!");
		Title.setPosition(titleX, titleY);
		Title.setFillColor(color);
	}

	void DrawRules() {


		setRules(rules, rulesText, Title);

		while (window.isOpen()) {
			Event event_play;
			while (window.pollEvent(event_play))
			{
				if (event_play.type == Event::Closed) window.close();

			}
			window.clear(clear);
			window.draw(Title);
			window.draw(rulesText);
			window.display();
		}
	}


};