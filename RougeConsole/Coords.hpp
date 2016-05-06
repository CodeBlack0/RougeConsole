#ifndef COORDS_HPP
#define COORDS_HPP

class Coords
{
public:
	
	Coords() : x(0), y(0) {}
	Coords(int x, int y) : x(x), y(y) {}
	
	int x;
	int y;

private:
};

#endif