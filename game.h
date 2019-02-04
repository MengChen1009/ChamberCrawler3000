#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "cell.h"
#include "floor.h"
#include "view.h"
#include "textdisplay.h"
#include "player.h"
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "goblin.h"
#include "troll.h"
#include "npc.h"
#include "elf.h"
#include "halfling.h"
#include "dragon.h"
#include "orc.h"
#include "merchant.h"
#include "dwarf.h"
#include "human.h"
#include "item.h"
#include "potion.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"
#include "rh.h"
#include "ph.h"
#include "gold.h"
#include "sgold.h"
#include "mgold.h"
#include "ngold.h"
#include "dgold.h"

class View;

class Floor;

class TextDisplay;

class Player;

class Game {
	void clearGame();   // Clears the Game
	bool custom;	
	std::unique_ptr<View> view;
	std::vector<Floor>::iterator currentFloor;
	TextDisplay* display;
	std::vector<Floor> dungeon;
	std::unique_ptr<Player> player;
	int spawn;
	int currentfloor;
	int startx;
	int starty;
	int dragon;

public:
	Game();
	~Game();
 	void setCustom(bool c); 
	void init(std::string filename, std::string race);
	void initfile(std::string filename, std::string race);
	void createPlayer(std::string race);
	void changeFloor();
	void endGame();
	void generatePlayer();
	bool movePlayer(int x, int y);
	bool playerUse(int x, int y);
	void generateStair();
	void moveEnemies();
	void printScreen();
	bool playerAttack(int x, int y);
	void enemyAttack();
	NPC *findEnemy(int x, int y);
	Potion *createPotion(char p, int x, int y);
  	Potion *generatePotion();	
	TextDisplay* getDisplay();
	bool NPCradiusCheck(int x, int y);
	NPC *createNPC(char npc, int x, int y);
	NPC *generateNPC();
	Gold *createGold(char g, int x, int y);
	Gold *generateGold();

};

#endif

