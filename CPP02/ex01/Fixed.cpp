#include "Fixed.hpp"

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

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &tmp) : _value(tmp._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int tmp) : _value(tmp << 8)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float tmp)
{
	_value = roundf(tmp * 256);
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / 256);
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractional);
}

Fixed	&Fixed::operator=(const Fixed &tmp)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = tmp._value;
	return (*this); 
}

std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

