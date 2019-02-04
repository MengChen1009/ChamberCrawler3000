#include <memory>
#include "view.h"
#include "game.h"
#include "cell.h"
#include "floor.h"
#include "textdisplay.h"
#include "player.h"
using namespace std;

View::View(){}

void View::printCurrentFloor(TextDisplay *display){
	display->printDisplay();
}

void View::printStatus(unique_ptr<Player> const &player){
	cout << "Race: " << player->getName() 
		<< " Gold: " << player->getGold() << endl;
        cout << "HP: " << player->getHP() << endl;
        cout << "Atk: " << player->getATK() << endl;
        cout << "Def: " << player->getDEF() << endl;
}

void View::printAction(string action){
	cout << action << endl;
}

void View::printPosition(unique_ptr<Player> const &player){
	cout << player->getRow() << endl;
	cout << player->getCol() << endl;
}	
