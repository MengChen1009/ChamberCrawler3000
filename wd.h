# ifndef WD_H
# define WD_H

# include "potion.h"
# include "player.h"

class WD : public Potion {

  public:

  // Defualt Constructor
  WD() ;
  void applyEffect(std::unique_ptr<Player> const &player) override; 

} ;

#endif

