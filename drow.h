# ifndef _DROW_H_
# define _DROW_H_
# include <iostream>
# include "player.h"
# include <climits>
class Drow : public Player {

  public:

  // Defualt Constructor
  Drow() ;
 
  void PCattacksNPC( NPC & enemy, int random ) override ; 
  
  void attackedbyNPC( NPC & enemy ) override ;
	
};

#endif

