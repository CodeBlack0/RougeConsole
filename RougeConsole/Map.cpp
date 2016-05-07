#include "Map.hpp"

Map::Map()
{
}

Map::Map(std::vector<std::string> d)
{
	design = d;
}

void Map::insertline(std::string line)
{
	design.push_back(line);
}

void Map::setCoord(Coords coord, char sym)
{
	design.at(coord.y)[coord.x] = sym;
}

char Map::getCoord(Coords coord)
{
	return design.at(coord.y)[coord.x];
}

std::vector<std::string> * Map::getlayout()
{
	return &design;
}
