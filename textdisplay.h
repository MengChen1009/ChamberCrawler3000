#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "cell.h"
#include "floor.h"
#include "view.h"
#include "game.h"
class Cell;

class TextDisplay{
	std::vector<std::vector<char>> theDisplay;
public:
	TextDisplay();

	void notify(Cell &whoNotified);
	void printDisplay();
	void printAll(const Game &game);
	void clearDisplay();
};

#endif

