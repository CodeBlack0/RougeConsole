#ifndef ITEMLIST_HPP
#define ITEMLIST_HPP

#include <vector>

#include "Item.hpp"
#include "Coords.hpp"

class ItemList
{
public:

	ItemList();

	void insert(Item * ac);
	Item * getItemAt(Coords pos);
	std::vector<Item *> * getList();

private:

	std::vector<Item *> items;

};

#endif