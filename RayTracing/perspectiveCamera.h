#ifndef _PERSPECTIVECAMERA_H_
#define _PERSPECTIVECAMERA_H_
#include "ray.h"

class perCamera
{
public:
	perCamera();
	perCamera(Vector3, Vector3, Vector3, double);
	~perCamera();

	Ray generateRay(double, double);
private:
	Vector3 eye;
	Vector3 front;
	Vector3 refUp;
	Vector3 right;
	Vector3 up;
	double  fov;
	double  fovScale;
};
#endif
