#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <curses.h>
#include <string>
#include "Coords.hpp"

class Map
{
public:

	Map();
	Map(std::vector<std::string> d);

	void insertline(std::string line);
	void setCoord(Coords coord, char sym);
	char getCoord(Coords coord);
	std::vector<std::string> getlayout();

private:

	std::vector<std::string> design;
};

#endif