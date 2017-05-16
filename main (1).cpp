#include "MainGameSystem.h"

int main()
{
	// Load dungeon from a specific directory
	MainGameSystem mainGameSystem("DungeonLevelOne.txt");
	// Start the game
	mainGameSystem.startGame();

	return 0;
}