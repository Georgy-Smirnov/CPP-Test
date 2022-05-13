#include "Fixed.hpp"

Fixed	&Fixed::operator=(const Fixed &tmp)
{
	if (&tmp == this)
		return (*this);
	std::cout << "Assignation operator called" << std::endl;
	this->_value = tmp._value;
	return (*this); 
}

Fixed::Fixed(const Fixed &tmp) : _value(tmp._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int		Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}