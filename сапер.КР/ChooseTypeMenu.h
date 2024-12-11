#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class ChooseType {
	int menuX;
	int menuY;
	int menuStep = 50;
	int maxMenu;
	int fontSize;
	int menuSelected;
	Font font;
	Text* menuText;
	Color menuTextColor = Color(0, 0, 0);
	Color menuChoseText = Color(192, 62, 28);
	Color clear = Color(166, 166, 166);

	Text Title;
	String title = L"—¿œ®–!";
	int TitleX=150;
	int TitleY=100;
	int sizeTitle = 80;
	Color titleColor = Color(0, 0, 0);

	RenderWindow& window;

public:
	ChooseType(RenderWindow& window, int menuX, int menuY, int maxMenu, String name[], int fontSize, int menuStep);

	~ChooseType();

	void setText(Text& text, String string, int menuX, int menuY);

	void setPositionCentre();

	void MoveUp();

	void MoveDown();

	int DrawChooseType();

	int getNumberMenu();


};
