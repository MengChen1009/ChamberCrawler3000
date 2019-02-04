#include <iostream>
#include "drow.h"
#include "player.h"
#include <climits>
#include "npc.h"
using namespace std ; 

Drow::Drow():  
	Player(
	"Drow",
	150, // HP
	25,  // ATK
	15,  // DEF
	150, // MAXHP
	25,  // defaultATK
	15)  // defaultDEF
{
	modifier = 1.5;
}

void Drow::PCattacksNPC( NPC & enemy, int random ) {

  char NPCname = enemy.getObject() ;

  int NPCDEF = enemy.getDEF() ;

  int damage = (100.0 / (100.0 + NPCDEF ) ) * PC_ATK ;

  if ( NPCname == 'M') { enemy.setHostile(); } // make merchant hostile

  // if attacked by HalfLing
  if ( ( NPCname == 'L' ) && ( random == 0 ) ) {
    return;
  }
  else { // run normal attacks (100% gaurantee hits.)
     enemy.setHP(-damage) ;
  }
 
}


void Drow::attackedbyNPC( NPC & enemy ) {
  char NPCname = enemy.getObject();

  int NPCATK = enemy.getATK();

  int damage = ( 100.0 / ( 100.0 + PC_DEF ) ) * NPCATK;

  if ( NPCname == 'H') {
    setHP(-damage);
  }

  else if ( NPCname == 'W') {
    setHP(-damage);
  }

  else if ( NPCname == 'E') { // Elf attacks twice
    setHP(-damage);
  }

  else if ( NPCname == 'O') {
    setHP(-damage);
  }

  else if ( NPCname == 'M') {
    setHP(-damage);
  }

  else if ( NPCname == 'D') {
    setHP(-damage);
  }

  else if ( NPCname == 'L') {
    setHP(-damage);
  }
  cout << "You got hit!" << endl;
}


