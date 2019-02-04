#include "gold.h"

using namespace std;

Gold::Gold(string name, char n, int val):
	name{name}, Object{n}, value{val}, used{false}{}

void Gold::setPosn(int x, int y){
	row = x;
	col = y;
}

int Gold::getValue() {
	return value;
}

int Gold::getRow(){
	return row;
}

int Gold::getCol(){
	return col;
}

string Gold::getName(){
	return name;
}

void Gold::setUsed(){
	used = true;
}

bool Gold::getUsed(){
	return used;
}


void Gold::setDxy(int x, int y){
        dx = x;
        dy = y;
}

int Gold::getDx(){
        return dx;
}

int Gold::getDy(){
        return dy;
}


