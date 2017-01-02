#ifndef Vector2f_H
#define Vector2f_H

namespace Eucolus {
    class Vector2f {
    public:
        Vector2f();
		Vector2f(float x, float y);
        ~Vector2f();

		float m_x;
		float m_y;
    };
}

#endif