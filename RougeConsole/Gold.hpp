#ifndef GOLD_HPP
#define GOLD_HPP

#include "Item.hpp"

class Gold :
	public Item
{
public:
	Gold();
	Gold(std::string line);

	void trigger(Player * p);

private:

	int value;
};
#endif
