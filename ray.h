#ifndef RAY_H
#define RAY_H

#include "vec3.h"
typedef struct { vec3 orig, dir;} ray;

void point_at(ray *v, double t)
{   add_vec3(v->orig, tmul_vec3(v->dir, t));}

void print_ray(ray *r) 
{	
	fprintf(stderr, "orig=[%.3f %.3f %.3f] dir=[%.3f %.3f %.3f]\n", 
		r->orig.e1, r->orig.e2, r->orig.e3, r->dir.e1, r->dir.e2, r->dir.e3);
}

#endif // RAY_H guard