#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "Utils.hpp"
#include "Coords.hpp"

class Player
{
public:

	Player();
	Player(std::string path);

	Coords *getPos();
	void setPos(Coords newpos);

	Coords dir;

private:
	
	Coords pos;
	std::string name;
	int health;
	int maxhealth;
	int lvl;
	int xp;
	int gold;
};


#endif