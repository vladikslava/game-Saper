#include "GameMenu.h"

GameMenu::GameMenu(RenderWindow& window, int menuX, int menuY, int maxMenu, String name[], int fontSize, int menuStep)
	:window(window), menuX(menuX), menuY(menuY), fontSize(fontSize), menuStep(menuStep) {
	this->maxMenu = maxMenu;
	menuText = new Text[maxMenu];
	for (int i = 0; i < maxMenu; ++i) {
		setText(menuText[i], name[i], menuX, menuY += menuStep);
	}
	menuSelected = 0;
	menuText[menuSelected].setFillColor(menuChoseText);
}

void GameMenu::setText(Text& text, String string, int menuX, int menuY) {

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

void GameMenu::setPositionCentre() {

	float nullx = 0;
	for (int i = 0; i < maxMenu; ++i) {

		nullx = menuText[i].getLocalBounds().width / 2;
		menuText[i].setPosition(menuText[i].getPosition().x - nullx, menuText[i].getPosition().y);
	}
}

void GameMenu::MoveUp() {
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

void GameMenu::MoveDown() {
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

void GameMenu::DrawMenu() {
	for (int i = 0; i < maxMenu; ++i) {
		window.draw(menuText[i]);
	}
}

int GameMenu::getNumberMenu() {
	return menuSelected;
}

GameMenu::~GameMenu() {
	if (menuText) {
		delete[] menuText;
	}
}
