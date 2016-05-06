#include "Player.hpp"

Player::Player()
{
}

Player::Player(std::string path)
{
	std::ifstream file(path + ".gp");
	std::vector<std::string> data;
	std::vector<std::string> * linetokens;

	std::string line;
	if (file.is_open())
		while (std::getline(file, line))
			data.push_back(line);
	file.close();

	int i = 0;
	for (auto line : data)
	{
		switch (i)
		{
		case 0:
			name = line;
			break;
		case 1:
			linetokens = &slice(line, ';');
			health = std::stoi(linetokens->at(0));
			maxhealth = std::stoi(linetokens->at(1));
			break;
		case 2:
			linetokens = &slice(line, ';');
			lvl = std::stoi(linetokens->at(0));
			xp = std::stoi(linetokens->at(1));
			break;
		case 3:
			xp = std::stoi(line);
			break;
		default:
			break;
		}
		i++;
	}
}
