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

class Level
{
public:

	Level();
	Level(std::string path);

	void play(WINDOW * screen);

private:
	
	void draw(WINDOW * screen);

	WINDOW * screen;
	Map * layout;
	Map * map;
	ActivatorList activators;
	std::vector<Item *>	items;
	std::string name;
	Coords size;
	Coords startpos;

};

#endif