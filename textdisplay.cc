#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "floor.h"
#include "view.h"
#include "game.h"
using namespace std;

TextDisplay::TextDisplay(){
	theDisplay.resize(25, vector<char>(79, ' '));
}

void TextDisplay::notify(Cell &whoNotified) {
	char info = whoNotified.getObject();
	int x = whoNotified.getRow();
	int y = whoNotified.getCol();
	theDisplay[x][y] = info;
}


void TextDisplay::printDisplay(){
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 79; j++){
			cout << theDisplay[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void TextDisplay::printAll(const Game &game){
	return;	
}

void TextDisplay::clearDisplay(){
	theDisplay.clear();
	theDisplay.resize(25, vector<char>(79, ' '));
}	
