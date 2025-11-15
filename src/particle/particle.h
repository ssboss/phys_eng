#pragma once

#include "vector/vector3D.h"

namespace Physics{
    class Particle{
        public:
            Particle(Vector3D present_pos, Vector3D force, double mass);
            ~Particle();
            Vector3D getCurrPos(); // getters for seeing values 
            Vector3D getPrevPos();
            Vector3D getForce();
            void modPos(Vector3D pos); // setters for inc/dec of particle values
            void modForce(Vector3D force);
            
        private:
            Vector3D curr_pos;
            Vector3D prev_pos;
            Vector3D force;
            double mass;
    };
}