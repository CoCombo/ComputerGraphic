#include "phongmaterial.h"

PhongMaterial::PhongMaterial()
{}

PhongMaterial::PhongMaterial(const Color  &_diffuse, 
							 const Color  &_specular, 
							 const double &_shininess, 
							 double    _reflectiveness): diffuse(_diffuse),
														 specular(_specular),
														 shiniess(_shininess),
														 Material(_reflectiveness)
{}

PhongMaterial::~PhongMaterial()
{}

Color PhongMaterial::sample(Ray &ray, const Vector3 &position, const Vector3 &normal)
{
	double  nDotl = normal.dotMul(lightDir);
	Vector3 H = (lightDir - ray.getDirection()).normalize();
	double  nDoth = normal.dotMul(H);
	Color   tmpDiffuse  = diffuse.multiply(std::max(nDoth, 0.0));
	Color   tmpSpecular = specular.multiply(pow(std::max(nDoth, 0.0), shiniess));

	return lightColor.modulate(tmpDiffuse.add(tmpSpecular));
}