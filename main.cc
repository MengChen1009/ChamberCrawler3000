#include <string>
#include <iostream>
#include "game.h"
#include "controller.h"
using namespace std;

int main(int argc, char *argv[]){
	string filename = "map.txt";
	if (argc < 2){
		Controller c(filename, false);	
		c.command();
	}
	else {
		filename = argv[1];
		Controller c(filename, true);
		c.command();
	}
	return 0;
}
