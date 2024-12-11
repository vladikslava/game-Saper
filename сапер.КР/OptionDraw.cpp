#include "OptionDraw.h"

void OptionDraw::setText(String way, Text& text, int x, int y, String string, int sizeText, int r, int g, int b) {

	if (!font.loadFromFile(way)) {
		throw "Ўрифт не найден!";
	}
	font.loadFromFile(way);
	text.setFont(font);

	text.setCharacterSize(sizeText);
	text.setPosition(x, y);
	text.setString(string);
	text.setFillColor(Color(r, g, b));
}

void OptionDraw::setRectangle(RectangleShape& shape, int x, int y, int r, int g, int b) {
	shape.setPosition(x, y);
	shape.setFillColor(Color(r, g, b));
}
