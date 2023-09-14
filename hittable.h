#ifndef HITTABLE_H
#define HITTABLE_H
#include "ray.h"
#include "vec3.h"

typedef struct{
	vec3 point3;
	vec3 normal;
	double t;
	int front_face;
}hit_record;

int hit(ray *r, double ray_tmin, double ray_tmax, hit_record *rec);
void set_face_normal(ray *r, vec3 *outward_normal);
#endif