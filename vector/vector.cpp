#include "vector.h"
#include <cmath>

namespace Physics{
	Vector::Vector(double x1, double y1, double z1) : x(x1), y(y1), z(z1){};

	Vector::~Vector(){};

	Vector operator+(Vector const& vect1, Vector const& vect2){ return {Vector(vect1.x + vect2.x, vect1.y + vect2.y, vect1.z + vect2.z)}; }

	Vector operator-(Vector const& vect1, Vector const& vect2){ return {Vector(vect1.x - vect2.x, vect1.y - vect2.y, vect1.z - vect2.z)}; }

	Vector operator*(double x, Vector const& vect2){ return {Vector(x * vect2.x, x * vect2.y, x * vect2.z)}; }

	Vector operator/(double x, Vector const& vect2){ return {Vector(vect2.x / x, vect2.y / x, vect2.z / x)}; }

	Vector& Vector::operator+=(Vector& const vect){ 
		Vector res {Vector(x + vect.x, y + vect.y, z + vect.z) };
		return res;
	}

	Vector& Vector::operator-=(Vector& const vect){ 
		Vector res {Vector(x - vect.x, y - vect.y, z - vect.z) };
		return res;
	}

	float Vector::magnitude(){
		return sqrt((x * x) + (y * y) + (z * z));
	}

	Vector& Vector::norm(Vector& const vect){
		Vector normalized{Vector(vect.x / vect.magnitude(), vect.y / vect.magnitude(), vect.z / vect.magnitude())};
		return normalized;
	}

}