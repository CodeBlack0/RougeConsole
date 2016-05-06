#include "Activatorlist.hpp"

ActivatorList::ActivatorList()
{
}

void ActivatorList::insert(Activator * ac)
{
	activators.push_back(ac);
}

Activator * ActivatorList::getActivatorAt(Coords pos)
{
	for (auto it : activators)
	{
		Coords * tmp(it->getSelfPos());
		if (tmp->x == pos.x && tmp->y == pos.y)
			return it;
	}
	return new Activator();
}
