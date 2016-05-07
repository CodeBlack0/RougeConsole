#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>
#include <curses.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "Coords.hpp"
#include "Map.hpp"
#include "Activatorlist.hpp"
#include "Item.hpp"
#include "Utils.hpp"
#include "Player.hpp"

class Level
{
public:

	Level();
	Level(std::string path);

	void play(WINDOW * screen, Player * p);

	Coords * getSize();

private:
	
	void draw(WINDOW * screen);
	void update(Player * p, int key);

	void getDir(Player * p, int key);
	void move(Player * p);
	bool checkCollsion(Player * p);
	bool checkActivatorCollsion(Player * p);

	void printToMap(Player * p);

	WINDOW * screen;
	Map * layout;
	Map * map;
	ActivatorList activators;
	std::vector<Item *>	items;
	std::string name;
	Coords size;
	Coords startpos;
	bool done;
};

#endif