#include "Activator.hpp"

Activator::Activator()
{
	state = false;
}

Activator::Activator(std::string line)
{
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
