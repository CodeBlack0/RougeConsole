#include "Itemlist.hpp"

ItemList::ItemList()
{
}

void ItemList::insert(Item * ac)
{
	items.push_back(ac);
}

Item * ItemList::getItemAt(Coords pos)
{
	for (auto it : items)
	{
		Coords * tmp(it->getPos());
		if (tmp->x == pos.x && tmp->y == pos.y)
			return it;
	}
	return new Item();
}

std::vector<Item*>* ItemList::getList()
{
	return &items;
}
