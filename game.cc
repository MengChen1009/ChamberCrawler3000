#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "cell.h"
#include "floor.h"
#include "game.h"
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
#include "potion.h"
#include "gold.h"

using namespace std;

Game::Game(): view{make_unique<View>()}, display{new TextDisplay}{
}

Game::~Game(){
	delete display;
}

void Game::clearGame(){
	dungeon.clear();
}

void Game::setCustom(bool c){
	custom = c;
}

TextDisplay* Game::getDisplay(){
	return display;
}

void Game::printScreen(){
	view->printCurrentFloor(display);
	view->printStatus(player);
}

void Game::createPlayer(string race){
	if (race == "s"){
                unique_ptr<Player> p1(new Shade());
                player = std::move(p1);
        }
	if (race == "d"){
                unique_ptr<Player> p1(new Drow());
                player = std::move(p1);
        }
	if (race == "t"){
                unique_ptr<Player> p1(new Troll());
                player = std::move(p1);
        }
	if (race == "v"){
                unique_ptr<Player> p1(new Vampire());
                player = std::move(p1);
        }
	if (race == "g"){
                unique_ptr<Player> p1(new Goblin());
                player = std::move(p1);
	}
}

void Game::init(string filename, string race) {
	srand(time(NULL));
	clearGame();
	cout << "Game start" << endl;
	char input;
	ifstream file(filename);
	
	if (!file){
		cout << "Invalid file" << endl;
		return;
	}
	dungeon.resize(5);
	dragon = 0;	
	createPlayer(race);

	for (int i = 0; i < 5; i++){	
		for (int j = 0; j < 25; j++){
			for (int k = 0; k < 79; k++){
				file.get(input);
				if (input == '\n'){
					k--;
					continue;	
				}
				dungeon[i].getCell(j, k)->setCoords(j,k);
				dungeon[i].getCell(j, k)->setObject(input);
                                dungeon[i].getCell(j, k)->setPrev(input);
				dungeon[i].getCell(j, k)->attachTD(display);
				if (input == '.'){
					dungeon[i].getCell(j, k)->setOccupied(false);
					dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setCheck(false);

					
				}
				else if ((input == '#') || (input == '+')){
					dungeon[i].getCell(j, k)->setOccupied(false);
					dungeon[i].getCell(j, k)->setEnemyMove(false);
					dungeon[i].getCell(j, k)->setCheck(true);

				}
				else {
					dungeon[i].getCell(j, k)->setOccupied(true);
					dungeon[i].getCell(j, k)->setEnemyMove(false);
					dungeon[i].getCell(j, k)->setCheck(true);
				}
			}
		}
		dungeon[i].setChambers(0, 3, 3);
        	dungeon[i].setChambers(1, 3, 39);
        	dungeon[i].setChambers(2, 10, 38);
        	dungeon[i].setChambers(3, 15, 4);
        	dungeon[i].setChambers(4, 19, 37);
		dungeon[i].setChamberSize(dungeon[i].getChamber(0).size(),
			dungeon[i].getChamber(1).size(),
			dungeon[i].getChamber(2).size(),
			dungeon[i].getChamber(3).size(),
			dungeon[i].getChamber(4).size());
	}
	currentFloor = dungeon.begin();
	(*currentFloor).floorNotifyTD();
	generatePlayer();
	generateStair();
	for (int p = 0; p < 10; p++){
		(*currentFloor).attachPotion(generatePotion());
	}
	for (int e = 0; e < 20; e++){
		(*currentFloor).attachNPC(generateNPC());
	}
	for (int g = 0; g < 10; g++){
		(*currentFloor).attachGold(generateGold());
	}	
	(*currentFloor).floorNotifyTD();
	cout << endl;
	cout << endl;	
	cout << "First floor" << endl;
	view->printCurrentFloor(display);
	view->printStatus(player);
	view->printAction("Action: Player character has spawned.");
}

void Game::initfile(string filename, string race) {
	clearGame();
        cout << "Game start" << endl;
        char input;
        ifstream file(filename);
        if (!file){
                cout << "Invalid file" << endl;
                return;
        }
        dungeon.resize(5);
	
	createPlayer(race);

        for (int i = 0; i < 5; i++){
                for (int j = 0; j < 25; j++){
                        for (int k = 0; k < 79; k++){
                                file.get(input);
                                if (input == '\n'){
                                        k--;
                                        continue;
                                }
                                dungeon[i].getCell(j, k)->setCoords(j,k);
                                dungeon[i].getCell(j, k)->setObject(input);
				dungeon[i].getCell(j, k)->attachTD(display);
                                if (input == '.'){
                                        dungeon[i].getCell(j, k)->setOccupied(false);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');

                                }
                                else if ((input == '#') || (input == '\\') || (input == '+')){
                                        dungeon[i].getCell(j, k)->setOccupied(false);
                                        dungeon[i].getCell(j, k)->setEnemyMove(false);
					dungeon[i].getCell(j, k)->setPrev(input);
                                }
				else if (input == '@'){
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
					dungeon[i].setStart(j, k);
                                }
				else if (input == '0'){
					dungeon[i].attachPotion(createPotion('0', j, k));
					dungeon[i].getCell(j, k)->setObject('P');
					dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
				}
				else if (input == '1'){
					dungeon[i].attachPotion(createPotion('1', j, k));
                                        dungeon[i].getCell(j, k)->setObject('P');
					dungeon[i].getCell(j, k)->setOccupied(true);
					dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == '2'){
					dungeon[i].attachPotion(createPotion('2', j, k));
                                        dungeon[i].getCell(j, k)->setObject('P');
					dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == '3'){
					dungeon[i].attachPotion(createPotion('3', j, k));
                                        dungeon[i].getCell(j, k)->setObject('P');
                                	dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
				}
				else if (input == '4'){
					dungeon[i].attachPotion(createPotion('4', j, k));
                                        dungeon[i].getCell(j, k)->setObject('P');
					dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == '5'){
					dungeon[i].attachPotion(createPotion('5', j, k));
                                        dungeon[i].getCell(j, k)->setObject('P');
					dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == '6'){
					dungeon[i].attachGold(createGold('6', j, k));	
                                        dungeon[i].getCell(j, k)->setObject('G');
					dungeon[i].getCell(j, k)->setOccupied(false);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == '7'){
					dungeon[i].attachGold(createGold('7', j, k));
                                        dungeon[i].getCell(j, k)->setObject('G');
					dungeon[i].getCell(j, k)->setOccupied(false);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == '8'){
					dungeon[i].attachGold(createGold('8', j, k));
                                        dungeon[i].getCell(j, k)->setObject('G');
					dungeon[i].getCell(j, k)->setOccupied(false);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == '9'){
					dungeon[i].attachGold(createGold('9', j, k));
                                        dungeon[i].getCell(j, k)->setObject('G');
					dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
					dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == 'E'){
					dungeon[i].attachNPC(createNPC('E', j, k));
					dungeon[i].getCell(j, k)->setObject('E');
                                        dungeon[i].getCell(j, k)->setOccupied(true);
					dungeon[i].getCell(j, k)->setEnemyMove(true);
                                        dungeon[i].getCell(j, k)->setPrev('.');
				}
				else if (input == 'L'){
                                        dungeon[i].attachNPC(createNPC('L', j, k));
                                        dungeon[i].getCell(j, k)->setObject('L');
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
                                        dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == 'W'){
                                        dungeon[i].attachNPC(createNPC('W', j, k));
                                        dungeon[i].getCell(j, k)->setObject('W');
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
                                        dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == 'D'){
                                        dungeon[i].attachNPC(createNPC('D', j, k));
                                        dungeon[i].getCell(j, k)->setObject('D');
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
                                        dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == 'M'){
                                        dungeon[i].attachNPC(createNPC('M', j, k));
                                        dungeon[i].getCell(j, k)->setObject('M');
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
                                        dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == 'O'){
                                        dungeon[i].attachNPC(createNPC('O', j, k));
                                        dungeon[i].getCell(j, k)->setObject('O');
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
                                        dungeon[i].getCell(j, k)->setPrev('.');
                                }
				else if (input == 'H'){
                                        dungeon[i].attachNPC(createNPC('H', j, k));
                                        dungeon[i].getCell(j, k)->setObject('H');
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(true);
                                        dungeon[i].getCell(j, k)->setPrev('.');
                                }

                                else {
                                        dungeon[i].getCell(j, k)->setOccupied(true);
                                        dungeon[i].getCell(j, k)->setEnemyMove(false);
					dungeon[i].getCell(j, k)->setPrev(input);
                                }
                        }
                }
        }
	currentfloor = 1;
        currentFloor = dungeon.begin();
	player->setPosn((*currentFloor).getStartx(),(*currentFloor).getStarty());
        (*currentFloor).floorNotifyTD();
        view->printCurrentFloor(display);
        view->printStatus(player);
	view->printAction("Action: Player character has spawned.");
}

void Game::changeFloor(){
        srand(time(NULL));
	currentfloor++;
	if (currentfloor == 6){
		endGame();
		return;
	}	
	(*currentFloor).getNPClist().clear();
        currentFloor++;
	if (!custom){
		generatePlayer();
		generateStair();
		for (int p = 0; p < 10; p++){
			(*currentFloor).attachNPC(generateNPC());
		}
		for (int i = 0; i < 20; i++){
			(*currentFloor).attachNPC(generateNPC());
		}
	}
	else {
		player->setPosn((*currentFloor).getStartx(), (*currentFloor).getStarty());
	}
	player->resetPlayer();
        (*currentFloor).floorNotifyTD();
        view->printCurrentFloor(display);
        view->printStatus(player);
}

void Game::endGame(){
	int score = player->getGold();
	if (player->getName() == "Shade"){
	  score *= 1.5;
	}
	cout << "Game Over! Your score was: " << score << endl;	
}	

void Game::generatePlayer(){
	int r = rand() % 5;	
	spawn = r;
	while (true){
		int size = (*currentFloor).getRandSize(r);
		int cell = rand() % size;
		int x = (*currentFloor).getChamber(r)[cell]->getRow();
                int y = (*currentFloor).getChamber(r)[cell]->getCol();
		if ((!(*currentFloor).getCell(x, y)->getState())){
			player->setPosn(x, y);
			(*currentFloor).getCell(x, y)->setObject('@');
			(*currentFloor).getCell(x, y)->notifyTD();
			return;
		}
		else {
			continue;
		}	
	}
}	

void Game::generateStair(){
	int r;
	while (true){
		r = rand() % 5;
		if (r != spawn){
			break;
		}
	}
        while (true){
                int size = (*currentFloor).getRandSize(r);
                int cell = rand() % size;
                int x = (*currentFloor).getChamber(r)[cell]->getRow();
                int y = (*currentFloor).getChamber(r)[cell]->getCol();
                if ((!(*currentFloor).getCell(x, y)->getState())){
                        (*currentFloor).getCell(x, y)->setObject('\\');
			(*currentFloor).getCell(x, y)->setOccupied(false);
			(*currentFloor).getCell(x, y)->setEnemyMove(false);
                        (*currentFloor).getCell(x, y)->notifyTD();
                        return;
                }
                else {
                        continue;
                }
        }
}
 
bool Game::movePlayer(int x, int y){
	int pRow = player->getRow();
	int pCol = player->getCol();
	int mRow = pRow + x;
	int mCol = pCol + y;	
	if ((*currentFloor).getCell(mRow, mCol)->getState()){
		view->printAction("Cannot move there!");
		return false;
	}
	else if (((*currentFloor).getCell(mRow, mCol)->getObject())
			== '\\'){
		changeFloor();
		return true;
	}
	else {
		if ((*currentFloor).getCell(mRow, mCol)->getObject() == 'G'){
			int g = (*currentFloor).getGoldnum();
			for (int i = 0; i < g; i++){
				if ((*currentFloor).getGold(i)->getUsed()){
					continue;
				}
				else if (((*currentFloor).getGold(i)->getRow() == mRow)
                            	  && ((*currentFloor).getGold(i)->getCol() == mCol)){
					(*currentFloor).getGold(i)->applyEffect(player);
					(*currentFloor).getGold(i)->setUsed();
				}
			}
		}
		(*currentFloor).getCell(pRow, pCol)->setOccupied(false);
		(*currentFloor).getCell(pRow, pCol)->setObject(
			(*currentFloor).getCell(pRow, pCol)->getPrev());
		(*currentFloor).getCell(pRow, pCol)->notifyTD();
		player->move(x, y);
		if (player->getName() == "Troll"){
			player->setHP(5);
		}
		(*currentFloor).getCell(mRow, mCol)->setOccupied(true);
		(*currentFloor).getCell(mRow, mCol)->setObject('@');
		(*currentFloor).getCell(mRow, mCol)->notifyTD();
		view->printAction("Player moved!");
		return true;
	}
}

bool Game::playerAttack(int x, int y){
  srand(time(NULL));
  int pRow = player->getRow();
  int pCol = player->getCol();
  int aRow = pRow + x;
  int aCol = pCol + y;
  if (((*currentFloor).getCell(aRow, aCol)->getObject() == 'H') ||
    ((*currentFloor).getCell(aRow, aCol)->getObject() == 'L') ||
    ((*currentFloor).getCell(aRow, aCol)->getObject() == 'O') ||
    ((*currentFloor).getCell(aRow, aCol)->getObject() == 'M') ||
    ((*currentFloor).getCell(aRow, aCol)->getObject() == 'D') ||
    ((*currentFloor).getCell(aRow, aCol)->getObject() == 'W') ||
    ((*currentFloor).getCell(aRow, aCol)->getObject() == 'E')){
      int e = (*currentFloor).getNPCnum();
      for (int i = 0; i < e; i++){
        if (((*currentFloor).getNPC(i)->getRow() == aRow)
           && ((*currentFloor).getNPC(i)->getCol() == aCol)){
	  cout << "NPC: " << (*currentFloor).getNPC(i)->getHP() << endl;
	  player->PCattacksNPC(*((*currentFloor).getNPC(i)), rand() % 2);
	    if ((*currentFloor).getNPC(i)->getHP() == 0){
	      (*currentFloor).getNPC(i)->setDead();
	      (*currentFloor).getCell(aRow, aCol)->setObject('.');
	      (*currentFloor).getCell(aRow, aCol)->setOccupied(false);
	      (*currentFloor).getCell(aRow, aCol)->notifyTD();
	      if (player->getName() == "Goblin"){
	        player->increaseGold(5);
	      }
	      if (((*currentFloor).getNPC(i)->getObject() == 'M') ||
		  ((*currentFloor).getNPC(i)->getObject() == 'H')){
		(*currentFloor).attachGold(createGold('8', aRow, aCol));
                (*currentFloor).getCell(aRow, aCol)->setObject('G');
                (*currentFloor).getCell(aRow, aCol)->setOccupied(false);
		(*currentFloor).getCell(aRow, aCol)->notifyTD();
	      }
	      if ((*currentFloor).getNPC(i)->getObject() == 'D'){
	        int gx = (*currentFloor).getNPC(i)->getGoldx();
 		int gy = (*currentFloor).getNPC(i)->getGoldy();
		(*currentFloor).getCell(gx, gy)->setOccupied(false);
              }
	      else {
	        int x = rand() % 2;
                if (x == 0){
		  player->increaseGold(1);
		}
                else {
		  player->increaseGold(2);
		}
	      }
	    }
	    cout << "AFTER: " << (*currentFloor).getNPC(i)->getHP() << endl;
	    return true;
	  }
	  else continue;	
	}	
      }
  else {
    return false;
  }
}

bool Game::playerUse(int x, int y){
	cout << "check" << endl;
	int pRow = player->getRow();
        int pCol = player->getCol();
        int uRow = pRow + x;
        int uCol = pCol + y;
	if ((*currentFloor).getCell(uRow, uCol)->getObject() == 'P'){
		cout << "found potion" << endl;	
		int p = (*currentFloor).potionNum();
                for (int i = 0; i < p; i++){
			if ((*currentFloor).getPotion(i)->getUsed()){
				continue;
			}
                        else if (((*currentFloor).getPotion(i)->getRow() == uRow)
                            && ((*currentFloor).getPotion(i)->getCol() == uCol)){
                         	cout << "Used a " 
				<< (*currentFloor).getPotion(i)->getName() << endl;
				(*currentFloor).getPotion(i)->applyEffect(player);
				(*currentFloor).getPotion(i)->setUsed();
				(*currentFloor).getCell(uRow, uCol)->setObject('.');
                                (*currentFloor).getCell(uRow, uCol)->setOccupied(false);
                                (*currentFloor).getCell(uRow, uCol)->notifyTD();
				if (player->getName() == "Troll"){
					player->setHP(5);
				}
				return true;
			}
			else continue;
		}
	}
	else {
		return false;
	}	
}

void Game::moveEnemies(){
	srand(time(NULL));
	int e = (*currentFloor).getNPCnum();
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 79; j++){
		 	if (((*currentFloor).getCell(i, j)->getObject() == 'H')
				|| ((*currentFloor).getCell(i, j)->getObject() == 'E')
				|| ((*currentFloor).getCell(i, j)->getObject() == 'W')
				|| ((*currentFloor).getCell(i, j)->getObject() == 'L')
				|| ((*currentFloor).getCell(i, j)->getObject() == 'M')
				|| ((*currentFloor).getCell(i, j)->getObject() == 'O')){ 
				for (int k = 0; k < e; k++){
					//find enemy on stack of enemies
					int eRow = (*currentFloor).getNPC(k)->getRow();
					int eCol = (*currentFloor).getNPC(k)->getCol();
					if ((*currentFloor).getNPC(k)->getMoved() || 
						(*currentFloor).getNPC(k)->Dead()){
						continue;
					}
					if ((eRow == i) && (eCol == j)){
						if (NPCradiusCheck(eRow, eCol)){
							(*currentFloor).getNPC(k)->NPCattacksPC(player, rand() % 2);
							(*currentFloor).getNPC(k)->setMoved(true);
							if (player->getHP() == 0){
								endGame();
								return;
							}
							break;
						}
						else {
							while (true){
								int x = rand() % 3 - 1;
								int y = rand() % 3 - 1;
								while ((x == 0) && (y == 0)){
									x = rand() % 3 - 1;
									y = rand() % 3 - 1;
								}   
								if ((!(*currentFloor).getCell((x + eRow), (y + eCol))->getState())
									&& ((*currentFloor).getCell((x + eRow), (y + eCol))->getEnemyMove())){
									(*currentFloor).getCell(eRow, eCol)->setOccupied(false);
									(*currentFloor).getCell(eRow, eCol)->setObject(
									(*currentFloor).getCell(eRow, eCol)->getPrev());
									(*currentFloor).getCell(eRow, eCol)->notifyTD();
									(*currentFloor).getNPC(k)->move(x, y);
									(*currentFloor).getCell((x + eRow), (y + eCol))->setOccupied(true);
									(*currentFloor).getCell((x + eRow), (y + eCol))->setObject(
									(*currentFloor).getNPC(k)->getObject());
									(*currentFloor).getNPC(k)->setMoved(true);
									(*currentFloor).getCell((x + eRow), (y + eCol))->notifyTD();
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	e = (*currentFloor).getNPCnum();
	for (int r = 0; r < e; r++){
		(*currentFloor).getNPC(r)->setMoved(false);
	}
	view->printCurrentFloor(display);
	view->printStatus(player);
	view->printAction("Enemies moved!");
}

bool Game::NPCradiusCheck(int x, int y){
	if (((*currentFloor).getCell((x + 1), y)->getObject() == '@') ||
		((*currentFloor).getCell((x - 1), y)->getObject() == '@') ||
		((*currentFloor).getCell(x, (y + 1))->getObject() == '@') ||
		((*currentFloor).getCell(x, (y - 1))->getObject() == '@') ||
		((*currentFloor).getCell((x + 1), (y + 1))->getObject() == '@') ||
		((*currentFloor).getCell((x + 1), (y - 1))->getObject() == '@') ||
		((*currentFloor).getCell((x - 1), (y + 1))->getObject() == '@') ||
		((*currentFloor).getCell((x - 1), (y - 1))->getObject() == '@')){
			return true;
		}
	else return false;
}


NPC *Game::createNPC(char npc, int x, int y){
	NPC* tmp;
	if (npc == 'E'){
		tmp = new Elf;
		tmp->setPosn(x, y);
	}
	if (npc == 'H'){
                tmp = new Human;
                tmp->setPosn(x, y);
        }
	if (npc == 'O'){
                tmp = new Orc;
                tmp->setPosn(x, y);
        }
	if (npc == 'D'){
                tmp = new Dragon;
                tmp->setPosn(x, y);
        }
	if (npc == 'M'){
                tmp = new Merchant;
                tmp->setPosn(x, y);
        }
	if (npc == 'L'){
                tmp = new Halfling;
                tmp->setPosn(x, y);
        }
	if (npc == 'W'){
                tmp = new Dwarf;
                tmp->setPosn(x, y);
        }
	return tmp;
}

NPC* Game::generateNPC() {
   	int type, chamber;
    	type = rand() % 18 + 1;//represents random type of NPC
    	chamber = rand() % 5;//represents random chamber
    	NPC* tmp;

    	int size = (*currentFloor).getRandSize(chamber);
    	int cell = rand() % size;
    	int x = (*currentFloor).getChamber(chamber)[cell]->getRow();
    	int y = (*currentFloor).getChamber(chamber)[cell]->getCol();
    
	
   	if(type >= 1 && type <= 4 ) {
     	  	tmp = new Human;
		tmp->setPosn(x, y);
		(*currentFloor).getCell(x, y)->setObject('H');
		(*currentFloor).getCell(x, y)->setOccupied(true);
	}
	if(type >= 5 && type <= 7 ) {
                tmp = new Dwarf;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('W');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type >= 8 && type <= 12 ) {
                tmp = new Halfling;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('L');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type >= 13 && type <= 14 ) {
                tmp = new Elf;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('E');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type >= 15 && type <= 16 ) {
                tmp = new Orc;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('O');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type >= 17 && type <= 18 ) {
                tmp = new Merchant;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('M');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	return tmp;
}

Potion* Game::createPotion(char p, int x, int y){
	Potion *tmp;
	if (p == '0'){
		tmp = new RH;
		tmp->setPosn(x, y);
	}
	if (p == '1'){
                tmp = new BA;
                tmp->setPosn(x, y);
        }
	if (p == '2'){
                tmp = new BD;
                tmp->setPosn(x, y);
        }
	if (p == '3'){
                tmp = new PH;
                tmp->setPosn(x, y);
        }
	if (p == '4'){
                tmp = new WA;
                tmp->setPosn(x, y);
        }
	if (p == '5'){
                tmp = new WD;
                tmp->setPosn(x, y);
        }
	return tmp;	
}	

Potion* Game::generatePotion(){
	int type, chamber;
        type = rand() % 6;//represents random type of NPC
        chamber = rand() % 5;//represents random chamber
        Potion* tmp;

        int size = (*currentFloor).getRandSize(chamber);
        int cell = rand() % size;
        int x = (*currentFloor).getChamber(chamber)[cell]->getRow();
        int y = (*currentFloor).getChamber(chamber)[cell]->getCol();

	if(type == 0){
                tmp = new BA;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('P');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type == 1){
                tmp = new WA;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('P');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type == 2){
                tmp = new BD;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('P');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type == 3){
                tmp = new WD;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('P');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type == 4){
                tmp = new RH;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('P');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	if(type == 5){
                tmp = new PH;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('P');
                (*currentFloor).getCell(x, y)->setOccupied(true);
        }
	return tmp;
}


Gold *Game::createGold(char g, int x, int y){
        Gold* tmp;
        if (g == '6'){
                tmp = new NGold;
                tmp->setPosn(x, y);
        }
        if (g == '7'){
                tmp = new SGold;
                tmp->setPosn(x, y);
        }
        if (g == '8'){
                tmp = new MGold;
                tmp->setPosn(x, y);
        }
        if (g == '9'){
                tmp = new DGold;
                tmp->setPosn(x, y);
        }
        return tmp;
}


Gold* Game::generateGold(){
        int type, chamber;
        type = rand() % 8;//represents random type of NPC
        chamber = rand() % 5;//represents random chamber
        Gold* tmp;

        int size = (*currentFloor).getRandSize(chamber);
        int cell = rand() % size;
        int x = (*currentFloor).getChamber(chamber)[cell]->getRow();
        int y = (*currentFloor).getChamber(chamber)[cell]->getCol();

        if((type >= 0) && (type <= 4)){
                tmp = new NGold;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('G');
                (*currentFloor).getCell(x, y)->setOccupied(false);
        }
        if((type >= 5) && (type <= 6)){
                tmp = new SGold;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('G');
                (*currentFloor).getCell(x, y)->setOccupied(false);
        }
        if(type == 7){
                tmp = new DGold;
                tmp->setPosn(x, y);
                (*currentFloor).getCell(x, y)->setObject('G');
                (*currentFloor).getCell(x, y)->setOccupied(true);
		int dx = rand() % 3 - 1;
		int dy = rand() % 3 - 1;
		while (((dx == 0) && (dy == 0))
			|| (*currentFloor).getCell((dx + x),(dy + y))->getState()){
			dx = rand() % 3 - 1;
			dy = rand() % 3 - 1;
		}
		int dRow = x + dx;
		int dCol = y + dy;
		NPC *dtmp = createNPC('D', dRow, dCol);
		dtmp->setGoldxy(x, y);
		(*currentFloor).attachNPC(dtmp);
		(*currentFloor).getCell(dRow, dCol)->setOccupied(true);
		(*currentFloor).getCell(dRow, dCol)->setObject('D');
		//tmp->setDxy(dRow, dCol);
        }
        return tmp;
}


