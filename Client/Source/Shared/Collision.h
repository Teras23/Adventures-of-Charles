#ifndef COLLISION_H
#define COLLISION_H
#include "../Shared/Util.h"
#include "../Shared/Entity.h"

class Collision {
private:
    static bool TestAABBCollision(Rect rect1, Rect retc2, float& moveX, float& moveY);
public:
    static float TestCollision(Entity* ent1, Entity* ent2);
    static float TestCollision(Entity* ent, Rect rect);
};

#endif