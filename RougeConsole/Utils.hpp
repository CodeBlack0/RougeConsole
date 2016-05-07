#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
#include <curses.h>
 
std::vector<std::string> tokenize(std::string line, char delim);
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

#endif