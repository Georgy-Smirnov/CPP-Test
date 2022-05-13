#ifndef _POINT_HPP_
# define _POINT_HPP_

#include "Fixed.hpp"

class Point
{
public:
	Point();
	~Point();
	Point(const Point &tmp);
	Point(const float x, const float y);
	Point &operator =(const Point &);
	Fixed getValueX() const;
	Fixed getValueY() const;
private:
	const Fixed _x;
	const Fixed _y;
};

std::ostream& operator <<(std::ostream &out, Point &point);

#endif