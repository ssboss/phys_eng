#include "particle.h"

namespace Physics{
    Particle::Particle(Vector3D present_pos,  Vector3D init_force, double init_mass) : curr_pos(present_pos), prev_pos(Vector3D{0.0,0.0,0.0}), force(init_force), mass(init_mass) {}
    Particle::~Particle(){}
    Vector3D Particle::getCurrPos(){return curr_pos;}
    Vector3D Particle::getPrevPos(){return prev_pos;}
    Vector3D Particle::getForce(){return force;}
    Vector3D Particle::getAccel(){return force / mass;}

    void Particle::modPos(Vector3D pos){
        prev_pos = curr_pos;
        curr_pos += pos;
    }

    void Particle::modForce(Vector3D added_force){force += added_force;}
    
}