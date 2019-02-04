# include "sgold.h"
# include <memory>

using namespace std ; 


// Intializes as follows.
SGold::SGold() : Gold("Small Gold", 'G', 1){}

void SGold::applyEffect(unique_ptr<Player> const &player){
	player->increaseGold(1);
}



