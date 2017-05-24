// VectorNormalization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector2.h"
#include "Vector3.h"
#include <iostream>
#include <math.h>

using namespace std;

float Rad2Deg(float radians);

int _tmain(int argc, _TCHAR* argv[])
{
    Vector2* vector2D = new Vector2(5, 5);
    Vector3* vector3D = new Vector3(-5, -5, -5);

    printf("2D vector at (%.2f,%.2f)\n", vector2D->X, vector2D->Y);
    printf("3D vector at (%.2f,%.2f,%.2f)\n", vector3D->X, vector3D->Y, vector3D->Z);

    printf("Length of 2D vector: %f\n", vector2D->Length());
    printf("Length of 3D vector: %f\n", vector3D->Length());

    // Normalize vectors
    Vector2* vector2DNormalized = &vector2D->Normalize();
    Vector3* vector3DNormalized = &vector3D->Normalize();

    printf("Normalized 2D vector (%f,%f)\n",
        vector2DNormalized->X, vector2DNormalized->Y);
    printf("Normalized 3D vector (%f,%f,%f)\n",
        vector3DNormalized->X, vector3DNormalized->Y, vector3DNormalized->Z);

    // Calculate angle for the 2D vector
    float angle = atan2(vector2DNormalized->X, vector2DNormalized->Y);
    angle = Rad2Deg(angle);

    printf("(2D) Angle from X-axis: %f\n", angle);

    // Calculate spherical coordinates for the 3D vector

    // Radius
    float r = vector3DNormalized->Length();

    // Polar angle
    float theta = atan2(sqrt(pow(vector3DNormalized->X, 2)
        + pow(vector3DNormalized->Y, 2)), vector3DNormalized->Z);

    // Azimuthal angle
    float phi = atan2(vector3D->Y, vector3D->X);

    theta = Rad2Deg(theta);
    phi = Rad2Deg(phi);

    printf("(3D) Spherical coordinates: (%f,%f,%f)\n", r, theta, phi);

    system("pause");

    return 0;
}

// Converts radians to degrees
float Rad2Deg(float radians) {
    return radians*(180 / 3.141592653589793238);
}