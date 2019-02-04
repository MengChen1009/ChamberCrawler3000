# include "wd.h"
# include <memory>
using namespace std ; 


// Intializes as follows.
WD::WD() : Potion( "Wound Defence", 'P' ){}

void WD::applyEffect(unique_ptr<Player> const &player){
	player->setDEF((player->getMod()) * -5 );
}



