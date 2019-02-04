# ifndef MGOLD_H
# define MGOLD_H

# include "gold.h"
#include "player.h"

class MGold : public Gold {

  public:

  // Defualt Constructor
  MGold() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

