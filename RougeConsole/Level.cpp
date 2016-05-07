#include "Level.hpp"

Level::Level()
{
}

Level::Level(std::string path)
{
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
		default:
			break;
		}
	}
}

void Level::play(WINDOW * screen, Player * p)
{
	int ch;
	draw(screen);

	while ((ch = getch()) != 'q')
	{
		draw(screen);
		refresh();
	}
}

Coords * Level::getSize()
{
	return &size;
}

void Level::draw(WINDOW * screen)
{
	wclear(screen);

	//wprintw(screen, "\n");
	for (auto line : map->getlayout())
	{
		//wprintw(screen, " ");
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
