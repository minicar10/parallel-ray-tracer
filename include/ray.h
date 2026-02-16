#ifndef RAY_H
#define RAY_H

#include "simd_math.h" 

struct ray {
    float origin[3];
    float direction[3];

    ray(float ox, float oy, float oz, float dx, float dy, float dz) {
        origin[0] = ox; origin[1] = oy; origin[2] = oz;
        direction[0] = dx; direction[1] = dy; direction[2] = dz;
    }

    // A ray is a function: P(t) = A + tB
    // This gets the position at a certain distance 't'
    void at(float t, float& x, float& y, float& z) const {
        x = origin[0] + t * direction[0];
        y = origin[1] + t * direction[1];
        z = origin[2] + t * direction[2];
    }
};

#endif
