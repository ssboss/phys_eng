#include "engine/engine.h"


constexpr float dt = 1.0f / 120.0f;
constexpr int width {1400};
constexpr int height {900};

int main(){
    World* sim {new World({5,5,5}, {-5,-5,-5}, dt)};
    Physics::Particle* test_obj1 {new Physics::Particle({0,0,0}, {1,0,0},5)};
    Physics::Particle* test_obj2 {new Physics::Particle({0.5,0,0}, {0,1,0},5)};
    sim->addObj(test_obj1);
    sim->addObj(test_obj2);
    renderObjects(width, height, sim); 
    return 0;
}