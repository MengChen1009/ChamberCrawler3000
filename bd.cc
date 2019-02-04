# include "bd.h"
#include <memory>
using namespace std ; 


// Intializes as follows.
BD::BD() : Potion("Boost Defence", 'P'){}

void BD::applyEffect(unique_ptr<Player> const &player){
	player->setDEF((player->getMod()) * 5);
}


