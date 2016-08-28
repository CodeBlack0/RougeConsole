#include "Player.hpp"

Player::Player()
{
}

Player::Player(std::string path)
{
	std::ifstream file(path + ".gp");
	std::vector<std::string> data;
	std::vector<std::string> linetokens;

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
			linetokens = tokenize(line, ';');
			health = std::stoi(linetokens.at(0));
			maxhealth = std::stoi(linetokens.at(1));
			break;
		case 2:
			linetokens = tokenize(line, ';');
			lvl = std::stoi(linetokens.at(0));
			xp = std::stoi(linetokens.at(1));
			break;
		case 3:
			linetokens = tokenize(line, ';');
			gold = std::stoi(linetokens.at(0));
			break;
		default:
			break;
		}
		i++;
	}

	dir = Coords(0, 0);
}

Coords * Player::getPos()
{
	return &pos;
}

void Player::setPos(Coords newpos)
{
	pos = newpos;
}

int Player::getHealth()
{
	return health;
}

void Player::addHealth(int i)
{
	health += i;
}

void Player::setHealth(int i)
{
	health = i;
}

int Player::getMaxHealth()
{
	return maxhealth;
}

void Player::addMaxHealth(int i)
{
	maxhealth += i;
}

void Player::setMaxHealth(int i)
{
	maxhealth = i;
}

int Player::getGold()
{
	return gold;
}

void Player::addGold(int i)
{
	gold += i;
}

void Player::setGold(int i)
{
	gold = i;
}

int Player::getXp()
{
	return xp;
}

void Player::addXp(int i)
{
	xp += i;
}

void Player::setXp(int i)
{
	xp = i;
}
