#include "vector3D.h"
#include "particle.h"
#include "dynamics.h"
#include "kinematics.h"
#include <vector>
#include <algorithm>

class World {
    public:
        World(Physics::Vector3D upperBound, Physics::Vector3D lowerBound, float dt);
        ~World();
        void update();
        void modUpBounds(Physics::Vector3D low);
        void modLowBounds(Physics::Vector3D high);
        Physics::Vector3D getUpperBounds() const;
        Physics::Vector3D getLowerBounds() const;
        void addForce(Physics::Vector3D force);
        void addObj(Physics::Particle* obj);
        void remObj(Physics::Particle* obj);
        const std::vector<Physics::Particle*>* getObjs() const;

    private:
        std::vector<Physics::Vector3D> forces; // global forces that affect the world
        std::vector<Physics::Particle*> objs;
        Physics::Vector3D worldMin;
        Physics::Vector3D worldMax;
        float dt;

        
};