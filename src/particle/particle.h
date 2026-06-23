#pragma once

#include "vector/vector3D.h"

// custom particle object class

namespace Physics{
    class Particle{
        public:
            Particle(Vector3D present_pos, Vector3D force, float mass);
            ~Particle();
            Vector3D getCurrPos(); // getters for seeing values 
            Vector3D getPrevPos();
            Vector3D getForce();
            Vector3D getAccel();
            void modCurrPos(Vector3D pos); // setters for inc/dec of particle values
            void modPrevPos(Vector3D pos);
            void modForce(Vector3D force);
            
        private:
            Vector3D curr_pos;
            Vector3D prev_pos;
            Vector3D force;
            float mass;
    };
}