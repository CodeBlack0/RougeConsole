#include "Level.hpp"

Level::Level()
{
}

Level::Level(std::string path)
{
	std::ifstream file(path + ".gp");
	std::vector<std::string> data;
	std::vector<std::string> * linedata;

	/* get data from into vector */
	std::string line;
	if (file.is_open())
		while (std::getline(file, line))
			data.push_back(line);
	file.close();

	/* tokenize first line and extract data */
	linedata = &slice(data.at(0), ';');
	name = linedata->at(0);
	size = Coords(std::stoi(linedata->at(1)), std::stoi(linedata->at(2)));
	startpos = Coords(std::stoi(linedata->at(3)), std::stoi(linedata->at(4)));
	data.erase(data.begin());

	/* extracting layout data from corresponding lines */
	std::vector<std::string> layoutdata(&data[0], &data[size.y - 1]);
	for (auto it : layoutdata)
		layout->insertline(it);
	map = layout;
	data.erase(data.begin() + size.y - 1);

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

void Level::play(WINDOW * screen)
{
	int ch;

	while ((ch = getch()) != 'q')
	{
		draw(screen);
		refresh();
	}
}

void Level::draw(WINDOW * screen)
{
	for (auto line : map->getlayout())
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
			default:
				printw("%c", pixel);
				break;
			}
		}
		wprintw(screen, "\n");
	}
}
