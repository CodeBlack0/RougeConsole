#include "Dungeon.hpp"

Dungeon::Dungeon()
{
}

Dungeon::Dungeon(std::string path)
{
}

void Dungeon::play(WINDOW * screen)
{
	for (auto it : levels)
		it->play(screen);
}
