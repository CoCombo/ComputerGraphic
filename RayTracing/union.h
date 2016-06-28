#ifndef _UNION_H_
#define _UNION_H_
#include <vector>
#include <cstddef>
#include "intersectresult.h"

class Union
{
public:
	Union();
	~Union();
	void addObject(Object *tmpObject);
	IntersectResult isIntersect(Ray &ray);
private:
	std::vector<Object *> object;
};
#endif // !_UNION_H_
