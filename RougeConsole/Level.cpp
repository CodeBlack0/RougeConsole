#include "Level.hpp"

Level::Level()
{
	done = false;
}

Level::Level(std::string path)
{
	Level();
	layout = new Map();
	map = new Map();

	std::ifstream file(path + ".gl");
	std::vector<std::string> data;
	std::vector<std::string> linedata;

	/* get data from into vector */
	std::string line;
	if (file.is_open())
		while (std::getline(file, line))
			data.push_back(line);
	file.close();

	/* tokenize first line and extract data */
	linedata = tokenize(data.at(0), ';');
	name = linedata.at(0);
	size = Coords(std::stoi(linedata.at(1)), std::stoi(linedata.at(2)));
	startpos = Coords(std::stoi(linedata.at(3)), std::stoi(linedata.at(4)));

	/* extracting layout data from corresponding lines */
	std::vector<std::string> layoutdata;
	for (int i = 1; i < size.y; i++)
		layout->insertline(data.at(i));
	map = layout;
	data.erase(data.begin(), data.begin() + size.y);

	/* extracting activator, item data from rest data */
	for (auto it : data)
	{
		switch (it.at(0))
		{
		case 'A':
			activators.insert(new Activator(it));
			break;
		case 'I':
			items.insert(new Item(it));
			break;
		case 'G':
			items.insert(new Gold(it));
			break;
		default:
			break;
		}
	}

	done = false;
}

void Level::play(WINDOW * screen, Player * p)
{
	int ch;

	*p->getPos() = startpos;

	printToMap(p);
	draw(screen);

	while ((ch = getch()) != 'q')
	{
		update(p, ch);
		draw(screen);
		refresh();
		if (done)
			break;
	}
}

Coords * Level::getSize()
{
	return &size;
}

void Level::draw(WINDOW * screen)
{
	wclear(screen);

	for (auto line : *map->getlayout())
	{
		for (auto pixel : line)
		{
			switch (pixel)
			{
			case '#':
				attron(A_NORMAL | COLOR_PAIR(6));
				wprintw(screen, "%c", '#');
				attroff(A_NORMAL | COLOR_PAIR(6));
				break;
			case '.':
				attron(A_DIM | COLOR_PAIR(5));
				wprintw(screen, "%c", '.');
				attroff(A_DIM | COLOR_PAIR(5));
				break;
			case '~':
				attron(A_DIM | COLOR_PAIR(4));
				wprintw(screen, "%c", '~');
				attroff(A_DIM | COLOR_PAIR(4));
				break;
			case '@':
				attron(A_BOLD | COLOR_PAIR(1));
				wprintw(screen, "%c", '@');
				attroff(A_BOLD | COLOR_PAIR(1));
				break;
			case '|': case '-': case '+':
				//wprintw(screen, " ");
				break;
			default:
				wprintw(screen, "%c", pixel);
				break;
			}
		}
		wprintw(screen, "\n");
	}
	box(screen, 0, 0);
	wrefresh(screen);
}

void Level::update(Player * p, int key)
{
	getDir(p, key);
	if (p->dir.x != 0 || p->dir.y != 0)
		move(p);
	printToMap(p);
}

void Level::getDir(Player * p, int key)
{
	p->dir = Coords(0, 0);

	switch (key)
	{
	case 'W': 
	case 'w':
		p->dir.y = -1;
		break;
	case 'A': 
	case 'a':
		p->dir.x = -1;
		break;
	case 'S': 
	case 's':
		p->dir.y = 1;
		break;
	case 'D': 
	case 'd':
		p->dir.x = 1;
		break;

	default:
		break;
	}
}

void Level::move(Player * p)
{
	checkItemCollsion(p);
	checkActivatorCollsion(p);
	if (!checkCollsion(p))
	{
		p->setPos(Coords(p->getPos()->x + p->dir.x, p->getPos()->y + p->dir.y));
	}
}

bool Level::checkCollsion(Player * p)
{
	char mapval = map->getCoord(Coords(p->getPos()->x + p->dir.x, p->getPos()->y + p->dir.y));
	if (mapval == 'O')
		done = true;
	if (mapval != '#' && mapval != '%' && mapval != ' ')
		return false;

	return true;
}

bool Level::checkActivatorCollsion(Player * p)
{
	auto *ac = activators.getActivatorAt(Coords(p->getPos()->x + p->dir.x, p->getPos()->y + p->dir.y));
	if (ac)
	{
		ac->trigger();
		return true;
	}
	return false;
}

bool Level::checkItemCollsion(Player * p)
{
	auto *it = items.getItemAt(Coords(p->getPos()->x + p->dir.x, p->getPos()->y + p->dir.y));
	if (it)
	{
		it->trigger(p);
		return true;
	}
	return false;
}

void Level::printToMap(Player * p)
{
	map = new Map(*layout);

	for (auto it : *activators.getList())
	{
		map->setCoord(*it->getSelfPos(), *it->getSelfChar());
		map->setCoord(*it->getTargetPos(), *it->getTargetChar());
	}

	for (auto it : *items.getList())
	{
		if (*it->getSym() != '³')
			map->setCoord(*it->getPos(), *it->getSym());
	}

	map->setCoord(*p->getPos(), '@');
}

