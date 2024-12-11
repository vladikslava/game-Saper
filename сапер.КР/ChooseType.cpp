#include "ChooseTypeMenu.h"

ChooseType::ChooseType(RenderWindow& window, int menuX, int menuY, int maxMenu, String name[], int fontSize, int menuStep)
	:window(window), menuX(menuX), menuY(menuY), fontSize(fontSize), menuStep(menuStep) {
	this->maxMenu = maxMenu;
	menuText = new Text[maxMenu];
	for (int i = 0; i < maxMenu; ++i) {
		setText(menuText[i], name[i], menuX, menuY += menuStep);
	}
	menuSelected = 0;
	menuText[menuSelected].setFillColor(menuChoseText);
	setText(Title, title, TitleX, TitleY);
	Title.setCharacterSize(sizeTitle);
}

ChooseType::~ChooseType() {
	if (menuText) {
		delete[] menuText;
	}
}

void ChooseType::setText(Text& text, String string, int menuX, int menuY) {

	if (!font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf")) {
		throw "Шрифт не найден!";
	}
	font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf");
	text.setFont(font);

	text.setCharacterSize(fontSize);
	text.setFillColor(menuTextColor);
	text.setString(string);
	text.setPosition(menuX, menuY);
	window.draw(text);
}

void ChooseType::setPositionCentre() {

	float nullx = 0;
	for (int i = 0; i < maxMenu; ++i) {

		nullx = menuText[i].getLocalBounds().width / 2;
		menuText[i].setPosition(menuText[i].getPosition().x - nullx, menuText[i].getPosition().y);
	}
}

void ChooseType::MoveUp() {
	--menuSelected;
	if (menuSelected >= 0) {
		menuText[menuSelected].setFillColor(menuChoseText);
		menuText[menuSelected + 1].setFillColor(menuTextColor);
	}
	else {
		menuText[0].setFillColor(menuTextColor);
		menuSelected = maxMenu - 1;
		menuText[menuSelected].setFillColor(menuChoseText);
	}
}

void ChooseType::MoveDown() {
	++menuSelected;
	if (menuSelected < maxMenu) {
		menuText[menuSelected - 1].setFillColor(menuTextColor);
		menuText[menuSelected].setFillColor(menuChoseText);
	}
	else {
		menuText[maxMenu - 1].setFillColor(menuTextColor);
		menuSelected = 0;
		menuText[menuSelected].setFillColor(menuChoseText);
	}
}

int ChooseType::DrawChooseType() {

	RectangleShape backRectangle(Vector2f(600, 700));
	backRectangle.setPosition(50, 50);
	backRectangle.setFillColor(Color(184, 177, 162));
	while (window.isOpen()) {
		Event event_play;
		while (window.pollEvent(event_play))
		{
			if (event_play.type == Event::Closed) window.close();
			if (event_play.type == Event::KeyReleased) {
				if ((event_play.key.code == Keyboard::W) || (event_play.key.code == Keyboard::Up)) {
					MoveUp();
				}
				if ((event_play.key.code == Keyboard::S) || (event_play.key.code == Keyboard::Down)) {
					MoveDown();
				}
				if (event_play.key.code == Keyboard::Enter) {
					return getNumberMenu();
				}
			}
		}
		window.clear(clear);
		window.draw(backRectangle);
		window.draw(Title);
		for (int i = 0; i < maxMenu; ++i) {
			window.draw(menuText[i]);
		}
		window.display();
	}
}

int ChooseType::getNumberMenu() {
	return menuSelected;
}
