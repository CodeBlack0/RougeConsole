#include "Framework.hpp"

int main(int argc, char** argv)
{
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);

	int height = 20;
	int width = 30;
	WINDOW *mapwin;
	mapwin = create_newwin(height, width, (LINES - height) / 2, (COLS - width) / 2);

	Framework * fm = new Framework("Player_A", "Test_Dungeon", mapwin);

	fm->play();


	endwin();
	return 0;
}