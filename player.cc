# include "player.h"
# include <climits>

using namespace std ;

// Initializes the values accordingly
Player::Player(std::string name, int HP, int ATK, int DEF,
	const int MAXHP, const int defaultATK, const int defaultDEF) :
 	PC_HP{HP},  PC_ATK{ATK}, PC_DEF{DEF}, gold{0}, Object{'@'}, name{name}, 
	modifier{1.0}, base_ATK{defaultATK},
	base_DEF{defaultDEF}, PC_MAXHP{MAXHP}{} 

void Player::setPosn(int x, int y){
	PC_row = x;
	PC_col = y;
}

int Player::getGold(){
	return gold;
}

float Player::getMod(){
	return modifier;
}

string Player::getName(){
	return name; 
}

int Player::getHP(){
	return PC_HP;
}

int Player::getATK(){
        return PC_ATK;
}

int Player::getDEF(){
        return PC_DEF;
}

int Player::getRow(){
        return PC_row;
}

int Player::getCol(){
        return PC_col;
}

void Player::move(int x, int y){
	PC_row += x;
	PC_col += y;
}

void Player::resetPlayer(){
	PC_ATK = base_ATK;
	PC_DEF = base_DEF;
}

void Player::increaseGold(int g){
	gold += g;
}

void Player::setATK(int a){
	if ((PC_ATK + a) <= 0){
		PC_ATK = 0;
	}
	else if ((max - PC_ATK) <= a){
		PC_ATK = max;
	}
	else {
		PC_ATK += a;
	}
}		


void Player::setDEF(int a){
        if ((PC_DEF + a) <= 0){
                PC_DEF = 0;
        }
        else if ((max - PC_DEF) <= a){
                PC_DEF = max;
        }
        else {
                PC_DEF += a;
        }
}


void Player::setHP(int a){
	if ((a + PC_HP) >= PC_MAXHP){
		PC_HP = PC_MAXHP;
	}
	else if ((a + PC_HP) <= 0){
		PC_HP = 0;
	}
	else {
		PC_HP += a;
	}
}


