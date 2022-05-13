#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed
{
public:
	void setRawBits(int const raw);
	int	getRawBits(void);
	Fixed();
	~Fixed();
	Fixed(const Fixed &tmp);
	Fixed(const int tmp);
	Fixed(const float tmp);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed &operator =(const Fixed &tmp);
private:
	int					_value;
	static const int	_fractional = 8;
};
	std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

#endif