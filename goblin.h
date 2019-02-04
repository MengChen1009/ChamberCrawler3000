# ifndef _GOBLIN_H_
# define _GOBLIN_H_
# include <iostream>
# include "player.h"
#include <climits>
class Goblin : public Player {

  public:

  // Defualt Constructor
  Goblin() ;

  void PCattacksNPC( NPC & enemy, int random ) override ;
 
  void attackedbyNPC( NPC & enemy ) override ;
 

};

#endif
