#include "union.h"

Union::Union()
{}

Union::~Union()
{}

void Union::addObject(Object *tmpObject) 
{
	object.push_back(tmpObject);
}

IntersectResult Union::isIntersect(Ray &ray)
{
	const double infinity = 1e30;
	double miniDistance = infinity;
	IntersectResult miniResult = IntersectResult::noHit();
	std::size_t objectCount = object.size();

	for (std::size_t i = 0; i < objectCount; i++)
	{
		IntersectResult result = object[i]->isIntersect(ray);
		if(result.object && result.distance < miniDistance)
		{
			miniDistance = result.distance;
			miniResult = result;
		}
	}
	return miniResult;
}