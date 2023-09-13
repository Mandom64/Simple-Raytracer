#include <stdio.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#define PUT_NEW_LINE(num) \
    for (int i = 0; i < (num); i++) \
        fprintf(stderr, "\n")

int hit_sphere(vec3 center, double radius, const ray *r)
{
    vec3 oc = sub_vec3(r->orig, center);
    double a = dot(r->dir, r->dir);
    double b = 2.0 * dot(oc, r->dir);
    double c = dot(oc, oc) - radius*radius;
    double discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

vec3 ray_color(const ray *r)
{
    if(hit_sphere(Vec3(0, 0, -1), 0.5, r))
        return Vec3(1, 0, 0);

    vec3 unit_direction = unit_vector(r->dir);
    double a = 0.5 * (unit_direction.e2 + 1.0);
    return add_vec3(tmul_vec3(color(1.0, 1.0, 1.0), (1.0-a)), 
        tmul_vec3(color(0.5, 0.7, 1.0), a));  
}

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
        vec3 camera_center = Vec3(0, 0, 0);

        vec3 viewport_u = Vec3(viewport_width, 0, 0);
        vec3 viewport_v = Vec3(0, -viewport_height, 0);

        vec3 pixel_delta_u = div_vec3(viewport_u, image_width);
        vec3 pixel_delta_v = div_vec3(viewport_v, image_height); 

        vec3 viewport_upper_left = sub_vec3(sub_vec3(sub_vec3(camera_center, Vec3(0, 0, focal_length)), 
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
                r.orig = camera_center;
                r.dir = ray_direction;
                vec3 pixel_color = ray_color(&r);
                //print_ray(&r);
                write_color(pixel_color);
            }
        }
        fprintf(stderr, "\ndone"); 
        PUT_NEW_LINE(3);
        return 0;
}   