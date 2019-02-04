# include "wa.h"
# include <memory>
using namespace std ; 


// Intializes as follows.
WA::WA() : Potion( "Wound Attack", 'P' ){}

void WA::applyEffect(unique_ptr<Player> const &player){
	player->setATK((player->getMod()) * -5);
}



