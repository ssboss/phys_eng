#include "vector3D.h"
#include <cmath>

namespace Physics{
	Vector3D::Vector3D(float x1, float y1, float z1) : x(x1), y(y1), z(z1){};

	Vector3D::~Vector3D(){};

	Vector3D operator+(Vector3D const& vect1, Vector3D const& vect2){ return {vect1.x + vect2.x, vect1.y + vect2.y, vect1.z + vect2.z}; }

	Vector3D operator-(Vector3D const& vect1, Vector3D const& vect2){ return {vect1.x - vect2.x, vect1.y - vect2.y, vect1.z - vect2.z}; }

	Vector3D operator*(Vector3D const& vect2, float x){ return {vect2.x * x, vect2.y * x,vect2.z * x}; }

	Vector3D operator/(Vector3D const& vect2, float x){ return {vect2.x / x, vect2.y / x, vect2.z / x}; }

	Vector3D operator*(float x, Vector3D const& vect2){ return {vect2.x * x, vect2.y * x,vect2.z * x}; } // overloaded fxn to reflect math for my monkey brain

	Vector3D operator/(float x, Vector3D const& vect2){ return {x / vect2.x, x / vect2.y, x / vect2.z}; }

	Vector3D& Vector3D::operator+=(const Vector3D& vect){ 
		this->x += vect.x;
		this->y += vect.y;
		this->z += vect.z;
		return *this;
	}

	Vector3D& Vector3D::operator-=(const Vector3D& vect){
		this->x -= vect.x;
		this->y -= vect.y;
		this->z -= vect.z;
		return *this; 
	}

	float Vector3D::magnitude() const{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	Vector3D Vector3D::norm(const Vector3D& vect){
		return Vector3D(vect.x / vect.magnitude(), vect.y / vect.magnitude(), vect.z / vect.magnitude());
	}

	std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    	return os;
	}

	

}