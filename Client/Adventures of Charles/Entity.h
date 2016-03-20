#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    int posx;

public:
    Entity();
    virtual Draw();
    virtual Update();
};

#endif