#ifndef _CONVERSION_HPP_
# define _CONVERSION_HPP_

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

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
	void printRezult() const;

	class NoConvertString : public std::exception
	{
	public:
		const char* what() const throw();
	};
private:
	std::string string;
	bool infValue;
	Conversion();
	void printrInfValue(char c) const;
};

#endif