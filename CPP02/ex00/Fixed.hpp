#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &tmp);
	Fixed &operator =(const Fixed &tmp);
	void setRawBits(int const raw);
	int	getRawBits(void);
private:
	int					_value;
	static const int	_fractional = 8;
};

#endif