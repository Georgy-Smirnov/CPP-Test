#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a1;
	Point b1;
	Point c1;
	Point point1;
	if (bsp(a1, b1, c1, point1))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	Point a2(32.12, 14.15);
	Point b2(-12.0, 0.234);
	Point c2(1, -36.12);
	Point point2(1.12, 0);
	if (bsp(a2, b2, c2, point2))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;

	Point a3;
	Point b3(3, 0);
	Point c3(0, 4);
	Point point3(0, 1.5);
	if (bsp(a3, b3, c3, point3))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
}