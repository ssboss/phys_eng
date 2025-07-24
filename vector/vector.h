#include <iostream>

namespace Physics{

    class Vector {
    public:
        Vector(double x, double y, double z);
        ~Vector();
        friend Vector operator+(Vector const& vect1, Vector const& vect2);
        friend Vector operator-(Vector const& vect1, Vector const& vect2);
        friend Vector operator*(double x, Vector const& vect);
        friend Vector operator/(double x, Vector const& vect);

        Vector& operator+=(Vector& const vect);
        Vector& operator-=(Vector& const vect);
        float magnitude();
        Vector& norm(Vector& const vect);

        
    private:
        double x, y, z;
    };

}