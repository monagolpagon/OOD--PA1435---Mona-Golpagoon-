#ifndef MAIN_GAME_SYSTEM_H
#define MAIN_GAME_SYSTEM_H
#include "Player.h"
#include "Dungeon.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <conio.h>

class MainGameSystem
{
private:
	Dungeon dungeon;
	Player player;
public:
	// Constructor
	MainGameSystem(string dungeonFileName);
	// Start game
	void startGame();
	// Move player with user input
	void inputKeyMovement();
};
#endif // !MAIN_GAME_SYSTEM_H
