#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
typedef struct { double e1, e2, e3; } vec3, point3;

inline double length_squared(vec3 v)
{   return v.e1*v.e1 + v.e2*v.e2 + v.e3*v.e3;}

inline double length(vec3 v)
{   return sqrt(length_squared(v));}

inline vec3 vadd_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 += v2.e1, v1.e2 += v2.e2, v1.e3 += v2.e3};} 

inline vec3 add_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 + v2.e1, v1.e2 + v2.e2, v1.e3 + v2.e3};} 

inline vec3 sub_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 - v2.e1, v1.e2 - v2.e2, v1.e3 - v2.e3};}

inline vec3 mul_vec3(vec3 v1, vec3 v2)
{   return (vec3){v1.e1 * v2.e1, v1.e2 * v2.e2, v1.e3 * v2.e3};}

inline vec3 not_vec3(vec3 v)
{   return (vec3){-v.e1, -v.e2, -v.e3};}

inline vec3 tmul_vec3(vec3 v, const double t)
{   return (vec3){v.e1 *= t, v.e2 *= t, v.e3 *= t};}

inline vec3 tdiv_vec3(vec3 v, const double t)
{   return (vec3){v.e1 /= 1 / t, v.e2 /= 1 / t, v.e3 /= 1 / t};}

inline vec3 div_vec3(vec3 v, const double t)
{   return (vec3){(1/t)*v.e1, (1/t)*v.e2, (1/t)*v.e3};}

inline vec3 unit_vector(vec3 v)
{   return (vec3){v.e1/length(v), v.e2/length(v), v.e3/length(v)};}

inline double dot(vec3 v1, vec3 v2)
{   return v1.e1 * v2.e1 
         + v1.e2 * v2.e2 
         + v1.e3 * v2.e3;
}

inline vec3 cross(vec3 v1, vec3 v2)
{   return (vec3){v1.e2 * v2.e3 - v1.e3 * v2.e2, 
                  v1.e3 * v2.e1 - v1.e1 * v2.e3,
                  v1.e1 * v2.e2 - v1.e2 * v2.e1};
}

void print_vec3(vec3 v)
{   fprintf(stderr, "%6.3f %6.3f %6.3f\n", v.e1, v.e2, v.e3);}

#endif // VECTOR_H guard 