#ifndef _SPHERE_H_
#define _SPHERE_H_
#include "ray.h"
#include "intersectresult.h"
#include "phongmaterial.h"

class Sphere: public Object
{
public:
	Sphere();
	Sphere(Vector3, double);
	Sphere(Sphere &);
	~Sphere();

	void setCenter(Vector3);
	void setRadius(double);
	Vector3 getCenter();
	double  getRadius();
	Vector3 getNoraml(Vector3);
	IntersectResult isIntersect(Ray &);

	//Material *material;
private:
	Vector3 center;
	double  radius;
	double  radius2;
};
#endif // !_SPHERE_H_
