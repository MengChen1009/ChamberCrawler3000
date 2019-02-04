# ifndef BD_H
# define BD_H

# include "potion.h"
#include "player.h"

class BD : public Potion {

  public:

  // Defualt Constructor
  BD() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

