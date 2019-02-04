# ifndef BA_H
# define BA_H

# include "potion.h"
#include "player.h"

class BA : public Potion {

  public:

  // Defualt Constructor
  BA() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

