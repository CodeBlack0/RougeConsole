#ifndef CHARSET_HPP
#define CHARSET_HPP

class CharSet
{
public:

	CharSet();
	CharSet(char a, char b);

	char * getA();
	char * getB();

private:

	char a;
	char b;

};

#endif