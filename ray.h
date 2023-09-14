#ifndef RAY_H
#define RAY_H

#include "vec3.h"
typedef struct { vec3 origin, direction;} ray;

vec3 point_at(ray *r, double t)
{   return (vec3)add_vec3(r->origin, tmul_vec3(r->direction, t));}

void print_ray(ray *r) 
{	
	fprintf(stderr, "orig=[%.3f %.3f %.3f] dir=[%.3f %.3f %.3f]\n", 
		r->origin.e1, r->origin.e2, r->origin.e3, r->direction.e1, r->direction.e2, r->direction.e3);
}

#endif // RAY_H guard