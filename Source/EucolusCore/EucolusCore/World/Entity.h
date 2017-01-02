#ifndef ENTITY_H
#define ENTITY_H
#include "GameObject.h"
#include "Component.h"

#include <vector>
#include <memory>

namespace Eucolus {
    class Entity : GameObject {
    public:
        Entity();
        ~Entity();

        bool Init();
        void Update();

    private:
        std::vector<std::shared_ptr<Component>> components;
    };
}

#endif