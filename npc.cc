#include "npc.h"
#include <string>
#include <memory>
#include "player.h"

using namespace std ;

// Initializes the values accordingly
NPC::NPC(string name, char n, int HP, int ATK, int DEF) : 
	NPC_HP{HP} ,
        NPC_ATK{ATK} ,
        NPC_DEF{DEF} ,
	Object{n},
	name{name}{}

bool NPC::merchantHostile = false;

void NPC::setPosn(int x, int y){
        NPC_row = x;
        NPC_col = y;
}

void NPC::setHostile(){
	merchantHostile = true;
}

bool NPC::getHostile(){
	return merchantHostile;
}

int NPC::getHP(){
        return NPC_HP;
}

int NPC::getATK(){
        return NPC_ATK;
}

int NPC::getDEF(){
        return NPC_DEF;
}

int NPC::getRow(){
        return NPC_row;
}

int NPC::getCol(){
        return NPC_col;
}

char NPC::getObject(){
	return Object;
}

bool NPC::getMoved(){
	return moved;
}

bool NPC::Dead(){
	return dead;
}

void NPC::setDead(){
	dead = true;
}

void NPC::setMoved(bool m){
	moved = m;	
}

void NPC::move(int x, int y){
        NPC_row += x;
        NPC_col += y;
}

void NPC::setHP(int a){
	if ((NPC_HP + a) < 0){
		NPC_HP = 0;
	}
	else {
		NPC_HP += a;
	}	
}

void NPC::NPCattacksPC(unique_ptr<Player> const &player, int random ) {
  if ( random ) {
    player->attackedbyNPC(*this);
  }
  else { cout << "NPC's Attack was Unsuccessfull!" << endl ; }
}


void NPC::setGoldxy(int x, int y){
        goldx = x;
        goldy = y;
}

int NPC::getGoldx(){
        return goldx;
}

int NPC::getGoldy(){
        return goldy;
}
