#include "particle/particle.h"
#include "physics/kinematics.h"
#include <vector>

const Physics::Vector3D gravity {0.0, -9.81, 0.0};

int main(){
    // std::vector<Physics::Particle*> objects;
    Physics::Particle* new_particle {new Physics::Particle({0.0,0.0,0.0}, gravity, 5.0)};
    double dt = 0.01;
    for(double i{0.00}; i < 1.00; i+=dt){
        Physics::step(dt, new_particle);
        std::cout << "Force: " << new_particle->getForce() << "\nnew position: " << new_particle->getCurrPos() << " prev position: " << new_particle->getPrevPos() << std::endl;
    }
}