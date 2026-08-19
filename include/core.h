#pragma once

#include "vector3D.h"
#include "particle.h"
#include <vector>

class RenderInfo {
    public:
        virtual ~RenderInfo() = default;
        virtual void update() = 0;
        virtual const unsigned int getCount() const = 0;
        virtual const Physics::Vector3D getPos(int id) const = 0;
        virtual const float getRadius(int id) const = 0;
        virtual const Physics::Vector3D getUpperBounds() const = 0;
        virtual const Physics::Vector3D getLowerBounds() const = 0;
};


