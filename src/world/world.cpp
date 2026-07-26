#include "world.h"

World::World(Physics::Vector3D upper, Physics::Vector3D lower, float dt) : worldMax(upper), worldMin(lower), dt(dt){}

World::~World(){
    for(unsigned int i {0}; i < objs.size(); ++i){
        auto del {objs[i]};
        delete del;
        objs[i] = nullptr;
    }
}

Physics::Vector3D World::getLowerBounds() const {return worldMin;}

Physics::Vector3D World::getUpperBounds() const {return worldMax;}

void World::modLowBounds(Physics::Vector3D low){worldMin = low;}

void World::modUpBounds(Physics::Vector3D high){worldMax = high;}

void World::update(){
    for(unsigned int i {0}; i < objs.size(); ++i){
        Physics::accumulateForces(objs[i], forces, false);
        Physics::step(dt, objs[i]);
    }
}

void World::addForce(Physics::Vector3D force){
    forces.push_back(force);
}

void World::addObj(Physics::Particle* obj){
    objs.push_back(obj);
}

void World::remObj(Physics::Particle* obj){
    auto it {std::find(objs.begin(), objs.end(), obj)};
    auto del {*it};
    delete del;
    objs.erase(it);
}

const std::vector<Physics::Particle*>* World::getObjs() const {return &objs;}