#ifndef _RAY_H_
#define _RAY_H_
#include "vector3.h"
#define PI 3.141592653

class Ray
{
public:
	//constructor
	Ray();
	Ray(Vector3 &, Vector3 &);
	~Ray();
	//
	void setOrigin(Vector3 &);
	void setDirection(Vector3 &);
	Vector3 getOrigin();
	Vector3 getDirection();
	Vector3 getPoint(double);
private:
	Vector3 origin;
	Vector3 direction;
};
#endif // !_RAY_H_
