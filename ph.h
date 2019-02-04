# ifndef PH_H
# define PH_H

# include "potion.h"
# include "player.h"

class PH : public Potion {

  public:

  // Defualt Constructor
  PH() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

