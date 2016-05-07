#include "Utils.hpp"

std::vector<std::string> tokenize(std::string line, char delim)
{
	std::vector<std::string> tokens;

	size_t pos = 0;
	int j = 0;
	while ((pos = line.find(delim)) != std::string::npos) 
	{
		tokens.push_back(line.substr(0, pos));
		line.erase(0, pos + 1);
		j++;
	}

	return tokens;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0); 
	wborder(local_win, '|', '|', '−', '−', '+', '+', '+', '+');
	wrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win); 
	delwin(local_win);
}