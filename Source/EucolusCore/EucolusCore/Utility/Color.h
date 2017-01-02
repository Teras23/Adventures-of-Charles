#ifndef COLOR_H
#define COLOR_H

namespace Eucolus {

    class Color {
    public:
		Color();
		Color(int r, int b, int g);
		Color(int r, int b, int g, int a);
        ~Color();

		int m_r;
		int m_b;
		int m_g;
		int m_a;
    };

	class Colorf{
	public:
		Colorf();
		Colorf(float r, float b, float g);
		Colorf(float r, float b, float g, float a);
		~Colorf();

		float m_r;
		float m_b;
		float m_g;
		float m_a;
	};

	Colorf ToColorf(Color);
}

#endif