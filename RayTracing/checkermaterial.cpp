#include "checkermaterial.h"

CheckMaterial::CheckMaterial()
{}

CheckMaterial::CheckMaterial(double _scale, double _reflectiveness): scale(_scale), 
																	 Material(_reflectiveness)
{}

CheckMaterial::~CheckMaterial()
{}

Color CheckMaterial::sample(Ray &tmpRay, const Vector3 &position, const Vector3 &normal)
{
	double d = abs(std::floor(position.x * scale) + std::floor(position.z * scale));
	d = fmod(d, 2);
	return d < 1 ? Color::black() : Color::white();
}