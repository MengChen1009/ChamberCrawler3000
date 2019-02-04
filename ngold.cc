# include "ngold.h"
# include <memory>

using namespace std ; 


// Intializes as follows.
NGold::NGold() : Gold("Normal Gold", 'G', 2){}

void NGold::applyEffect(unique_ptr<Player> const &player){
	player->increaseGold(2);
}



