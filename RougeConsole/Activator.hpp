#ifndef ACTIVATOR_HPP
#define ACTIVATOR_HPP

#include <string>

#include "Coords.hpp"
#include "CharSet.hpp"

class Activator
{
public:

	Activator();
	Activator(std::string line);

	Coords * getSelfPos();
	char * getSelfChar();

	Coords * getTargetPos();
	char * getTargetChar();

	void trigger();
	bool getState();

private:

	Coords pos;
	CharSet selfChars;
	Coords target;
	CharSet targetChars;

	bool state;
};

#endif