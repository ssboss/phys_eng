#pragma once

#include "particle.h"



// bare for now i think i might need to add more once i move past this and get into collisions
namespace Physics {
    void step(float dt, Physics::Particle* obj, const Physics::Vector3D worldMax, const Physics::Vector3D worldMin);
    void BoundaryCheck(Physics::Particle* obj, const Physics::Vector3D worldMax, const Physics::Vector3D worldMin);
    void AxisReflection(float& curr, float& prev, float& force, float max, float min=0.0f);
}