#include "CharSet.hpp"

CharSet::CharSet()
	: a(' '), b(' ')
{
}

CharSet::CharSet(char a, char b)
	: a(a), b(b)
{
}

char * CharSet::getA()
{
	return &a;
}

char * CharSet::getB()
{
	return &b;
}
