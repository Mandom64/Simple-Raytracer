#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>
#include "vec3.h"

void write_color(vec3 pixel_color)
{
    printf("%d %d %d\n", 
    (int)(255.999 * pixel_color.e1), 
    (int)(255.999 * pixel_color.e2), 
    (int)(255.999 * pixel_color.e3));
}

#endif // COLOR.H guard
