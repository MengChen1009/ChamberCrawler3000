#include "potion.h"

using namespace std;

Potion::Potion(string name, char n):
	Object{n}, name{name}, used{false}{}

void Potion::setPosn(int x, int y){
	row = x;
	col = y;
}

int Potion::getRow(){
	return row;
}

int Potion::getCol(){
	return col;
}

string Potion::getName(){
	return name;
}

void Potion::setUsed(){
	used = true;
}

bool Potion::getUsed(){
	return used;
}
