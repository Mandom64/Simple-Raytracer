#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef struct { double e1, e2, e3; } vec3;

double length_squared(vec3 v)
{   return v.e1*v.e1 + v.e2*v.e2 + v.e3*v.e3;}

double length(vec3 v)
{   return length_squared(v);}

vec3 vadd_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 += v2.e1, v1.e2 += v2.e2, v1.e3 += v2.e3};} 

vec3 add_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 + v2.e1, v1.e2 + v2.e2, v1.e3 + v2.e3};} 

vec3 sub_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 - v2.e1, v1.e2 - v2.e2, v1.e3 - v2.e3};}

vec3 mul_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 * v2.e1, v1.e2 * v2.e2, v1.e3 * v2.e3};}

vec3 not_vec3(vec3 v)
{   return (vec3){-v.e1, -v.e2, -v.e3};}

void set_vec3(vec3 *v, double x, double y, double z)
{   v->e1 = x; v->e2 = y; v->e3 = z;}

vec3 ret_vec3(double x, double y, double z)
{   vec3 v; return (vec3){v.e1 = x, v.e2 = y, v.e3 = z};}

vec3 tmul_vec3(vec3 v, const double t)
{   return (vec3){v.e1 *= t, v.e2 *= t, v.e3 *= t};}

vec3 tdiv_vec3(vec3 v, const double t)
{   return (vec3){v.e1 /= 1 / t, v.e2 /= 1 / t, v.e3 /= 1 / t};}

vec3 div_vec3(vec3 v, const double t)
{   return (vec3){(1/t)*v.e1, (1/t)*v.e2, (1/t)*v.e3};}

vec3 unit_vector(vec3 v)
{   return (vec3){ v.e1 / length(v), v.e2 / length(v), v.e3 / length(v)};}

double dot(vec3 v1, vec3 v2)
{   return v1.e1 * v2.e1 
         + v1.e2 * v2.e2 
         + v1.e3 * v2.e3;
}

vec3 cross(vec3 v1, vec3 v2)
{   return (vec3){v1.e2 * v2.e3 - v1.e3 * v2.e2, 
                  v1.e3 * v2.e1 - v1.e1 * v2.e3,
                  v1.e1 * v2.e2 - v1.e2 * v2.e1};
}

void print_vec3(vec3 v)
{   printf("%.3f %.3f %.3f\n", v.e1, v.e2, v.e3);}

#endif // VECTOR_H guard 