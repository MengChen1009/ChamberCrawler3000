# ifndef _TROLL_H_
# define _TROLL_H_
# include <iostream>
# include "player.h"
#include <climits>
class Troll : public Player {

  public:

  // Defualt Constructor
  Troll() ;

  void PCattacksNPC( NPC & enemy, int random ) override ;

  void attackedbyNPC( NPC & enemy ) override ; 

};

#endif
