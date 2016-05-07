#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <curses.h>

#include "Player.hpp"
#include "Dungeon.hpp"

class Framework
{
public:

	Framework();
	Framework(std::string gamepath);
	Framework(std::string ppath, std::string dpath, WINDOW * mapScreen);

	void play();

private:
	
	Player *p;
	Dungeon *d;

	WINDOW * mapscreen;
	WINDOW GUIscreen;
};


#endif