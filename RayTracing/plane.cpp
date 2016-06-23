#include "plane.h"

Plane::Plane()
{}

Plane::Plane(Vector3 _normal, double _d): normal(_normal), d(_d)
{}

Plane::~Plane()
{}

IntersectResult Plane::isIntersect(Ray tmpRay)
{
	IntersectResult result = IntersectResult::noHit();
	double hitAngle = tmpRay.getDirection().dotMul(normal);

	if (hitAngle < 0)
	{
		result.isHit = true;
		double a = normal.dotMul(tmpRay.getOrigin() - normal * d);
		result.distance = -a / hitAngle;
		result.position = tmpRay.getPoint(result.distance);
		result.normal = normal;
	}

	return result;
}