# ifndef _SHADE_H_
# define _SHADE_H_
# include <climits>
# include <iostream>
# include "player.h"

class Shade : public Player {

  public:

  // Defualt Constructor
  Shade() ;
  // Attacks NPC
  void PCattacksNPC( NPC & enemy, int random ) override ;
    // Attacked By NPC
  void attackedbyNPC( NPC & enemy ) override ;
};

#endif


