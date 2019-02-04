# ifndef SGOLD_H
# define SGOLD_H

# include "gold.h"
#include "player.h"

class SGold : public Gold {

  public:

  // Defualt Constructor
  SGold() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

