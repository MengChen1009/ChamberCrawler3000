#include "cell.h"
#include "textdisplay.h"
using namespace std;

Cell::Cell(){}

bool Cell::getState() const{
	return occupied;
}

bool Cell::getEnemyMove() const{
	return EnemyMove;
}

bool Cell::getCheck() const{
	return check;
}

int Cell::getRow(){
	return r;
}

int Cell::getCol(){
	return c;
}	

char Cell::getObject() const{
	return object;
}

char Cell::getPrev() const{
	return prev;
}

void Cell::setCoords(int row, int col){
	r = row;
	c = col;
}

void Cell::setOccupied(bool state){
	occupied = state;
}

void Cell::setObject(char p){
	object = p;
}

void Cell::setEnemyMove(bool Emove){
	EnemyMove = Emove;
}

void Cell::attachTD(TextDisplay *td){
	observer.push_back(td);
}

void Cell::notifyTD(){
	observer[0]->notify(*this);
}

void Cell::setPrev(char obj){
	prev = obj;
}

void Cell::setCheck(bool c){
	check = c;	
}

	
