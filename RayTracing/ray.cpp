#include "ray.h"
#define PI 3.1415926
//constructor
Ray::Ray() {}
Ray::Ray(Vector3 &origin_, Vector3 &direction_): origin(origin_), direction(direction_) {}
Ray::~Ray() {}
//
void Ray::setOrigin(Vector3 &tmpo)
{
	origin = tmpo;
}

void Ray::setDirection(Vector3 &tmpd)
{
	direction = tmpd;
}

Vector3 Ray::getOrigin()
{
	return origin;
}

Vector3 Ray::getDirection()
{
	return direction;
}

Vector3 Ray::getPoint(double t)
{
	return origin + direction * t;
}