#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <vector>
#include <string>
#include "Level.hpp"

#include "Player.hpp"

class Dungeon
{
public:

	Dungeon();
	Dungeon(std::string path);

	void play(WINDOW * screen, Player * p);

private:

	std::vector<Level *> levels;
	std::string name;

	int currentLevel;

};

#endif