#include "sphere.h"
#include <cmath>

Sphere::Sphere()
{}

Sphere::Sphere(Vector3 _center, double _radius): center(_center), 
											     radius(_radius), 
						                         radius2(_radius * _radius)
{}

Sphere::Sphere(Sphere &tmpSphere): center(tmpSphere.center), 
								   radius(tmpSphere.radius), 
	                               radius2(tmpSphere.radius * tmpSphere.radius)
{}

Sphere::~Sphere()
{}

void Sphere::setCenter(Vector3 tmpCenter)
{
	center = tmpCenter;
}

void Sphere::setRadius(double tmpRadius)
{
	radius = tmpRadius;
}

Vector3 Sphere::getCenter()
{
	return center;
}

double Sphere::getRadius()
{
	return radius;
}

Vector3 Sphere::getNoraml(Vector3 tmpPoint)
{
	return tmpPoint - center;
}

IntersectResult Sphere::isIntersect(Ray &tmpRay)
{
	IntersectResult result = IntersectResult::noHit();
	//radical formula 
	Vector3 v = tmpRay.getOrigin() - center;
	double dDotv = tmpRay.getDirection().dotMul(v);
	double vr = v.dotMul(v) - radius2;

	if (dDotv <= 0)
	{
		double underSqrt = dDotv * dDotv - vr;
		if (underSqrt >= 0)
		{
			result.isHit = true;
			result.object = this;
			result.distance = -dDotv - std::sqrt(underSqrt);
			result.position = tmpRay.getPoint(result.distance);
			result.normal = getNoraml(result.position);
			result.normal.normalize();
		}
	}
	return result;
}