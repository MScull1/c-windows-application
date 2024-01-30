#ifndef MYMATH_HEADER_
#define MYMATH_HEADER_

typedef struct Vector2
{
    float x;
    float y;
} Vector2;

const extern Vector2 mymath_vector2_zero;

Vector2 mymath_vector2_add(Vector2* vec1, Vector2* vec2);
Vector2 mymath_vector2_add(Vector2* vec1, Vector2* vec2);
Vector2 mymath_vector2_scalar(Vector2* vec, float factor);
Vector2 mymath_vector2_normalize(Vector2* vec);

float mymath_vector2_magnitude(Vector2* vec);
float mymath_vector2_dot(Vector2* vec1, Vector2* vec2);
float mymath_vector2_distance(Vector2* vec1, Vector2* vec2);

#endif