#include "Fixed.hpp"

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::getRawBits(void)
{
	return (this->_value);
}

Fixed::Fixed()
{
	_value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &tmp) : _value(tmp._value)
{
}

Fixed::Fixed(const int tmp) : _value(tmp << 8)
{
}

Fixed::Fixed(const float tmp)
{
	_value = roundf(tmp * 256);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / 256);
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractional);
}

Fixed	&Fixed::operator =(const Fixed &tmp)
{
	this->_value = tmp._value;
	return (*this); 
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator >(const Fixed &tmp) const
{
	return (_value > tmp._value);
}

bool	Fixed::operator <(const Fixed &tmp) const
{
	return (_value < tmp._value);
}

bool	Fixed::operator >=(const Fixed &tmp) const
{
	return (_value >= tmp._value);
}

bool	Fixed::operator <=(const Fixed &tmp) const
{
	return (_value <= tmp._value);
}

bool	Fixed::operator ==(const Fixed &tmp) const
{
	return (_value == tmp._value);
}

bool	Fixed::operator !=(const Fixed &tmp) const
{
	return (_value != tmp._value);
}

Fixed	Fixed::operator +(const Fixed &tmp) const
{
	Fixed rez;

	rez.setRawBits(_value + tmp._value);
	return (rez);
}

Fixed	Fixed::operator -(const Fixed &tmp) const
{
	Fixed rez;

	rez.setRawBits(_value - tmp._value);
	return (rez);
}

Fixed	Fixed::operator *(const Fixed &tmp) const
{
	Fixed rez;

	rez.setRawBits(_value * tmp._value / 256);
	return (rez);
}

Fixed	Fixed::operator /(const Fixed &tmp) const
{
	Fixed rez;

	rez.setRawBits(_value / tmp._value * 256);
	return (rez);
}

Fixed&	Fixed::operator ++(void)
{
	_value++;
	return (*this);
}

Fixed&	Fixed::operator --(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator ++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator --(int)
{
	Fixed tmp(_value);
	--(*this);
	return (tmp);
}

Fixed	&Fixed::max(Fixed &s1, Fixed &s2)
{
	if (s1 > s2)
		return (s1);
	return (s2);
}

Fixed	&Fixed::min(Fixed &s1, Fixed &s2)
{
	if (s1 < s2)
		return (s1);
	return (s2);
}

const Fixed	&Fixed::max(const Fixed &s1, const Fixed &s2)
{
	if (s1 > s2)
		return (s1);
	return (s2);
}

const Fixed	&Fixed::min(const Fixed &s1, const Fixed &s2)
{
	if (s1 < s2)
		return (s1);
	return (s2);
}
