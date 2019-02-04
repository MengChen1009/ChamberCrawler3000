#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include "controller.h"
#include "game.h"
#include "view.h"
#include <stdio.h>
#include <cstring>
#include <fstream>
using namespace std;

Controller::Controller(string filename, bool IsCustomedMap): 
	filename{filename}, IsCustomedMap{IsCustomedMap}, g{make_unique<Game>()}{}    

void Controller::command(){
	string input;
	ifstream file(filename);
	if (!file){
		cout << "Invalid file" << endl;
		return;
	}	
	bool paused = false;
	PrintRaceInfo();
	while (!cin.eof()){
		cin >> input;
        	if ((input == "s") || (input == "d") || (input == "v") ||
               	 (input == "t") || (input == "g")){
                        if (IsCustomedMap == true){
                                g->setCustom(true);
                                g->initfile(filename, input);
                        }
                        else {
                                g->setCustom(false);
                                g->init(filename, input);
                        }
			break;
                }
                else if ((input == "q") || (cin.eof())){
                        cout << "Bye!" << endl;
                        return;
                }
                else {
                        cout << "Invalid input!" << endl;
                }
        }

	while(!cin.eof()){
		cin >> input;
		if (input == "r"){
			cout << "Restaring Game." << endl;
			PrintRaceInfo();	
			while (!cin.eof()){
				cin >> input;
				if ((input == "s") || (input == "d") || (input == "v") ||
                			(input == "t") || (input == "g")){
                        		if (IsCustomedMap == true){
                                		g->setCustom(true);
                               			g->initfile(filename, input);
                        		}
                        		else {
                                		g->setCustom(false);
                               			g->init(filename, input);
                       			}
					break;
                		}
				else if ((input == "q") || (cin.eof())){
                        		cout << "Bye!" << endl;
                        		return;
                		}
                		else {
                        		cout << "Invalid input!" << endl;
               	 		}
        		}
		}
        	if (input == "q"){
			g->endGame();
			cout << "Bye!" << endl;
			return;
		}
		if (input == "no") {
			if (g->movePlayer(-1, 0)){
				if (!paused){
					g->moveEnemies();
				}
				else g->printScreen();
			}
			else continue;
            	} 
		if (input == "so") {
              		if (g->movePlayer(1, 0)){
				if (!paused){
					g->moveEnemies();
				}
				else g->printScreen();
			}
			else continue;
           	}
		if (input == "ea") {
               		if (g->movePlayer(0, 1)){
				if (!paused){
                                        g->moveEnemies();
                                }
				else g->printScreen();	
			}
			else continue;
	        }	
		if (input == "we") {
       	        	if (g->movePlayer(0, -1)){
				if (!paused){
					g->moveEnemies();	
				}
				else g->printScreen();
			}
			else continue;
            	}
		if (input == "ne") {
                	if (g->movePlayer(-1, 1)){
				if (!paused){
                                        g->moveEnemies();
                                }
				else g->printScreen();
			}
			else continue;
	        } 
		if (input == "nw") {
                	if (g->movePlayer(-1, -1)){
				 if (!paused){
                                        g->moveEnemies();
                                }
				else g->printScreen();
			}
			else continue;
	        } 
		if (input == "se") {
			if (g->movePlayer(1, 1)){
				 if (!paused){
                                        g->moveEnemies();
                                }
				else g->printScreen();
			}
			else continue;
	        } 
		if (input == "sw") {
                	if (g->movePlayer(1, -1)){
				 if (!paused){
                                        g->moveEnemies();
                                }
				else g->printScreen();
			}
			else continue;
		}
		if (input == "f"){
			if (paused){
				paused = false;
				cout << "Game unpaused." << endl;
			}
			else {
				paused = true;
				cout << "Game paused." << endl;
			}		
		}
		if (input == "a"){
			cin >> input;
			if (input == "no"){
				if (g->playerAttack(-1, 0)){
					if (!paused){
                                        	g->moveEnemies();
                                	}
					else g->printScreen();
				}
			}
			 if (input == "so"){
                                if (g->playerAttack(1, 0)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }

 			if (input == "ea"){
                                if (g->playerAttack(0, 1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }

 			if (input == "we"){
                                if (g->playerAttack(0, -1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }

 			if (input == "ne"){
                                if (g->playerAttack(-1, 1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }

 			if (input == "nw"){
                                if (g->playerAttack(-1, -1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }

			if (input == "se"){
                                if (g->playerAttack(1, 1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }

 			if (input == "sw"){
                                if (g->playerAttack(1, -1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }

	
		}
		if (input == "u"){
                        cin >> input;
                        if (input == "no"){
                                if (g->playerUse(-1, 0)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
			if (input == "so"){
                                if (g->playerUse(11, 0)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
 			if (input == "ea"){
                                if (g->playerUse(0, 1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
 			if (input == "we"){
                                if (g->playerUse(0, -1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
 			if (input == "ne"){
                                if (g->playerUse(-1, 1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
 			if (input == "nw"){
                                if (g->playerUse(-1, -1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
 			if (input == "se"){
                                if (g->playerUse(1, 1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
			if (input == "sw"){
                                if (g->playerUse(1, -1)){
                                        if (!paused){
                                                g->moveEnemies();
                                        }
                                        else g->printScreen();
                                }
                        }
                }
	}
}


void Controller::PrintRaceInfo() {
    cout << "Choose your race: s, d, v, t, g" << endl;
    
    // s-shade
	cout << "s (Shade): " << '\n' << "HP: 125" <<  '\n' 
	<< "Atk: 25" << '\n' << "Def: 25" 
	<< '\n' << "Special Ability: Gets a bonus."
	<< endl;
    //drow,
	cout << "d (Drow): " << '\n' << "HP: 150" <<  '\n' 
	<< "Atk: 25" << '\n' << "Def: 15" << '\n' 
	<< "Special Ability: Potion effects are magnified by 1.5" << endl;
    //vampire
	cout << "v (Vampire): " << '\n' << "HP: 50" <<  '\n' 
	<< "Atk: 25" << '\n' << "Def: 25" << '\n' 
	<< "Special Ability: Gains 5HP every attack and has no max HP" << endl;
    //troll
	cout << "t (Troll): " << '\n' << "HP: 120" <<  '\n' 
	<< "Atk: 25" << '\n' << "Def: 15" << '\n'
	<< "Regains 5 HP every turn" << endl;
    //goblin
	cout << "g (Goblin): " << '\n' << "HP: 110" <<  '\n' 
	<< "Atk: 15" << '\n' << "Def: 20" << '\n' 
	<< "Steals 5 gold from every slain enemy" << endl;
}


