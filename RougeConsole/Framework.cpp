#include "Framework.hpp"

Framework::Framework()
{
}

Framework::Framework(std::string gamepath)
{
}

Framework::Framework(std::string ppath, std::string dpath, WINDOW * mapScreen)
	: mapscreen(mapScreen)
{
	p = new Player(ppath);
	d = new Dungeon(dpath);
}

void Framework::play()
{
	d->play(mapscreen, p);
}
