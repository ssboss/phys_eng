#include "dynamics.h"
namespace Physics{
    void accumulateForces(Physics::Particle* obj, std::vector<Vector3D> forces, bool constAccel){
        if (constAccel)
                return;

        Vector3D netForce {0.0f,0.0f,0.0f};

        for(unsigned int i {0}; i < (int)forces.size(); ++i){
            netForce += forces[i];
        }
        obj->modForce(netForce + obj->getForce());
    }
}