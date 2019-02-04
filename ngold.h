# ifndef NGOLD_H
# define NGOLD_H

# include "gold.h"
#include "player.h"

class NGold : public Gold {

  public:

  // Defualt Constructor
  NGold() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

