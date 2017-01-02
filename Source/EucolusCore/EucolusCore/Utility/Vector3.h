#ifndef VECTOR3_H
#define VECTOR3_H

namespace Eucolus {
    class Vector3f {
    public:
        Vector3f();
		Vector3f(float x, float y, float z);
        ~Vector3f();

		float m_x;
		float m_y;
		float m_z;
    };

	class Vector3i {
	public:
		Vector3i();
		Vector3i(int x, int y, int z);
		~Vector3i();

		int m_x;
		int m_y;
		int m_z;
	};

	class Vector3ui {
	public:
		Vector3ui();
		Vector3ui(unsigned int x, unsigned int y, unsigned int z);
		~Vector3ui();

		unsigned int m_x;
		unsigned int m_y;
		unsigned int m_z;
	};
}

#endif