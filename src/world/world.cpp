#include "world.h"

World::World(Physics::Vector3D upper, Physics::Vector3D lower, float dt) : worldMax(upper), worldMin(lower), dt(dt){}

World::~World(){}

Physics::Vector3D World::getLowerBounds(){return worldMin;}

Physics::Vector3D World::getUpperBounds(){return worldMax;}

void World::modLowBounds(Physics::Vector3D low){worldMin = low;}

void World::modUpBounds(Physics::Vector3D high){worldMax = high;}

void update(std::vector<Physics::Particle*> objs, float dt){
    for(unsigned int i {0}; i < objs.size(); ++i){
        Physics::accumulateForces(objs[i], {}, false);
    }
}