# include "rh.h"
# include <memory>
using namespace std ; 


// Intializes as follows.
RH::RH() : Potion("Restore Health", 'P'){}

void RH::applyEffect(unique_ptr<Player> const &player){
	player->setHP((player->getMod()) * 10);
}



