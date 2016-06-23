#include "color.h"
Color::Color()
{}

Color::Color(double _r, double _g, double _b): r(_r), g(_g), b(_b)
{}

Color::~Color()
{}

Color Color::add(const Color &tmpColor)
{
	return Color(r + tmpColor.r, g + tmpColor.g, b + tmpColor.b);
}

Color Color::multiply(double tmpV) const
{
	return Color(r * tmpV, g * tmpV, b * tmpV);
}

Color Color::modulate(const Color &tmpColor) const
{
	return Color(r * tmpColor.r, g * tmpColor.g, b * tmpColor.b);
}

void Color::saturate()
{
	r = r > 1.0 ? 1.0 : r;
	g = g > 1.0 ? 1.0 : g;
	b = b > 1.0 ? 1.0 : b;
}

void Color::show() const
{
	std::cout << "r: " << r
		      << "g: " << g
		      << "b: " << b
		      << std::endl;
}