#ifndef _VECTOR3_H_
#define _VECTOR3_H_
#include <iostream>
#include <cmath>
//#include "stdafx.h"

class Vector3
{
	//流对象不允许复制只能用&引用
	friend std::ostream& operator <<(std::ostream &, const Vector3 &);
public:
	Vector3();
	Vector3(double, double, double);
	Vector3(const Vector3 &);
	~Vector3();

	//operator method
	Vector3 operator +(const Vector3 &)  const;
	Vector3 operator -(const Vector3 &)  const;
	Vector3 operator *(const double  &)  const;
	Vector3& operator +=(const Vector3 &);
	Vector3& operator -=(const Vector3 &);
	Vector3& operator *=(const double  &);
	Vector3& operator /=(const double  &);

	//length of vector
	double length()             const;
	double length_2()           const;
	//dotmul, crossmul
	double  dotMul  (const Vector3 &) const;
	Vector3 crossMul(const Vector3 &) const;
	//distance
	double dist(const Vector3 &) const;
	Vector3& normalize();

public:
	double x, y, z;
};

//operator method
inline Vector3
Vector3::operator +(const Vector3 &tmpv) const
{
	return Vector3(x + tmpv.x, y + tmpv.y, z + tmpv.z);
}

inline Vector3
Vector3::operator -(const Vector3 &tmpv) const
{
	return Vector3(x - tmpv.x, y - tmpv.y, z - tmpv.z);
}

inline Vector3
Vector3::operator *(const double &num) const
{
	return Vector3(x * num, y * num, z * num);
}

inline Vector3&
Vector3::operator +=(const Vector3 &tmpv)
{
	x += tmpv.x;
	y += tmpv.y;
	z += tmpv.z;
}

inline Vector3& 
Vector3::operator -=(const Vector3 &tmpv)
{
	x -= tmpv.x;
	y -= tmpv.y;
	z -= tmpv.z;
}
inline Vector3&
Vector3::operator *=(const double &num)
{
	x *= num;
	y *= num;
	z *= num;
}
inline Vector3&
Vector3::operator /=(const double &num)
{
	x /= num;
	y /= num;
	z /= num;

	return *this;
}

//length of vector
inline double
Vector3::length() const
{
	return sqrt(x * x + y * y + z * z);
}

inline double
Vector3::length_2() const
{
	return x * x + y * y + z * z;
}

//distance
inline double
Vector3::dist(const Vector3 &tmpv) const
{
	return sqrt(this->dotMul(tmpv));
}
#endif