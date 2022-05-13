#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed aX = Fixed(a.getValueX());
	Fixed aY = Fixed(a.getValueY());
	Fixed bX = Fixed(b.getValueX());
	Fixed bY = Fixed(b.getValueY());
	Fixed cX = Fixed(c.getValueX());
	Fixed cY = Fixed(c.getValueY());
	Fixed pointX = Fixed(point.getValueX());
	Fixed pointY = Fixed(point.getValueY());
	
	Fixed reza = Fixed((aX - pointX) * (bY - aY) - (bX - aX) * (aY - pointY));
	Fixed rezb = Fixed((bX - pointX) * (cY - bY) - (cX - bX) * (bY - pointY));
	Fixed rezc = Fixed((cX - pointX) * (aY - cY) - (aX - cX) * (cY - pointY));
	return ((reza > 0 && rezb > 0 && rezc > 0) || (reza < 0 && rezb < 0 && rezc < 0));
}