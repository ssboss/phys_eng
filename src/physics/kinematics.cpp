#include "kinematics.h"
#include <vector>

/*
    Finished writing the object and particle classes, this is a test to try then out and test 
    1-D Kinematics before moving to 3-D implementation
*/
namespace Physics {
    void step(double dt, Physics::Particle* obj){
        Physics::Vector3D new_pos {0.0,0.0,0.0};
        new_pos = 2*obj->getCurrPos() - obj->getPrevPos() + (dt*dt) * obj->getForce();
        obj->modPos(new_pos);
    }
}

