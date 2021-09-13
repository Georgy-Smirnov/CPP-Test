#include "Conversion.hpp"

Conversion::Conversion() {}

Conversion::Conversion(char *str) : rez(atof(str))
{

}

Conversion::~Conversion() {}

Conversion::Conversion(const Conversion& tmp) : rez(tmp.rez) {}

Conversion& Conversion::operator=(const Conversion& tmp)
{
	if (this == &tmp)
		return (*this);
	rez = tmp.rez;
	return (*this);
}

int Conversion::getInt() const
{
	return (static_cast<int>(rez));
}

float Conversion::getFloat() const
{
	return (static_cast<float>(rez));
}

char Conversion::getChar() const
{
	return (static_cast<char>(rez));
}

double Conversion::getDouble() const
{
	return (static_cast<double>(rez));
}

std::ostream& operator<<(std::ostream& out, const Conversion& a)
{
	if (a.getChar() < 32 || a.getChar() > 126)
		out << "char: Non displayable\n";
	else
		out << "char: " << a.getChar() << std::endl;
	out << "int: " << a.getInt() << std::endl;
	if (a.getFloat() == static_cast<float>(a.getInt()))
		out << "float: " << a.getFloat() << ".0f" << std::endl;
	else
		out << "float: " << a.getFloat() << "f" << std::endl;
	if (a.getDouble() == static_cast<double>(a.getInt()))
		out << "double: " << a.getDouble() << ".0" << std::endl;
	else
		out << "double: " << a.getDouble() << std::endl;
	return (out);
}