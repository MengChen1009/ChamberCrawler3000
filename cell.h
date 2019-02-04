#ifndef __CELL_H__
#define __CELL_H__
#include "textdisplay.h"
#include <memory>
class TextDisplay;

class Cell{
	bool occupied;
	bool EnemyMove;
	bool check;
	int r, c;
	char object;
	char prev;
	std::vector<TextDisplay*> observer;
  
public:
	Cell(); 
	bool getState() const;
	bool getCheck() const;
	bool getEnemyMove() const;
	int getRow();
	int getCol();
	char getObject() const;
	char getPrev() const;
	void setCoords(int row, int col);
	void setOccupied(bool state);
	void setObject(char obj);
	void setPrev(char p);
	void setEnemyMove(bool Emove);
	void setCheck(bool c);
	void attachTD(TextDisplay *td);
	void notifyTD();
};
#endif

