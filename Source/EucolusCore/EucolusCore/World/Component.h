#ifndef COMPONENT_H
#define COMPONENT_H

namespace Eucolus {
    class Component {
    public:
        Component();
        ~Component();

        virtual bool Init();
        virtual void Update();

    private:
        
    };
}

#endif