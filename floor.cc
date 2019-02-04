#include "floor.h"
#include "cell.h"

using namespace std;

Floor::Floor(){
	floor.resize(25, vector<Cell>(79, Cell()));
	chambers.resize(5);
	enemies = 0;
	potion = 0;
}

Floor::~Floor(){
	for (int i = 0; i < NPClist.size(); i++){
		delete NPClist[i];	
	}
	for (int j = 0; j < potionlist.size(); j++){
                delete potionlist[j];
        }	
	for (int k = 0; k < goldlist.size(); k++){
                delete goldlist[k];
        }
	NPClist.clear();
	potionlist.clear();
	goldlist.clear();
}

Cell* Floor::getCell(int x, int y){
	return &floor[x][y];
}

vector<Cell*> Floor::getChamber(int c){
	return chambers[c];
}

NPC *Floor::getNPC(int e){
	return NPClist[e]; 

}

Gold *Floor::getGold(int g){
        return goldlist[g];

}

Potion *Floor::getPotion(int p){
	return potionlist[p];
}

vector<NPC*> Floor::getNPClist(){
	return NPClist;
}

vector<Gold*> Floor::getGoldlist(){
        return goldlist;
}


int Floor::getStartx(){
	return startx;
} 

int Floor::getStarty(){
	return starty;
}

void Floor::setStart(int x, int y){
	startx = x;
	starty = y;
}

void Floor::floorNotifyTD(){
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 79; j++){
			floor[i][j].notifyTD();	
		}
	}	
}

void Floor::attachNPC(NPC *enemy){
	NPClist.push_back(enemy);
	enemies++;
}

void Floor::attachPotion(Potion *p){
	potionlist.push_back(p);
	potion++;		
}

void Floor::attachGold(Gold *g){
	goldlist.push_back(g);
	gold++;
}

void Floor::setChambers(int r, int x, int y){
	if (floor[x][y].getCheck()){
		return;
	}
	else if (floor[x][y].getPrev() == '.'){
		floor[x][y].setCheck(true);
		chambers[r].push_back(getCell(x, y));
		setChambers(r, (x + 1), y);
		setChambers(r, (x - 1), y);
		setChambers(r, x, (y + 1));
		setChambers(r, x, (y - 1));
	}
}

void Floor::setChamberSize(int a, int b, int c, int d, int e){
	chamber1 = a;
	chamber2 = b;
	chamber3 = c;
	chamber4 = d;
	chamber5 = e;
}

void Floor::incrementNPC(){
	enemies++;
}

void Floor::decrementNPC(){
        enemies--;
}

int Floor::getNPCnum(){
        return enemies;
}

int Floor::potionNum(){
	return potion;
}

int Floor::getGoldnum(){
	return gold;
}

int Floor::sizeC1(){
	return chamber1;
}

int Floor::sizeC2(){
        return chamber2;
}

int Floor::sizeC3(){
        return chamber3;
}

int Floor::sizeC4(){
        return chamber4;
}

int Floor::sizeC5(){
        return chamber5;
}

int Floor::getRandSize(int r){
	if (r == 0){
		return chamber1;
	}
	if (r == 1){
                return chamber2;
        }
	if (r == 2){
                return chamber3;
        }
	if (r == 3){
                return chamber4;
        }
	else {
                return chamber5;
        }
}


