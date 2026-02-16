#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class Camera {
public:
    Camera() {
        // Standard 16:9 setup
        float aspect_ratio = 16.0 / 9.0;
        float viewport_height = 2.0;
        float viewport_width = aspect_ratio * viewport_height;
        float focal_length = 1.0;

        // Position of the camera in 3D space
        origin[0] = 0; origin[1] = 0; origin[2] = 0;
        
        // Define the screen "rectangle" in front of the camera
        horizontal[0] = viewport_width; horizontal[1] = 0; horizontal[2] = 0;
        vertical[0] = 0; vertical[1] = viewport_height; vertical[2] = 0;
        
        // Find the bottom-left corner of the "screen"
        lower_left_corner[0] = origin[0] - horizontal[0]/2 - vertical[0]/2;
        lower_left_corner[1] = origin[1] - horizontal[1]/2 - vertical[1]/2;
        lower_left_corner[2] = origin[2] - horizontal[2]/2 - focal_length;
    }

    // u and v are pixel percentages (0.0 to 1.0)
    ray get_ray(float u, float v) const {
        return ray(
            origin[0], origin[1], origin[2],
            lower_left_corner[0] + u*horizontal[0] + v*vertical[0] - origin[0],
            lower_left_corner[1] + u*horizontal[1] + v*vertical[1] - origin[1],
            lower_left_corner[2] + u*horizontal[2] + v*vertical[2] - origin[2]
        );
    }

private:
    float origin[3];
    float lower_left_corner[3];
    float horizontal[3];
    float vertical[3];
};

#endif
