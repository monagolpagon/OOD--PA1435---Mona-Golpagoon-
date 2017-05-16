#include "MainGameSystem.h"

MainGameSystem::MainGameSystem(string dungeonFileName)
{
	// Initialize player with current property values
	player.initializePlayer("Player", "Female", "Knight", "Knight Armor");
	// Load dungoen from file and initialize player 
	dungeon.loadEntity(dungeonFileName, player);
}

void MainGameSystem::startGame()
{
	bool quitGame = false;

	while (quitGame != true)
	{
		dungeon.renderGameMovements();
		inputKeyMovement();
	}
}

void MainGameSystem::inputKeyMovement()
{
	char userInput;

	cout << "Enter a key (w/s/a/d) to move the player: ";
	userInput = _getch();

	dungeon.movePlayerKey(userInput, player);
}
