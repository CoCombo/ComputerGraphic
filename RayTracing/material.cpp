#include "material.h"
Material::Material()
{}

Material::Material(double _ref): reflectiveness(_ref)
{}

Material::~Material()
{}

double Material::getRef()
{
	return reflectiveness;
}

void Material::setRef(double tmpRef)
{
	reflectiveness = tmpRef;
}