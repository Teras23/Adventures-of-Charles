#include "Collision.h"

bool Collision::TestAABBCollision(Rect rect1, Rect rect2, float& moveX, float& moveY) {
    //The difference between different edges
    float right = (rect1.x + rect1.w) - rect2.x;
    float left = rect1.x - (rect2.x + rect2.w);
    float top = rect1.y - (rect2.y + rect2.h);
    float bottom = (rect1.y + rect1.h) - rect2.y;

    if(right < 0 || left > 0 || top > 0 || bottom < 0) {
        return false;
    }

    //The distance you would need to move to not collide
    moveX = abs(left) < right ? left : right;
    moveY = abs(top) < bottom ? top : bottom;

    //Check which distance is smaller and return only that
    if(abs(moveX) > abs(moveY)) {
        moveX = 0.0f;
    }
    else {
        moveY = 0.0f;
    }

    return true;
}

float Collision::TestCollision(Entity* ent1, Entity* ent2) {
    float dis = 0.0f;

    float x = 0;
    float y = 0;

    Rect rect1 = Rect(ent1->GetPosition().x, ent1->GetPosition().y, 32, 32);
    Rect rect2 = Rect(ent2->GetPosition().x, ent2->GetPosition().y, 32, 32);

    float res = TestAABBCollision(rect1, rect2, x, y);

    Console::Print(std::to_string(res) + " " + std::to_string(x) + " " + std::to_string(y));

    return dis;
}

float Collision::TestCollision(Entity* ent, Rect rect) {
    float dis = 0.0f;

    return dis;
}