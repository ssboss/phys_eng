#pragma once

#include <iostream>

namespace Physics{

    struct Vector3D {
        Vector3D(float x, float y, float z);
        ~Vector3D();
        friend Vector3D operator+(Vector3D const& vect1, Vector3D const& vect2);
        friend Vector3D operator-(Vector3D const& vect1, Vector3D const& vect2);
        friend Vector3D operator*(Vector3D const& vect, float x);
        friend Vector3D operator/(Vector3D const& vect, float x);
        friend Vector3D operator*(float x, Vector3D const& vect);
        friend Vector3D operator/(float x, Vector3D const& vect);
        friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);

        Vector3D& operator+=(const Vector3D& vect);
        Vector3D& operator-=(const Vector3D& vect);
        float magnitude() const;
        Vector3D norm(const Vector3D& vect);

        float x,y,z;
    };

}