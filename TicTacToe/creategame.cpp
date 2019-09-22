#include <iostream>
#include "creategame.h"

void askPlayerName() {

	std::string player_name;

	std::cout << "What is your name: ";
	std::cin >> player_name;

	std::cout << "Hello there " << player_name;
}