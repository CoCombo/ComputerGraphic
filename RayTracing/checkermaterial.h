#ifndef _CHECKERMATERIAL_H_
#define _CHECKERMATERIAL_H_
#include "material.h"
#include <stdlib.h>

class CheckMaterial: public Material
{
public:
	CheckMaterial();
	CheckMaterial(double _scale, double _reflectiveness = 0);
	~CheckMaterial();

	virtual Color sample(const Ray &tmpRay, const Vector3 &position, const Vector3 &normal);
private:
	double scale;

};
#endif // !_CHECKERMATERIAL_H_
