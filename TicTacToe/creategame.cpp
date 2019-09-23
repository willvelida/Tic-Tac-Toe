#include <iostream>
#include <stdlib.h>
#include "creategame.h"
#include <time.h>

std::string askPlayerName() {

	std::string player_name;

	std::cout << "What is your name?: ";
	std::cin >> player_name;

	std::cout << "Hello there " << player_name << "\n";
	
	return player_name;
}

std::string askPlayerForOpponent() {
	std::string opponent_choice;

	// Just make the user play against the computer for now
	std::cout << "Would you like to play against a human or the PC?\n";
	std::cout << "Type in PC for Computer or HU for human: ";
	std::cin >> opponent_choice;

	return opponent_choice;
}

std::string askPlayerForCoinChoice() {

	std::string coin_choice;

	std::cout << "Flip a coin to see who goes first\n";
	std::cout << "Heads or Tails? (Enter H for Heads, T for Tails)\n";

	std::cin >> coin_choice;

	return coin_choice;
}

std::string createOpponent() {

	std::string opponent_choice = askPlayerForOpponent();
	std::string opponent_name;

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

	opponent_name = "PC";
	std::cout << "Get ready to play against " << opponent_name << "\n";
	return opponent_name;
}

std::string coinFlip() {

	double coin_flip_number;
	std::string coin_flip_result;

	srand(time(NULL));

	coin_flip_number = rand() % 2;
	
	// include this number for debugging;
	std::cout << coin_flip_number << "\n";

	if (coin_flip_number < 0.5)
	{
		coin_flip_result = "Heads";
	}
	else
	{
		coin_flip_result = "Tails";
	}

	return coin_flip_result;
}

// Should be a bool
void whoGoesFirst() {

	std::string player_choice = askPlayerForCoinChoice();
	std::string coin_flip_result = coinFlip();

	if (player_choice == "H" || player_choice == "h")
	{
		// Player chooses heads
		std::cout << "You have chosen heads.\n";
		if (coin_flip_result == "Heads") {
			std::cout << "You won the toss\n";
			// Start first
		}
		else {
			std::cout << "You lost the toss\n";
			// start second
		}
	}
	else if (player_choice == "T" || player_choice == "t") {
		std::cout << "You have chosen tails.\n";
		if (coin_flip_result == "Tails") {
			std::cout << "You won the toss\n";
			// Start first
		}
		else {
			std::cout << "You lost the toss\n";
			// start second
		}
	}
	else {
		std::cout << "Please enter a valid choice\n";
		player_choice = askPlayerForCoinChoice();
	}
}