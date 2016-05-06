#ifndef ACTIVATORLIST_HPP
#define ACTIVATORLIST_HPP

#include <vector>

#include "Activator.hpp"
#include "Coords.hpp"

class ActivatorList
{
public:

	ActivatorList();

	void insert(Activator * ac);
	Activator * getActivatorAt(Coords pos);

private:

	std::vector<Activator *> activators;

};

#endif