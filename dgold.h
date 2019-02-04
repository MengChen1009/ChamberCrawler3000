# ifndef DGOLD_H
# define DGOLD_H

# include "gold.h"
#include "player.h"

class DGold : public Gold {

  public:

  // Defualt Constructor
  DGold() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 
} ;

#endif

