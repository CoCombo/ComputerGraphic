//#include "stdafx.h"
#include "vector3.h"

//construct function
Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}
Vector3::Vector3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
Vector3::Vector3(const Vector3 &vec3) : x(vec3.x), y(vec3.y), z(vec3.z) {}
Vector3::~Vector3() {}

//dotmul
double Vector3::dotMul(const Vector3 &tmpv) const
{
	return x * tmpv.x + y * tmpv.y + z * tmpv.z;
}
//crossmul
Vector3 Vector3::crossMul(const Vector3 &tmpv) const
{
	Vector3 normalv(0.0, 0.0, 0.0);
	normalv.x = ((y * tmpv.z) - (z * tmpv.y));
	normalv.y = ((z * tmpv.x) - (x * tmpv.z));
	normalv.z = ((x * tmpv.y) - (y * tmpv.x));

	return normalv;
}
//normalize
Vector3 & Vector3::normalize()
{
	double len = length();

	if (len > 0)
	{
		*this /= len;
	}
	return *this;
}

//output method
std::ostream & operator <<(std::ostream &os, const Vector3 &tmpv)
{
	os << "[" << tmpv.x << "," << tmpv.y << "," << tmpv.z << "]" << std::endl;
	return os;
}