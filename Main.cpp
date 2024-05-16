#include <iostream>
#include <time.h>
#include <random>
#include "Game/Game.h"
using namespace std;

int main() {
	srand(time(0));	 // Generating a new seed for random of the current time 
	Game g;	// the constructor of the game moderates all the project
	return 0;
}