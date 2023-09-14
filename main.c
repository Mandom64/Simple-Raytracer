#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "hittable.h"
#include "sphere.h"
#define PUT_NEW_LINE(num) \
    for (int i = 0; i < (num); i++) \
        fprintf(stderr, "\n")

// double hit_sphere(vec3 center, double radius, const ray *r)
// {
//     vec3 oc = sub_vec3(r->origin, center);
//     double a = length_squared(r->direction);
//     double half_b = dot(oc, r->direction);
//     double c = length_squared(oc) - radius*radius;
//     double discriminant = half_b*half_b - a*c;

//     if(discriminant < 0)
//         return -1.0;
//     else
//         return (-half_b - sqrt(discriminant))/a;
// }

// vec3 ray_color(ray *r)
// {
//     double t = hit_sphere((vec3){0, 0, -1}, 0.5, r);
//     if(t > 0.0) {
//         vec3 N = unit_vector(sub_vec3(point_at(r, t), (vec3){0, 0, -1}));
//         return tmul_vec3(add_vec3(N, (vec3){1, 1, 1}), 0.5);
//     }

//     vec3 unit_direction = unit_vector(r->direction);
//     double a = 0.5 * (unit_direction.e2 + 1.0);
//     return add_vec3(tmul_vec3(color(1.0, 1.0, 1.0), (1.0-a)), 
//         tmul_vec3(color(0.5, 0.7, 1.0), a));  
// }

int main()
{
        // image
        const double aspect_ratio = 16.0/9.0;
        const int image_width = 1920;
        const int image_height = (int)( image_width / aspect_ratio);

        // camera
        double viewport_height = 2.0;
        double viewport_width = aspect_ratio * viewport_height;
        double focal_length = 1.0;
        vec3 camera_center = {0, 0, 0};

        vec3 viewport_u = {viewport_width, 0, 0};
        vec3 viewport_v = {0, -viewport_height, 0};

        vec3 pixel_delta_u = div_vec3(viewport_u, image_width);
        vec3 pixel_delta_v = div_vec3(viewport_v, image_height); 

        vec3 viewport_upper_left = sub_vec3(sub_vec3(sub_vec3(camera_center, (vec3){0, 0, focal_length}), 
            div_vec3(viewport_u, 2)), div_vec3(viewport_v, 2));

        vec3 pixel00_loc = add_vec3(viewport_upper_left, 
            tmul_vec3(add_vec3(pixel_delta_u, pixel_delta_v), 0.5));

        // render 
        printf("P3\n%d %d\n255\n", image_width, image_height);
        for(int j = image_height-1; j >= 0; --j)
        {
            fprintf(stderr, "\rscanlines left: %d", j); fflush(stderr);
            for(int i = 0; i < image_width; ++i)
            {
                vec3 pixel_center = add_vec3(pixel00_loc, 
                    add_vec3(tmul_vec3(pixel_delta_u, i), tmul_vec3(pixel_delta_v, j)));
                vec3 ray_direction = sub_vec3(pixel_center, camera_center);
                ray r;
                r.origin = camera_center;
                r.direction = ray_direction;
                //vec3 pixel_color = ray_color(&r);
                //write_color(pixel_color);
            }
        }
        fprintf(stderr, "\ndone"); 
        PUT_NEW_LINE(3);
        return 0;
}   