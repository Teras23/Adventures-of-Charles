#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

namespace Eucolus {
    class GameObject {
    public:
        GameObject();
        ~GameObject();

        virtual bool Init();
        virtual void Update();

    private:

    };
}

#endif