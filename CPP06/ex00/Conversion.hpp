#ifndef _CONVERSION_HPP_
# define _CONVERSION_HPP_

#include <iostream>
#include <cstdlib>

class Conversion
{
public:
	~Conversion();
	Conversion(char *str);
	Conversion(const Conversion& tmp);
	Conversion& operator=(const Conversion& tmp);
	char getChar() const;
	int getInt() const;
	float getFloat() const;
	double getDouble() const;
private:
	Conversion();
	double rez;
};

std::ostream& operator<<(std::ostream& out, const Conversion& a);

#endif