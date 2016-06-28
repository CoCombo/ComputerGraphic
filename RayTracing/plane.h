#ifndef _PLANE_H_
#define _PLANE_H_
#include "intersectresult.h"
#include "checkermaterial.h"

class Plane: public Object
{
public:
	Plane();
	Plane(Vector3, double);
	~Plane();

	IntersectResult isIntersect(Ray &);
	//Material *material;
private:
	Vector3 normal;
	double  d;
	
};
#endif // !_PLANE_H_
