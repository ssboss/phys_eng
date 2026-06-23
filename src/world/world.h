#include "vector/vector3D.h"
#include "particle/particle.h"
#include "physics/dynamics/dynamics.h"
#include <vector>

class World {
    public:
        World(Physics::Vector3D upperBound, Physics::Vector3D lowerBound, float dt);
        ~World();
        void update(std::vector<Physics::Particle*> objs, float dt);
        void modUpBounds(Physics::Vector3D low);
        void modLowBounds(Physics::Vector3D high);
        Physics::Vector3D getUpperBounds();
        Physics::Vector3D getLowerBounds();
        void addForce();
        void addObj();
        void remObj(Physics::Particle* obj);

    private:
        std::vector<Physics::Vector3D> forces;
        std::vector<Physics::Particle*> objs;
        Physics::Vector3D worldMin;
        Physics::Vector3D worldMax;
        float dt;

        
};