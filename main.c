#include <stdio.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"

#define PUT_NEW_LINE(num) \
    for (int i = 0; i < (num); i++) \
        fprintf(stderr, "\n")

vec3 ray_color(const ray *r)
{
        vec3 unit_direction = unit_vector(r->dir);
        double t = 0.5 * (unit_direction.e2 + 1.0);
        vec3 c1, c2;
        set_vec3(&c1, 1.0, 1.0, 1.0);
        set_vec3(&c2, 0.5, 0.7, 1.0);
        return add_vec3(tmul_vec3(c1, (1.0-t)), tmul_vec3(c2, t));
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
        vec3 camera_center = ret_vec3(0, 0, 0);

        vec3 viewport_u;
        vec3 viewport_v;
        set_vec3(&viewport_u, viewport_width, 0, 0);
        set_vec3(&viewport_v, 0, -viewport_height, 0);

        vec3 pixel_delta_u = viewport_u;
        vec3 pixel_delta_v = viewport_v; 
        pixel_delta_u = div_vec3(pixel_delta_u, image_width);
        pixel_delta_v = div_vec3(pixel_delta_v, image_height);

        vec3 viewport_upper_left;
        sub_vec3(camera_center, ret_vec3(0, 0, focal_length));
        sub_vec3(div_vec3(viewport_u, 2), div_vec3(viewport_v, 2));

        viewport_upper_left = sub_vec3(sub_vec3(camera_center, ret_vec3(0, 0, focal_length)), 
            sub_vec3(div_vec3(viewport_u, 2), div_vec3(viewport_v, 2)));
        //print_vec3(viewport_upper_left);

        vec3 pixel00_loc = add_vec3(viewport_upper_left, 
            tmul_vec3(add_vec3(pixel_delta_u, pixel_delta_v), 0.5));
        //print_vec3(pixel00_loc);

        vec3 origin;
        set_vec3(&origin, 0, 0, 0);
        vec3 horizontal;
        set_vec3(&horizontal, viewport_width, 0, 0);
        vec3 vertical;
        set_vec3(&vertical, 0, viewport_height, 0);
        vec3 lower_left_corner, llc1, llc2;
        llc1 = div_vec3(horizontal, 2);
        llc2 = sub_vec3(origin, llc1);
        llc1 = div_vec3(vertical, 2);
        llc1 = sub_vec3(llc1, (vec3){0, 0, focal_length});
        lower_left_corner = sub_vec3(llc2, llc1);

        // render 
        printf("P3\n%d %d\n255\n", image_width, image_height);
        for(int j = image_height-1; j >= 0; j--)
        {
            fprintf(stderr, "\rscanlines left: %d", j); fflush(stderr);
            for(int i = 0; i < image_width; i++)
            {
                // double u = (double)i / (image_width-1);
                // double v = (double)j / (image_height-1);
                // ray r;
                // r.orig = origin;
                // vec3 a, b;
                // a = add_vec3(tmul_vec3(horizontal, u), tmul_vec3(vertical, v));
                // b = add_vec3(lower_left_corner, a);
                // a = sub_vec3(b, origin);
                // r.dir = a;
                // vec3 pixel_color = ray_color(&r);
                // write_color(pixel_color);
                vec3 pixel_center = add_vec3(pixel00_loc, 
                    add_vec3(tmul_vec3(pixel_delta_u, i), tmul_vec3(pixel_delta_v, j)));
                vec3 ray_direction = sub_vec3(pixel_center, camera_center);
                ray r;
                r.orig = camera_center;
                r.dir = ray_direction;
                vec3 pixel_color = ray_color(&r);
                write_color(pixel_color);
            }
        }
        fprintf(stderr, "\ndone\n"); 
        PUT_NEW_LINE(3);
        
}   