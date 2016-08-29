#include "Gold.hpp"

Gold::Gold()
{
}

Gold::Gold(std::string line)
{
	std::vector<std::string> linedata;
	linedata = tokenize(line, ';');
	
	pos = Coords(std::stoi(linedata.at(1)), std::stoi(linedata.at(2)));
	value = std::stoi(linedata.at(3));
	sym = CharSet('$', '³');

	used = false;
}

void Gold::trigger(Player * p)
{
	p->addGold(value);
	used = true;
}