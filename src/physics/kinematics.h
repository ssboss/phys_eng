#pragma once

#include "particle.h"



// bare for now i think i might need to add more once i move past this and get into collisions
namespace Physics {
    void step(double dt, Physics::Particle* obj);
}