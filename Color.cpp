#include "Color.h"

Color::Color(unsigned int r, unsigned int g, unsigned int b)
{
	R = r, G = g, B = b;
}

ofstream& operator<< (std::ofstream &out, const Color &color)
{
	out << color.R << " " << color.G << " " << color.B;
	return out;
}