# include "ba.h"
#include <memory>
using namespace std ; 


// Intializes as follows.
BA::BA() : Potion("Boost Attack", 'P'){}

void BA::applyEffect(unique_ptr<Player> const &player){
	player->setATK((player->getMod()) * 5);
}



