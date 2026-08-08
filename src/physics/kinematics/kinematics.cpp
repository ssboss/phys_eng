#include "kinematics.h"
#include <vector>
// adding consts representing width and height of window

void BoundaryCheck(Physics::Particle* obj);

/*
    Finished writing the object and particle classes, this is a test to try then out and test 
    1-D Kinematics before moving to 3-D implementation
*/

// calculates position based on acceleration and prev pos using Verlet Integration
namespace Physics {
    void step(float dt, Physics::Particle* obj, const Physics::Vector3D worldMax, const Physics::Vector3D worldMin){
        Physics::Vector3D new_pos {0.0,0.0,0.0};
        new_pos = 2 * obj->getCurrPos() - obj->getPrevPos() +  (dt*dt) * obj->getAccel();
        obj->modCurrPos(new_pos);
        BoundaryCheck(obj, worldMax, worldMin);
    }
    // checks boundary conditions and updates particle pos if it exceeds bounds of box/window
    void BoundaryCheck(Physics::Particle* obj, const Physics::Vector3D worldMax, const Physics::Vector3D worldMin){
       Physics::Vector3D curr{obj->getCurrPos()};
       Physics::Vector3D prev{obj->getPrevPos()};
       Physics::Vector3D force{obj->getForce()};

       AxisReflection(curr.x, prev.x, force.x, worldMax.x, worldMin.x);
       AxisReflection(curr.y, prev.y, force.y, worldMax.y, worldMin.y);
       AxisReflection(curr.z, prev.z, force.z, worldMax.z, worldMin.z);

       obj->modCurrPos(curr);
       obj->modPrevPos(prev);
       obj->modForce(force);
        
    }

    void AxisReflection(float& curr, float& prev, float& force, float max, float min){
        float vel {curr - prev};
        if(curr < min){
            curr = min;
            prev = curr + vel;
            force = -1 * force;
        }
        else if(curr > max){
            curr = max;
            prev = curr + vel;
            force = -1 * force;
        }
    }
}
    

