#pragma once
#include "particle.h"
#include <vector>
// goal of this file is to do net force calculations for acceleration, including gravity, damping force, etc.
namespace Physics{
    void accumulateForces(Physics::Particle* obj, std::vector<Vector3D> forces, bool constAccel);
}