#ifndef PLAYER_H
#define PLAYER_H
#include <random>
#include <stdio.h>
#include <ctime>
#include <string>
using namespace std;

class Player
{
private:
	// Player Properties
	string name, gender, characterType, outfit;
	// Player Position
	int playerPosX;
	int playerPosY;
public:
	// Default constructor
	Player();
	// Initialize player with properties
	void initializePlayer(string name, string gender, string characterType, string outfit);
	// Get- and set-method
	void getPosition(int &posX, int &posY);
	void setPosition(int newPlayerPosX, int newPlayerPosY);
};
#endif 
#pragma once
