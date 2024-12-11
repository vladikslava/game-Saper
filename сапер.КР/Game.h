#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <cstring>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Game {
protected:
	const int BOOM = 5;
	int** field;
	int** hideField;
	int sizeField = 0;
	int quantityBooms = 0;
	double sizeSquare = 38.5;
	int points = 0;
	int levelType = 0;
	Texture square;
	Text Title;
	Text exit;
	Font font;
	RenderWindow window;

public:
	enum LevelType { EASY = 0, MIDDLE = 1, HARD = 2 };
	LevelType type;
	enum FieldSize { EASYSIZE = 6, MIDDLESIZE = 10, HARDSIZE = 15 };
	FieldSize size;
	enum BoomsQuantity { EASYBOOMS = 7, MIDDLEBOOMS = 11, HARDBOOMS = 16 };

	Game(int levelType);

	void run();

	void setBack(RenderWindow& window, Text& Title, Text& exit);

	void DrawLevel();

	void DrawHide();

	void gameOver();

	void Win();

	int SizeField();

	void SetSizeField();

	int getSizeField();

	int QuantityBooms();

	void SetQuantityBooms();

	int getQuantityBooms();

	void CreateField();

	void SetField();

	void CreateHideField();

	void SetHideField();
	
	void SetBooms();

	void SetSignes();


	int getField(int i, int j);
	
	~Game();

};

