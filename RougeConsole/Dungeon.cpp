#include "Dungeon.hpp"

Dungeon::Dungeon()
{
}

Dungeon::Dungeon(std::string path)
{
	std::ifstream file(path + ".gd");

	std::string line;
	if (file.is_open())
		while (std::getline(file, line))
			levels.push_back(new Level(line));
	file.close();
}

void Dungeon::play(WINDOW * screen, Player * p)
{
	for (auto it : levels)
		it->play(screen, p);
}
