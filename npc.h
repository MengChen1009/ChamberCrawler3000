# ifndef _NPC_H_
# define _NPC_H_

# include <iostream>
# include <string>
# include <memory>
class Player;

class NPC {

protected:
	int NPC_HP ;
	int NPC_ATK ;
	int NPC_DEF ;

	int NPC_row ;
	int NPC_col ;
	
	char Object;
	std::string name;
	bool moved = false;
	bool dead = false;
	static bool merchantHostile;
	
	int goldx;
	int goldy;	
		 

public:
	NPC(std::string name, char n, int HP, int ATK, int DEF);
        void setPosn(int x, int y);
	void setMoved(bool m);
	bool getMoved();
	bool Dead();
        int getHP();
        int getATK();
        int getDEF();
        int getRow();
        int getCol();
	void setHP(int a);
	void setDead();
	char getObject();
        void move(int x, int y);
	void setHostile();
	bool getHostile();
	// NPC Attacks PC
    	void NPCattacksPC(std::unique_ptr<Player> const &player, int random) ;
	int getGoldx();
        int getGoldy();
	void setGoldxy(int x, int y);

} ;

#endif
