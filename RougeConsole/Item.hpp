#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include "Coords.hpp"
#include "Player.hpp"
#include "CharSet.hpp"

class Item
{
public:

	Item();
	Item(std::string line);

	void trigger(Player * p);

	Coords * getPos();
	char * getSym();


protected:

	bool used;

	Coords pos;
	CharSet sym;

};

#endif#pragma once
