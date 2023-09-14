#ifndef SPHERE_H
#define SPHERE_H
#include <stdbool.h>
#include "hittable.h"
#include "vec3.h"

typedef struct {
	point3 center;
	double radius;
}sphere;

int hit_sphere(sphere *s, ray *r, double ray_tmin, double ray_tmax, 
	double radius, vec3 center, hit_record *rec)
{
	vec3 oc = sub_vec3(r->origin, s->center);
	double a = length_squared(r->direction);
	double half_b = dot(oc, r->direction);
	double c = length_squared(oc) - radius*radius;

	double discriminant = half_b*half_b - a*c;
	if(discriminant < 0)
		return 0;
	double sqrtd = sqrt(discriminant);

	double root = (-half_b - sqrtd) / a;
	if(root <= ray_tmin || ray_tmax <=root) {
		root = 	(-half_b + sqrtd) / a;
		if(root <= ray_tmin || ray_tmax <= root)
			return false;
	}
	rec->t = root;
	rec->point3 = point_at(r, rec->t);
	rec->normal = tdiv_vec3((sub_vec3(rec->point3, center)), radius);

	
}

#endif