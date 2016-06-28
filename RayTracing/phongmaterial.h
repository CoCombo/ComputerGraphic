#ifndef _PHONGMATERIAL_H_
#define _PHONGMATERIAL_H_
#include "material.h"
#include <algorithm>
#include <cmath>

static Vector3 lightDir   = Vector3(1, 1, 1).normalize();
static Color   lightColor = Color::white();

class PhongMaterial : public Material
{
public:
	PhongMaterial();
	PhongMaterial(const Color &_diffuse, const Color &_specular, const double &shiniess, double _reflectiveness = 0.0);
	~PhongMaterial();

	virtual Color sample(Ray &ray, const Vector3 &position, const Vector3 &normal);

private:
	Color  diffuse; //漫反射颜色
	Color  specular;//高光颜色
	double shiniess;
};
#endif // !_PHONGMATERIAL_H_
