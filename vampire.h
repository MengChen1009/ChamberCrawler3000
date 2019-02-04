# ifndef _VAMPIRE_H_
# define _VAMPIRE_H_
# include <iostream>
# include "player.h"
# include <climits>
class Vampire : public Player {

  public:

  // Defualt Constructor
  Vampire() ;

  void PCattacksNPC( NPC & enemy, int random ) override ; 

  void attackedbyNPC( NPC & enemy ) override ;

};

#endif
