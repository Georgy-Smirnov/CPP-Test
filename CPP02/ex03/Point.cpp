#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
}

Point::~Point()
{
}

Fixed Point::getValueX() const
{
	return (this->_x);
}

Fixed Point::getValueY() const
{
	return (this->_y);
}

Point::Point(const Point &tmp) : _x(tmp._x), _y(tmp._y)
{
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point &Point::operator =(const Point&)
{
	return (*this);
}

std::ostream& operator <<(std::ostream &out, Point &point)
{
	out << point.getValueX();
	std::cout << "_";
	out << point.getValueY();
	return (out);
}

