#ifndef controller_h
#define controller_h
#include <iostream>
#include <memory>
#include "game.h"
#include "view.h"

class Game;

class Controller {

private:
	std::string filename;
	bool IsCustomedMap;
	std::unique_ptr<Game> g;
public:
	Controller(std::string filename, bool IsCustomedMap);
	void PrintRaceInfo();
	void command();
	void readfile();
};

#endif
 
