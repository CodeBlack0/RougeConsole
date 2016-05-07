#include "Framework.hpp"

int main(int argc, char** argv)
{
	initscr();
	cbreak();

	WINDOW *mapwin;
	mapwin = create_newwin(10, 20, (LINES - 10) / 2, (COLS - 20) / 2);

	Framework * fm = new Framework("Player_A", "Test_Dungeon", stdscr);

	fm->play();


	endwin();
	return 0;
}