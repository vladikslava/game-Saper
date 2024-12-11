#include "Rules.h"

void Rules::setRules(Texture& rules, Sprite& rulesText, Text& Title) {

	if (!rules.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/images/rules (2).png")) {
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

void Rules::DrawRules() {

	setRules(rules, rulesText, Title);
	RectangleShape back(Vector2f(600, 700));
	back.setPosition(50, 50);
	back.setFillColor(Color(255, 255, 255, 50));
	while (windowRules.isOpen()) {
		Event event_play;
		while (windowRules.pollEvent(event_play))
		{
			if (event_play.type == Event::Closed) windowRules.close();
			if (event_play.type == Event::KeyReleased) {
				if (event_play.key.code == Keyboard::Escape) {
					windowRules.close();
				}

			}
			windowRules.clear(clear);
			windowRules.draw(back);
			windowRules.draw(Title);
			windowRules.draw(rulesText);
			windowRules.display();
		}
	}
}
