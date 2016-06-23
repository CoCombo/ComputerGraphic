#include "perspectiveCamera.h"
#define PI 3.1415926

perCamera::perCamera()
{}

perCamera::perCamera(Vector3 _eye, Vector3 _front, Vector3 _refUp, double _fov): eye(_eye), 
																				 front(_front), 
																	             refUp(_refUp),
																	             fov(_fov)
{
	right    = front.crossMul(refUp);
	up       = right.crossMul(front);
	fovScale = std::tan(fov * (PI / 180) * 0.5f) * 2;
}

perCamera::~perCamera()
{}

Ray perCamera::generateRay(double x, double y)
{
	Vector3 r   = right * ((x - 0.5f) * fovScale);
	Vector3 u   = up * ((y - 0.5f) * fovScale);
	Vector3 tmp = front + r + u;
	tmp.normalize();
	return Ray(eye, tmp);
}

