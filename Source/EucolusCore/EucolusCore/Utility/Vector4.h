#pragma once

namespace Eucolus
{
	class Vector4f
	{
	public:
		Vector4f();
		Vector4f(float, float, float, float);
		~Vector4f();

		float m_x;
		float m_y;
		float m_z;
		float m_w;
	};
}
