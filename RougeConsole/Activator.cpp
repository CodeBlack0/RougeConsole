#include "Activator.hpp"

Activator::Activator()
{
	state = false;
}

Activator::Activator(std::string line)
{
	std::vector<std::string> linedata;
	linedata = tokenize(line, ';');

	pos = Coords(std::stoi(linedata.at(1)), std::stoi(linedata.at(2)));
	selfChars = CharSet(linedata.at(3).at(0), linedata.at(4).at(0));

	target = Coords(std::stoi(linedata.at(5)), std::stoi(linedata.at(6)));
	targetChars = CharSet(linedata.at(7).at(0), linedata.at(8).at(0));

	state = false;
}

Coords * Activator::getSelfPos()
{
	return &pos;
}

char * Activator::getSelfChar()
{
	if (state)
		return selfChars.getB();
	else
		return selfChars.getA();
}

Coords * Activator::getTargetPos()
{
	return &target;
}

char * Activator::getTargetChar()
{
	if (state)
		return targetChars.getB();
	else
		return targetChars.getA();
}

void Activator::trigger()
{
	state = !state;
}

bool Activator::getState()
{
	return state;
}
