#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameMenu {
	int menuX;
	int menuY;
	int menuStep=50;
	int maxMenu;
	int fontSize;
	int menuSelected;
	Font font;
	Text* menuText;
	Color menuTextColor = Color(0, 0, 0);
	Color menuChoseText= Color(192, 62, 28);
	RenderWindow& window;

public:
	GameMenu(RenderWindow& window, int menuX, int menuY, int maxMenu, String name[], int fontSize, int menuStep);

	void setText(Text& text, String string, int menuX, int menuY);

	void setPositionCentre();

	void MoveUp();

	void MoveDown();

	void DrawMenu();
	
	int getNumberMenu();

	~GameMenu();
	
};
