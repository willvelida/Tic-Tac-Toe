#include <iostream>
#include "creategame.h"

void askPlayerName() {

	std::string player_name;

	std::cout << "What is your name?: ";
	std::cin >> player_name;

	std::cout << "Hello there " << player_name << "\n";
}

std::string askPlayerForOpponent() {
	std::string opponent_choice;

	// Just make the user play against the computer for now
	std::cout << "Would you like to play against a human or the PC?\n";
	std::cout << "Type in PC for Computer or HU for human: ";
	std::cin >> opponent_choice;

	return opponent_choice;
}

void createOpponent() {

	std::string opponent_choice = askPlayerForOpponent();

	while (opponent_choice != "PC" && opponent_choice != "pc") {

		if (opponent_choice == "HU" || opponent_choice == "hu") {
			std::cout << "You are unable to play against another human at this time!\n";
			opponent_choice = askPlayerForOpponent();
		}
		else {
			std::cout << "Invalid input. Please try again!\n";
			opponent_choice = askPlayerForOpponent();
		}		
	}

	std::cout << "Get ready to play against the computer!\n";
}