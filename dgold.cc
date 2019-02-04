# include "dgold.h"
# include <memory>

using namespace std ; 


// Intializes as follows.
DGold::DGold() : Gold("Dragon Gold", 'G', 6){}

void DGold::applyEffect(unique_ptr<Player> const &player){
	player->increaseGold(6);
}


