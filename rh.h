# ifndef RH_H
# define RH_H

# include "potion.h"
# include "player.h"

class RH : public Potion {

  public:

  // Defualt Constructor
  RH() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

