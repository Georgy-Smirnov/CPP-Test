#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed
{
public:
	void setRawBits(const int raw);
	int	getRawBits(void);

	Fixed();
	~Fixed();
	Fixed(const Fixed &tmp);
	Fixed(const int tmp);
	Fixed(const float tmp);

	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed &operator =(const Fixed &tmp);
	friend std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

	bool	operator >(const Fixed &tmp) const;
	bool	operator <(const Fixed &tmp) const;
	bool	operator >=(const Fixed &tmp) const;
	bool	operator <=(const Fixed &tmp) const;
	bool	operator ==(const Fixed &tmp) const;
	bool	operator !=(const Fixed &tmp) const;

	Fixed	operator +(const Fixed &tmp) const;
	Fixed	operator -(const Fixed &tmp) const;
	Fixed	operator *(const Fixed &tmp) const;
	Fixed	operator /(const Fixed &tmp) const;

	Fixed	&operator ++(void);
	Fixed	&operator --(void);
	Fixed	operator ++(int);
	Fixed	operator --(int);

	static Fixed	&max(Fixed &s1, Fixed &s2);
	static Fixed	&min(Fixed &s1, Fixed &s2);
	static const Fixed	&max(const Fixed &s1, const Fixed &s2);
	static const Fixed	&min(const Fixed &s1, const Fixed &s2);
private:
	int					_value;
	static const int	_fractional = 8;
};

#endif