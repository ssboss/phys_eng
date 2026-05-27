#include "kinematics.h"
#include <vector>
// adding consts representing width and height of window
int const SCREEN_WIDTH = 800;
int const SCREEN_HEIGHT = 600;

void BoundaryCheck(Physics::Particle* obj);

/*
    Finished writing the object and particle classes, this is a test to try then out and test 
    1-D Kinematics before moving to 3-D implementation
*/

// calculates position based on acceleration and prev pos using Verlet Integration
namespace Physics {
    void step(double dt, Physics::Particle* obj){
        Physics::Vector3D new_pos {0.0,0.0,0.0};
        new_pos = 2 * obj->getCurrPos() - obj->getPrevPos() +  (dt*dt) * obj->getAccel();
        obj->modCurrPos(new_pos);
        BoundaryCheck(obj);
    }
    // checks boundary conditions and updates particle pos if it exceeds bounds of box/window
    void BoundaryCheck(Physics::Particle* obj){
        Physics::Vector3D velocity = obj->getCurrPos() - obj->getPrevPos();
        if(obj->getCurrPos().x < 0){
            obj->modCurrPos({0, obj->getCurrPos().y, obj->getCurrPos().z});
            obj->modPrevPos({velocity.x + obj->getCurrPos().x, obj->getPrevPos().y, obj->getPrevPos().z});
        }
        else if(obj->getCurrPos().x > SCREEN_WIDTH){
            obj->modCurrPos({SCREEN_WIDTH, obj->getCurrPos().y, obj->getCurrPos().z});
            obj->modPrevPos({velocity.x + obj->getCurrPos().x, obj->getPrevPos().y, obj->getPrevPos().z});
        }
        else if(obj->getCurrPos().y < 0){
            obj->modCurrPos({obj->getCurrPos().x, 0, obj->getCurrPos().z});
            obj->modPrevPos({obj->getPrevPos().x, obj->getPrevPos().y + velocity.y, obj->getPrevPos().z});
        }
        else if(obj->getCurrPos().y > SCREEN_HEIGHT){
            obj->modCurrPos({obj->getCurrPos().x, SCREEN_HEIGHT, obj->getCurrPos().z});
            obj->modPrevPos({obj->getPrevPos().x, obj->getPrevPos().y + velocity.y, obj->getPrevPos().z});
        }
    }
    }
    

