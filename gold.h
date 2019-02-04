#ifndef GOLD_H
#define GOLD_H

# include "item.h"
# include <memory>

class Player;

class Gold: public Item{

protected:
	std::string name;
        char Object;
	int value;
        int row;
        int col;
	bool used;

	int dx;
	int dy;

public:
	Gold(std::string name, char n, int val);
	bool getUsed();
	int getValue();
	void setPosn(int x, int y);
	void setUsed();
	int getRow();
	int getCol();
	std::string getName();
	virtual void applyEffect(std::unique_ptr<Player> const &player) = 0;
	void setDxy(int x, int y);
  	int getDx();
  	int getDy();

} ;
#endif

