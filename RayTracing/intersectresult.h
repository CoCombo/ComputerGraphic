#ifndef _INTERSECTRESULT_H_
#define _INTERSECTRESULT_H_
#include "vector3.h"

struct IntersectResult
{
	double distance;
	bool isHit = false;
	Vector3 position;
	Vector3 normal;
	static inline IntersectResult noHit() { return IntersectResult(); }
	//Plane *object = nullptr;
};
#endif // !_INTERSECTRESULT_H_
