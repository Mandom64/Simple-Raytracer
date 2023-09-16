#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#include <stdlib.h>
#include "vec3.h"
#include "hittable.h"
#include "sphere.h"

typedef struct{
	sphere *spheres;
	int num_spheres;
} hittableList;

void init_hittableList(hittableList *list) 
{
	list = malloc(sizeof(hittableList));
	list->spheres = NULL;
	list->num_spheres = 0; 
}

void add_sphere(hittableList *list, sphere s)
{
	if(!list->num_spheres) {
		list->spheres = malloc(sizeof(sphere)*1);
		list->spheres[list->num_spheres] = s;
		list->num_spheres++;
	}
	else {
		list->spheres = realloc(list->spheres, 
			sizeof(sphere) * (list->num_spheres+1));
		list->spheres[list->num_spheres] = s;
		list->num_spheres++;	
	}
}

void del_hittableList(hittableList list) 
{
	free(list.spheres);
	list.num_spheres = 0;
}

void print_hittableList(hittableList *list)
{
	int i;

	for(i = 0; i < list->num_spheres; i++) {
		fprintf(stderr, "\nsphere %d :\n", i);
		fprintf(stderr, "center : %.3f %.3f %.3f\n", list->spheres[i].center.e1, 
			list->spheres[i].center.e2, list->spheres[i].center.e3); 
		fprintf(stderr, "radius: %f\n", list->spheres[i].radius);
	}
}


#endif