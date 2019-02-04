# include "mgold.h"
# include <memory>

using namespace std ; 


// Intializes as follows.
MGold::MGold() : Gold("Merchant Gold", 'G', 4){}

void MGold::applyEffect(unique_ptr<Player> const &player){
	player->increaseGold(4);
}



