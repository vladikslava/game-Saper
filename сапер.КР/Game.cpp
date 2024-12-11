#include "Game.h"

Game::Game(int levelType) {
	this->levelType = levelType;
	switch (levelType) {
	case(0):type = EASY; break;
	case(1):type = MIDDLE; break;
	case(2):type = HARD; break;
	}
}

void Game::run() {

	SetSizeField();
	SetQuantityBooms();
	CreateField();
	SetField();
	CreateHideField();
	SetHideField();
	SetBooms();
	SetSignes();
}

void Game::setBack(RenderWindow& window, Text& Title, Text& exit) {

	if (!font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf")) {
		throw "Шрифт не найден!";
	}
	font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf");

	Title.setFont(font);
	Title.setCharacterSize(80);
	Title.setFillColor(Color(0, 0, 0));
	Title.setString(L"САПЁР!");
	Title.setPosition(150, 80);

	exit.setFont(font);
	exit.setCharacterSize(15);
	exit.setFillColor(Color(0, 0, 0));
	exit.setString(L"Нажмите Esc, чтобы закончить игру");
	exit.setPosition(120, 760);

}

void Game::DrawLevel() {
	RenderWindow window(VideoMode(700, 800), L"Сапёр!");
	//задник
	RectangleShape backRectangle(Vector2f(600, 720));
	backRectangle.setPosition(50, 50);
	backRectangle.setFillColor(Color(184, 177, 162));

	Text Title;
	Text exit;
	setBack(window, Title, exit);

	//текстура
	Texture square;
	if (!square.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/images/текстуры нормальные.jpg")) {
		throw "Невозможно открыть изображение!";
	}
	Sprite gameField(square);

	if (!font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf")) {
		throw "Шрифт не найден!";
	}
	font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf");

	run();

	Clock clock;
	Clock gameTimeClock;
	int gameTime = 0;
	int minutes = 0;
	Text text;

	int winpoint = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();

		gameTime = gameTimeClock.getElapsedTime().asSeconds();
		clock.restart();

		window.clear(Color(166, 166, 166));
		window.draw(backRectangle);
		window.draw(Title);
		window.draw(exit);

		if (gameTime == 60) {
			minutes++;
			gameTime = 0;
		}
		String gameTimeStringSec = to_string(gameTime);
		String gameTimeStringMin = to_string(minutes);
		text.setFont(font);
		text.setCharacterSize(20);
		text.setString(L"Время игры  0" + gameTimeStringMin + L" мин. " + gameTimeStringSec + L" сек.");
		text.setFillColor(Color::Black);
		text.setPosition(10, 15);

		window.draw(text);

		DrawHide();

		int flag = 0;
		int boom = 0;
		int nullx = (700 - (sizeField * sizeSquare)) / 2;
		int flagturn = 0;
		int turn = 0;

		Vector2i pos = Mouse::getPosition(window);
		int x = (pos.x - nullx) / sizeSquare;
		int y = (pos.y - 140) / sizeSquare;

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}
			}

			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Right) {
					hideField[x][y] = 7;
				}
				if (event.key.code == Mouse::Left) {
					hideField[x][y] = field[x][y];
					winpoint++;
					if (hideField[x][y] == 5) {
						boom = 1;

					}
				}
			}
		}

		for (int i = 1; i < sizeField - 1; ++i) {
			for (int j = 1; j < sizeField - 1; ++j) {
				if (boom == 1) {
					flag = -1;
					hideField[i][j] = field[i][j];
				}
				gameField.setTextureRect(IntRect(hideField[i][j] * sizeSquare, 0, sizeSquare, sizeSquare));
				gameField.setPosition((i * sizeSquare) + nullx, (j * sizeSquare) + 140);

				window.draw(gameField);
			}
		}

		if (flag == -1) {
			gameOver();
		}
		if ((winpoint == (((sizeField - 2) * (sizeField - 2) - quantityBooms)) && (flag != -1))) {
			Win();
		}

		window.display();
	}
}

void Game::DrawHide() {

	int nullx = (700 - (sizeField * sizeSquare)) / 2;
	int sizeHide = 39;
	Texture hide;
	if (!hide.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/images/текстуры нормальные.jpg")) {
		throw "Невозможно открыть изображение!";
	}
	Sprite hideSq(hide);

	for (int i = 1; i < sizeField - 1; ++i) {
		for (int j = 1; j < sizeField - 1; ++j) {

			hideSq.setTextureRect(IntRect(hideField[i][j] * sizeHide, 0, sizeHide, sizeHide));
			hideSq.setPosition((i * sizeSquare) + nullx, (j * sizeSquare) + 140);
		}
	}
}

void Game::gameOver() {
	RenderWindow window(VideoMode(550, 550), L"Вы проиграли!");
	RectangleShape end(Vector2f(530, 530));
	end.setPosition(10, 10);
	end.setFillColor(Color(0, 0, 0, 20));

	Text GameOver;
	Font font;
	if (!font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf")) {
		throw "Шрифт не найден!";
	}
	font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf");

	String GameOverStr = L"ВЫ ПРОИГРАЛИ!";

	GameOver.setFont(font);
	GameOver.setCharacterSize(30);
	GameOver.setFillColor(Color::Black);
	GameOver.setString(GameOverStr);
	GameOver.setPosition(100, 100);

	Text Close;
	String CloseStr = L"Закрыть";

	Close.setFont(font);
	Close.setCharacterSize(30);
	Close.setFillColor(Color(198, 62, 28));
	Close.setString(CloseStr);
	Close.setPosition(180, 200);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if ((event.type == Event::KeyReleased)) {
				if ((event.key.code == Keyboard::Enter)|| (event.key.code == Keyboard::Escape)) {
					window.close();
				}
			}

		}
		window.clear(Color(184, 177, 162));
		window.draw(Close);
		window.draw(end);
		window.draw(GameOver);

		window.display();
	}
}

void Game::Win() {
	RenderWindow window(VideoMode(550, 550), L"Вы победили!");
	RectangleShape end(Vector2f(530, 530));
	end.setPosition(10, 10);
	end.setFillColor(Color(0, 0, 0, 20));

	Text GameOver;
	Font font;
	if (!font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf")) {
		throw "Шрифт не найден!";
	}
	font.loadFromFile("C:/Users/79089/OneDrive/Рабочий стол/сапер.КР/сапер.КР/Fonts/Sonic 1 Title Screen Filled.ttf");

	String GameOverStr = L"ВЫ ПОБЕДИЛИ!";

	GameOver.setFont(font);
	GameOver.setCharacterSize(30);
	GameOver.setFillColor(Color::Black);
	GameOver.setString(GameOverStr);
	GameOver.setPosition(100, 100);

	Text Close;
	String CloseStr = L"Закрыть";

	Close.setFont(font);
	Close.setCharacterSize(30);
	Close.setFillColor(Color(198, 62, 28));
	Close.setString(CloseStr);
	Close.setPosition(180, 200);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyReleased) {
				if ((event.key.code == Keyboard::Enter) || (event.key.code == Keyboard::Escape)) {
					window.close();
				}
			}

		}
		window.clear(Color(184, 177, 162));
		window.draw(Close);
		window.draw(end);
		window.draw(GameOver);

		window.display();
	}
}

int Game::SizeField() {
	switch (type) {
	case(EASY): return EASYSIZE; break;
	case(MIDDLE): return MIDDLESIZE; break;
	case(HARD): return HARDSIZE; break;
	}
}

void Game::SetSizeField() {
	sizeField = SizeField() + 2;
}

int Game::getSizeField() {
	SetSizeField();
	return sizeField;
}

int Game::QuantityBooms() {
	switch (type) {
	case(EASY): return EASYBOOMS; break;
	case(MIDDLE): return MIDDLEBOOMS; break;
	case(HARD): return HARDBOOMS; break;
	}
}

void Game::SetQuantityBooms() {
	quantityBooms = QuantityBooms();
}

int Game::getQuantityBooms() {
	return quantityBooms;
}

void Game::CreateField() {
	field = new int* [sizeField];

	for (int i = 0; i < sizeField; ++i) {
		field[i] = new int[sizeField];
	}
}

void Game::SetField() {
	for (int i = 0; i < sizeField; ++i)
	{
		for (int j = 0; j < sizeField; ++j)
		{
			field[i][j] = 0;
		}
	}
}

void Game::CreateHideField() {
	hideField = new int* [sizeField];

	for (int i = 0; i < sizeField; ++i) {
		hideField[i] = new int[sizeField];
	}
}

void Game::SetHideField() {
	for (int i = 1; i < sizeField; ++i) {
		for (int j = 1; j < sizeField; ++j) {
			hideField[i][j] = 6;
		}
	}
}

void Game::SetBooms() {
	bool good = 0;
	int i = 0;
	srand(time(NULL));
	while (quantityBooms > 0) {
		int randomPlaceX = 2 + rand() % SizeField() - 1;
		int randomPlaceY = 2 + rand() % SizeField() - 1;
		if (field[randomPlaceX][randomPlaceY] == BOOM) {
			continue;
		}
		else {
			field[randomPlaceX][randomPlaceY] = BOOM;
			--quantityBooms;
		}
	}
}

void Game::SetSignes() {
	int countBooms;
	for (int i = 1; i < sizeField - 1; ++i) {
		for (int j = 1; j < sizeField - 1; ++j) {

			countBooms = 0;
			if (field[i][j] != BOOM) {
				if (field[i - 1][j] == BOOM)
					countBooms++;
				if (field[i][j - 1] == BOOM)
					countBooms++;
				if (field[i][j + 1] == BOOM)
					countBooms++;
				if (field[i + 1][j] == BOOM)
					countBooms++;

				field[i][j] = countBooms;
			}
		}
	}
}

int Game::getField(int i, int j) {
	run();
	return field[i][j];
}

Game::~Game()
{
	if (field) {
		for (int i = 0; i < sizeField; ++i) {
			delete[]field[i];
		}
		delete[] field;
	}
	if (hideField) {
		for (int i = 0; i < sizeField; ++i) {
			delete[]hideField[i];
		}
		delete[] hideField;
	}
}
