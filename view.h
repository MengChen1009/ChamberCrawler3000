#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <vector>
#include <memory>
#include "floor.h"
#include "cell.h"
#include "game.h"
#include "textdisplay.h"
#include "player.h"
class Game;
class Player;
class TextDisplay;

class View{

public:
	View();
	void printCurrentFloor(TextDisplay *current);
	void printStatus(std::unique_ptr<Player> const &player);
	void printAction(std::string action);
	void printPosition(std::unique_ptr<Player> const &player);
};

#endif

