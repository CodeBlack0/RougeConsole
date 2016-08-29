#include "Item.hpp"

Item::Item()
{
}

Item::Item(std::string line)
{
	std::vector<std::string> linedata;
	linedata = tokenize(line, ';');

	pos = Coords(std::stoi(linedata.at(1)), std::stoi(linedata.at(2)));
	sym = CharSet(linedata.at(3).at(0), linedata.at(4).at(0));

	used = false;
}

Coords * Item::getPos()
{
	return &pos;
}

char * Item::getSym()
{
	if (used)
		return sym.getB();
	else
		return sym.getA();
}