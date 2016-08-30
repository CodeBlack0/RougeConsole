#include "Framework.hpp"

int main(int argc, char** argv)
{
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);

	if (has_colors() == TRUE) 
	{
		start_color();

		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_BLACK, COLOR_BLACK);
		init_pair(6, COLOR_CYAN, COLOR_BLACK);
		if (can_change_color() == TRUE) 
		{
			init_color(COLOR_WHITE, 1000, 0, 0);
			init_pair(7, COLOR_WHITE, COLOR_BLACK);
		}
	}

	int height = 20;
	int width = 30;
	WINDOW *mapwin;
	mapwin = create_newwin(height, width, (LINES - height) / 2, (COLS - width) / 2);

	Framework * fm = new Framework("Player_A", "Test_Dungeon", stdscr);

	fm->play();


	endwin();
	return 0;
}