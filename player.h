# ifndef _PLAYER_H_
# define _PLAYER_H_

# include <iostream>
# include <string>
# include <climits>

class NPC;

class Player {
protected:
	int PC_HP;
	int PC_ATK;
	int PC_DEF;
		
	int PC_row;
	int PC_col;
	
	int gold;
	int max = INT_MAX;
	
	char Object;
 	std::string name;
	 
	float modifier;

	const int base_ATK;
	const int base_DEF;
	const int PC_MAXHP;  
	
public:
	Player(std::string name, int HP, int ATK, int DEF, 
        const int MAXHP, const int defaultATK, const int defaultDEF);
 	void setPosn(int x, int y);
	int getHP();
	int getATK();
	int getDEF();
	int getRow();
	int getCol();
	int getGold();
	float getMod();
	std::string getName();
	void move(int x, int y); 
	void resetPlayer();
	void increaseGold(int g);  
	void setATK(int a);
	void setDEF(int a);
	void setHP(int a);
	    // Attacks NPC
    	virtual void PCattacksNPC( NPC & enemy, int random ) = 0 ;
    	// Attacked By NPC
    	virtual void attackedbyNPC( NPC & enemy ) = 0 ;
	
};

#endif
