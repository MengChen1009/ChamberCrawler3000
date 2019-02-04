#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include <memory>
#include "cell.h"
#include "npc.h"
#include "potion.h"
#include "gold.h"
class Cell;

class Floor {
	std::vector<std::vector<Cell>>floor;
	std::vector<NPC*> NPClist;
	std::vector<Potion*> potionlist;
	std::vector<Gold*> goldlist;
	std::vector<std::vector<Cell*>> chambers;
	int enemies;
	int potion;
	int gold;
	int chamber1;
	int chamber2;
	int chamber3;
	int chamber4;
	int chamber5;
	int startx;
	int starty;		
	
public:
	Floor();
	virtual ~Floor();
	Cell* getCell(int x, int y);
	std::vector<Cell*> getChamber(int c);
	std::vector<NPC*> getNPClist();
	std::vector<Gold*> getGoldlist();
	void floorNotifyTD();
	void attachNPC(NPC *enemy);
	void attachPotion(Potion *p);
	void attachGold(Gold *g);
	void setChambers(int r, int x, int y);
	void setChamberSize(int a, int b, int c, int d, int e);
	void incrementNPC();
	void decrementNPC();
	void setStart(int x, int y);
	NPC *getNPC(int e);
	Potion *getPotion(int p);
	Gold *getGold(int g);
	int getGoldnum();
	int getNPCnum();
	int potionNum();
	int getStartx();
	int getStarty();
	int sizeC1();
	int sizeC2();
	int sizeC3();
	int sizeC4();
	int sizeC5();
	int getRandSize(int r);

};
#endif

