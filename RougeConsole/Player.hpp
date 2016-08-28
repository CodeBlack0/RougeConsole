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

	int getHealth();
	void addHealth(int i);
	void setHealth(int i);
	int getMaxHealth();
	void addMaxHealth(int i);
	void setMaxHealth(int i);
	int getGold();
	void addGold(int i);
	void setGold(int i);
	int getXp();
	void addXp(int i);
	void setXp(int i);


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