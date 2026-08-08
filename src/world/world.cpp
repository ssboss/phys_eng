#include "world.h"
#include "core.h"
#include "dynamics.h"
#include "kinematics.h"

World::World(Physics::Vector3D upper, Physics::Vector3D lower, float dt) : worldMax(upper), worldMin(lower), dt(dt){}

World::~World(){
    for(unsigned int i {0}; i < objs.size(); ++i){
        auto del {objs[i]};
        delete del.obj;
        del.obj = nullptr;
    }
}

const Physics::Vector3D World::getLowerBounds() const {return worldMin;}

const Physics::Vector3D World::getUpperBounds() const {return worldMax;}

const unsigned int World::getCount() const {return objs.size();}

void World::modLowBounds(Physics::Vector3D low){worldMin = low;}

void World::modUpBounds(Physics::Vector3D high){worldMax = high;}

void World::update(){
    for(unsigned int i {0}; i < objs.size(); ++i){
        Physics::accumulateForces(objs[i].obj, forces, false);
        Physics::step(dt, objs[i].obj, worldMax, worldMin); // rewrite later
    }
}

void World::addForce(Physics::Vector3D force){forces.push_back(force);}

void World::addObj(Physics::Particle* obj){objs.push_back({obj, 0});}

void World::remObj(int id){
    auto del {objs[id]};
    delete del.obj;
    del.obj = nullptr;
    del.generation++;
}

const Physics::Vector3D World::getPos(int id) const{return objs[id].obj->getCurrPos();}

const float World::getRadius(int id) const{return objs[id].obj->getRad();}


