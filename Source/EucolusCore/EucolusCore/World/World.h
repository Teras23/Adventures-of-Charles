#ifndef WORLD_H
#define WORLD_H
#include "GameObject.h"

#include <vector>
#include <memory>

namespace Eucolus {
    class World {
    public:
        World();
        ~World();

        bool Init();
        void Update();
        void Render();

    private:
        std::vector<std::shared_ptr<GameObject>> m_gameObjects;
    };
}

#endif