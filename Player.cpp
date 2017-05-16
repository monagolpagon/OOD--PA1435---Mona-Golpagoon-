#include "Player.h"

Player::Player()
{
	playerPosX = 0;
	playerPosY = 0;
}

void Player::initializePlayer(string name, string gender, string characterType, string outfit)
{
	this->name = name;
	this->gender = gender;
	this->characterType = characterType;
	this->outfit = outfit;
}

void Player::getPosition(int & posX, int & posY)
{
	posX = playerPosX;
	posY = playerPosY;
}

void Player::setPosition(int newPlayerPosX, int newPlayerPosY)
{
	playerPosX = newPlayerPosX;
	playerPosY = newPlayerPosY;
}
