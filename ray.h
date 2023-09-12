#ifndef RAY_H
#define RAY_H

#include "vec3.h"
typedef struct { vec3 orig, dir;} ray;

void point_at(ray *v, double t)
{   add_vec3(v->orig, tmul_vec3(v->dir, t));}

#endif // RAY_H guard