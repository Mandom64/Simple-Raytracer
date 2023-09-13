#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include "vec3.h"

vec3 color(double e1, double e2, double e3)
{ vec3 v; return (vec3){v.e1 = e1, v.e2 = e2, v.e3 = e3};}

void write_color(vec3 pixel_color)
{
    printf("%d %d %d\n", 
    (int)(255.999 * pixel_color.e1), 
    (int)(255.999 * pixel_color.e2), 
    (int)(255.999 * pixel_color.e3));
}

#endif // COLOR.H guard
