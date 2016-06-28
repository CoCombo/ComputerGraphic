#ifndef _INTERSECTRESULT_H_
#define _INTERSECTRESULT_H_
#include "material.h"
class Object;

struct IntersectResult
{
	double  distance;
	bool    isHit = false;
	Vector3 position;
	Vector3 normal;
	Object  *object = nullptr;
	static inline IntersectResult noHit() { return IntersectResult(); }
};

class Object
{
public:
	Object();
	~Object();
	Material *material;
	virtual IntersectResult isIntersect(Ray &tmpRay) = 0;
};


#endif // !_INTERSECTRESULT_H_
