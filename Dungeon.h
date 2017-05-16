#ifndef DUNGEON_H
#define DUNGEON_H
#include "Player.h"
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>

class Dungeon
{
private:
	// Update player movements
	void updatePlayerMovement(Player &player, int playerTargetPosX, int playerTargetPosY);
	vector <string> dungeonData;
public:
	// Default constructor
	Dungeon();
	// Load dungeon and player
	void loadEntity(string dungeonName, Player &player);
	// Display game window
	void renderGameMovements();
	// Move player;
	void movePlayerKey(char userInput, Player &player);
	// Get- and set-method
	char getDungeonTile(int posX, int posY);
	void setDungeonTile(int posX, int posY, char dungeonTile);
};
#endif 
