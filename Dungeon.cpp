#include "Dungeon.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

void Dungeon::updatePlayerMovement(Player & player, int playerTargetPosX, int playerTargetPosY)
{
	int currentPosX, currentPosY;

	player.getPosition(currentPosX, currentPosY);

	char moveDungeonTile = getDungeonTile(playerTargetPosX, playerTargetPosY);

	switch (moveDungeonTile)
	{
	case '.':
		player.setPosition(playerTargetPosX, playerTargetPosY);
		setDungeonTile(currentPosX, currentPosY, '.');
		setDungeonTile(playerTargetPosX, playerTargetPosY, '@');
		break;
	}
}

Dungeon::Dungeon()
{

}

void Dungeon::loadEntity(string dungeonName, Player & player)
{
	ifstream gameDungeon;

	gameDungeon.open(dungeonName);

	if (gameDungeon.fail())
	{
		perror(dungeonName.c_str());
		getchar();
		exit(1);
	}

	string dungeonLine;

	while (getline(gameDungeon, dungeonLine))
	{
		dungeonData.push_back(dungeonLine);
	}
	gameDungeon.close();

	// Update the dungeon, when player moves

	char dungeonTile;

	for (int i = 0; i < dungeonData.size(); i++)
	{
		for (int j = 0; j < dungeonData[i].size(); j++)
		{
			dungeonTile = dungeonData[i][j];

			switch (dungeonTile)
			{
			case '@':
				player.setPosition(j, i);
				break;
			}
		}
	}

}

void Dungeon::renderGameMovements()
{
	system("cls");

	for (int i = 0; i < dungeonData.size(); i++)
	{
		printf("%s\n", dungeonData[i].c_str());
	}
	printf("\n");
}

void Dungeon::movePlayerKey(char userInput, Player & player)
{
	int currentPosX, currentPosY;

	player.getPosition(currentPosX, currentPosY);

	switch (userInput)
	{
	case 'w':
	case 'W':
		updatePlayerMovement(player, currentPosX, currentPosY - 1);
		break;

	case 'a':
	case 'A':
		updatePlayerMovement(player, currentPosX - 1, currentPosY);
		break;

	case 's':
	case 'S':
		updatePlayerMovement(player, currentPosX, currentPosY + 1);
		break;

	case 'd':
	case 'D':
		updatePlayerMovement(player, currentPosX + 1, currentPosY);
		break;
	default:
		cout << "WRONG KEY INPUT" << endl;
		break;
	}
}

char Dungeon::getDungeonTile(int posX, int posY)
{
	char dungeonTile = dungeonData[posY][posX];
	return dungeonTile;
}

void Dungeon::setDungeonTile(int posX, int posY, char dungeonWall)
{
	dungeonData[posY][posX] = dungeonWall;
}
