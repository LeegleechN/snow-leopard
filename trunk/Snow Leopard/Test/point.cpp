#include "point.h"
#include "boost/lexical_cast.hpp"

int nround(double a) {
return int(a + 0.5);
}

point::point(double i, double j)
{
	x = i;
	y = j;
}

point::point()
{
	x=0;
	y=0;
}

point point::offsetRect(double ox, double oy)
{
	return point(x+ox,y+oy);
}

point point::offsetPolar(double heading, double distance)
{
	double intpart;
	heading = modf(heading,&intpart);
	heading = heading + (int)intpart % 360;
	return point(x + distance * cos(heading * 3.14159/180),y + distance * sin(heading * 3.14159/180));
}

std::string point::toString()
{
	return boost::lexical_cast<std::string>((nround(x))) + "," + boost::lexical_cast<std::string>(nround(y));
}