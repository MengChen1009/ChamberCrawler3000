# include "ph.h"
# include <memory>
using namespace std ; 


// Intializes as follows.
PH::PH() : Potion("Poison Health", 'P'){}

void PH::applyEffect(unique_ptr<Player> const &player){
	player->setHP((player->getMod()) * -10);
}



