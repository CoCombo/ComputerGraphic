#ifndef _COLOR_H_
#define _COLOR_H_
#include <iostream>

class Color
{
public:
	double r;
	double g;
	double b;

	Color();
	Color(double, double, double);
	~Color();

	Color add(const Color &);
	Color multiply(double)        const;
	Color modulate(const Color &) const;//颜色调制，
	void  saturate();                   //使饱和
	void  show()                  const;

	static Color black() { return Color(0, 0, 0); }
	static Color white() { return Color(1, 1, 1); }
	static Color red()   { return Color(1, 0, 0); }
	static Color green() { return Color(0, 1, 0); }
	static Color blue()  { return Color(0, 0, 1); }
	
};
#endif // !_COLOR_H_
