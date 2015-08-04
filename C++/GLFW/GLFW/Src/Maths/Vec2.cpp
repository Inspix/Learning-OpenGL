#include "Vec2.h"

namespace OpenGL {
	namespace Maths {
		Vec2::Vec2()
			: X(0), Y(0)
		{
			
		}
		Vec2::Vec2(const float x,const float y)
			: X(x), Y(y)
		{

		}

		Vec2::~Vec2() {

		}

		Vec2& Vec2::Normalize()
		{
			float length = Length();
			if (length != 0)
			{
				X /= length;
				Y /= length;
			}
			return *this;
		}

		Vec2 Vec2::Normalize(const Vec2& vector)
		{
			float lenght = vector.Length();
			Vec2 newVector;
			if (lenght != 0)
			{
				newVector = Vec2(vector.X / lenght, vector.Y / lenght);
			}
			return newVector;
		}

		float Vec2::Length() const
		{
			return sqrtf(X*X + Y*Y);
		}

		float Vec2::AngleRadians()
		{
			Vec2 normalized = Normalize(*this);
			return atan2(normalized.X, normalized.Y);
		}

		float Vec2::AngleDegrees() 
		{
			return this->AngleRadians() *(180 / 3.141592653589793f);
		}		

		Vec2& Vec2::operator+(const Vec2& other)
		{
			X += other.X;
			Y += other.Y;
			return *this;
		}

		Vec2& Vec2::operator-(const Vec2& other)
		{
			X -= other.X;
			Y -= other.Y;
			return *this;
		}

		Vec2& Vec2::operator++()
		{
			X++;
			Y++;
			return *this;
		}

		Vec2& Vec2::operator--()
		{
			X--;
			Y--;
			return *this;
		}

		Vec2& Vec2::operator*(const Vec2& other)
		{
			X *= other.X;
			Y *= other.Y;
			return *this;
		}

		Vec2& Vec2::operator*(const float& multValue)
		{
			X *= multValue;
			Y *= multValue;
			return *this;
		}

		Vec2& Vec2::operator/(const Vec2& other)
		{
			X /= other.X;
			Y /= other.Y;
			return *this;
		}

		Vec2 & Vec2::operator/(const float& divValue)
		{
			X /= divValue;
			Y /= divValue;
			return *this;
		}

		std::ostream& operator<<(std::ostream& os, const Vec2& vector)
		{
			os << "X: " << vector.X << " Y: " << vector.Y << std::endl;
			return os;
		}
		
	}

	
}
