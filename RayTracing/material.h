#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include "color.h"
#include "vector3.h"
#include "ray.h"

class Material
{
public:
	Material();
	Material(double _ref);
	~Material();
	virtual Color sample(const Ray &_ray, const Vector3 &_position, const Vector3 &_normal) = 0;//pure function
	double getRef();
	void   setRef(double tmpRef);
protected:
	double reflectiveness;
private:
};
#endif // !_MATERIAL_H_
