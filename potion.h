#ifndef POTION_H
#define POTION_H
#include "item.h"
#include <memory>

class Player;

class Potion: public Item{

	char Object;
	int row;
	int col;
	std::string name;
	bool used;
public:
	Potion(std::string name, char n);
	bool getUsed();
	void setPosn(int x, int y);
	void setUsed();
	int getRow();
	int getCol();
	std::string getName();
	virtual void applyEffect(std::unique_ptr<Player> const &player) = 0;
};
#endif

