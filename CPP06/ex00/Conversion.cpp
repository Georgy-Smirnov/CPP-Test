#include "Conversion.hpp"

Conversion::Conversion() {}

bool isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return(true);
	return (false);
}

bool checkString(std::string& str, bool* infValue)
{
	size_t count;
	bool checkPrecision = false;
	if (str.length() > 16)
		return(true);
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "nanf")
		return (!(*infValue = true));
	if (!((str[0] >='0' && str[0] <= '9') || str[0] == '-' || str[0] == '+'))
		return(true);
	if (str[0] == '-' || str[0] == '+')
		count = 1;
	else
		count = 0;
	while (count < str.length())
	{
		while (isDigit(str[count]))
			count++;
		if (str[count] == '.' && checkPrecision == false)
			checkPrecision = true;
		else if (!((str[count] == 'f' && count + 1 == str.length()) || count == str.length()))
		{
			std::cout << str[count] << "|\n";
			return (true);
		}
		count++;
	}
	return (false);
}

Conversion::Conversion(char *str) : string(str), infValue(false)
{
	if (checkString(string, &infValue))
		throw (NoConvertString());
}

Conversion::~Conversion() {}

Conversion::Conversion(const Conversion& tmp) : string(tmp.string), infValue(tmp.infValue) {}

Conversion& Conversion::operator=(const Conversion& tmp)
{
	if (this == &tmp)
		return (*this);
	string = tmp.string;
	infValue = tmp.infValue;
	return (*this);
}
char Conversion::getChar() const
{
	return (static_cast<char>(atof(string.c_str())));
}

int Conversion::getInt() const
{
	return (static_cast<int>(atof(string.c_str())));
}

float Conversion::getFloat() const
{
	return (static_cast<float>(atof(string.c_str())));
}


double Conversion::getDouble() const
{
	return (static_cast<double>(atof(string.c_str())));
}

void Conversion::printRezult() const
{
	double tmp = atof(string.c_str());
	if (infValue)
		std::cout << "char: impossible\n";
	else if (tmp < 32 || tmp > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << this->getChar() << std::endl;
	if (tmp < INT32_MIN || tmp > INT32_MAX || infValue)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << this->getInt() << std::endl;
	if (tmp < 1.17549e-038 || tmp > 3.40282e+038)
		std::cout << "float: impossible\n";
	else if (infValue)
		this->printrInfValue('f');
	else if (static_cast<float>(this->getInt()) == this->getFloat())
		std::cout << "float: " << this->getFloat() << ".0f" << std::endl;
	else
		std::cout << "float: " << std::setprecision(7) << this->getFloat() << "f" << std::endl;
	if (tmp < 2.22507e-308 || tmp > 1.79769e+308)
		std::cout << "float: double\n";
	else if (infValue)
		this->printrInfValue('d');
	else if (static_cast<float>(this->getInt()) == this->getFloat())
		std::cout << "float: " << this->getDouble() << ".0" << std::endl;
	else
		std::cout << "double: " << std::setprecision(15) << this->getDouble() << std::endl;
}

const char* Conversion::NoConvertString::what() const throw()
{
	return ("This string not convert");
}

void Conversion::printrInfValue(char c) const
{
	if (string == "-inf" || string == "+inf" || string == "nan")
	{
		if (c == 'f')
			std::cout << "float: " << string + "f" << std::endl;
		else
			std::cout << "double: " << string << std::endl;
	}
	if (string == "-inff" || string == "+inff" || string == "nanf")
	{
		if (c == 'f')
			std::cout << "float: " << string << std::endl;
		else
		{
			std::string tmp(string);
			tmp.pop_back();
			std::cout << "double: " << tmp << std::endl;
		}
	}
}