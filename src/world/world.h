#include "core.h"
#include "dynamics.h"
#include "kinematics.h"
#include <algorithm>

struct ObjHandle {
    Physics::Particle* obj;
    u_int32_t generation;
};

class World : public RenderInfo {
    public:
        World(Physics::Vector3D upperBound, Physics::Vector3D lowerBound, float dt);
        ~World();
        void update() override;
        void modUpBounds(Physics::Vector3D low);
        void modLowBounds(Physics::Vector3D high);
        const Physics::Vector3D getUpperBounds() const override;
        const Physics::Vector3D getLowerBounds() const override;
        void addForce(Physics::Vector3D force);
        void addObj(Physics::Particle* obj);
        void remObj(int id);
        const Physics::Vector3D getPos(int id) const override;
        const float getRadius(int id) const override;
        const unsigned int getCount() const override;
    private:
        std::vector<Physics::Vector3D> forces; // global forces that affect the world
        std::vector<ObjHandle> objs;
        Physics::Vector3D worldMin, worldMax;
        float dt;
        int width, height;
};
