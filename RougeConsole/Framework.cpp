#include "Framework.hpp"

Framework::Framework()
{
}

Framework::Framework(std::string gamepath)
{
}

Framework::Framework(std::string ppath, std::string dpath, WINDOW * mapScreen)
	//: mapscreen(*mapScreen)
{
	p = new Player(ppath);
	d = new Dungeon(dpath);

	int height = d->getLevels()->at(0)->getSize()->y;
	int width = d->getLevels()->at(0)->getSize()->x - 1;

	mapscreen = *create_newwin(height, width, (LINES - height) / 2, (COLS - width) / 2);
}

void Framework::play()
{
	d->play(&mapscreen, p);
}
