#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class OptionDraw {
private:
	Font font;
public:

	void setText(String way, Text& text, int x, int y, String string, int sizeText, int r, int g, int b);

	void setRectangle(RectangleShape& shape, int x, int y, int r, int g, int b);
};