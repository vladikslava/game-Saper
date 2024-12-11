#define _CRT_SECURITYCRITICAL_ATTRIBUTE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale>
#include <cstring>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "OptionDraw.h"
#include "GameMenu.h"
#include "ChooseTypeMenu.h"
#include "Rules.h"

using namespace sf;

int main()
{
	setlocale(LC_ALL, "rus");
	Texture square;
	square.loadFromFile("C:/Users/79089/OneDrive/������� ����/�����.��/�����.��/images/�������� ����������.jpg");
	Sprite gameField(square);

	RenderWindow window(VideoMode(700, 800), L"����!");

	OptionDraw option;

	//�������� ����
	Text Title;
	option.setText("C:/Users/79089/OneDrive/������� ����/�����.��/�����.��/Fonts/Sonic 1 Title Screen Filled.ttf",
		Title, 150, 100, L"��Ϩ�!", 80, 0, 0, 0);


	//�������� ������� ����
	String menuText[]{ L"������ ����",L"������� ����",L"�����" };
	GameMenu menu(window, 350, 200, 3, menuText, 30, 45);
	menu.setPositionCentre();

	//�������� ������� ����
	RectangleShape backRectangle(Vector2f(600, 700));
	option.setRectangle(backRectangle, 50, 50, 184, 177, 162);
	Color backColor = Color(166, 166, 166);

	//������ ������ �������� ������ ���������
	String chooseType[]{ L"������ �����",L"������� �����",L"������� �����" };
	ChooseType chooseMenu(window, 350, 200, 3, chooseType, 30, 45);
	chooseMenu.setPositionCentre();

	int flagType = -1;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}
				if ((event.key.code == Keyboard::W) || (event.key.code == Keyboard::Up)) {
					menu.MoveUp();
				}
				if ((event.key.code == Keyboard::S) || (event.key.code == Keyboard::Down)) {
					menu.MoveDown();
				}
				if (event.key.code == Keyboard::Enter) {
					switch (menu.getNumberMenu()) {
					//����� ������ ������
					case (0): {
						flagType = chooseMenu.DrawChooseType();
					}break;

					//����� �������
					case(1): {
						RenderWindow windowRules(VideoMode(700, 800), L"������� ���� � ����");
						windowRules.setMouseCursorVisible(false);
						Rules rules(windowRules);
						rules.DrawRules();
					}break;

					//����� ����� �� ����
					case(2):window.close(); break;
					}
					//�������� �������� ������
					if (flagType > -1) {
						Game gameLevel(flagType);
						gameLevel.DrawLevel();
					}
				}
			}

			window.clear(backColor);
			window.draw(backRectangle);
			window.draw(Title);
			menu.DrawMenu();
			window.display();
		}
	}
}