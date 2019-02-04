# ifndef WA_H
# define WA_H

# include "potion.h"
# include "player.h"

class WA : public Potion {

  public:

  // Defualt Constructor
  WA() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

