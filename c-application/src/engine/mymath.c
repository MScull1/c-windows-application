#include "mymath.h"
#include <math.h>

const Vector2 mymath_vector2_zero = {0 , 0};

Vector2 mymath_vector2_add(Vector2* vec1, Vector2* vec2)
{
    Vector2 val;

    val.x = vec1->x + vec2->x;
    val.y = vec1->y + vec2->y;

    return val;
}

Vector2 mymath_vector2_scalar(Vector2* vec, float factor)
{
    Vector2 val;

    val.x = vec->x * factor;
    val.y = vec->y * factor;

    return val;
}

Vector2 mymath_vector2_normalize(Vector2* vec)
{
    Vector2 val;
    val.x = 0;
    val.y = 0;

    float magnitude = mymath_vector2_magnitude(vec);

    if (magnitude == 0) 
        return val;

    val.x = vec->x / magnitude;
    val.y = vec->y / magnitude;
    
    return val;
}

float mymath_vector2_magnitude(Vector2* vec)
{
    float val;
    
    val = sqrtf(powf(vec->x, 2) + powf(vec->y, 2));

    return val;
}

float mymath_vector2_dot(Vector2* vec1, Vector2* vec2)
{
    return vec1->x * vec2->x + vec1->y * vec2->y;
}

float mymath_vector2_distance(Vector2* vec1, Vector2* vec2)
{
    Vector2 val;

    val.x = vec2->x - vec1->x;
    val.y = vec2->y - vec1->y;

    return mymath_vector2_magnitude(&val);
}