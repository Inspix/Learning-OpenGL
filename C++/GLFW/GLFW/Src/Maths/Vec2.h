#pragma once

#include <iostream>

namespace OpenGL {
	namespace Maths {
		class Vec2
		{
		public:
			Vec2();
			Vec2(const float x, const float y);
			virtual ~Vec2();
			float X;
			float Y;


			Vec2& Normalize();
			Vec2 Normalize(const Vec2& vector);
			float Length() const ;
			float AngleRadians();
			float AngleDegrees();

			Vec2& operator +(const Vec2& other);
			Vec2& operator -(const Vec2& other);
			Vec2& operator ++();
			Vec2& operator --();
			Vec2& operator *(const Vec2& other);
			Vec2& operator *(const float& multValue);
			Vec2& operator /(const Vec2& other);
			Vec2& operator /(const float& divValue);
			

		};

		std::ostream& operator <<(std::ostream& os, const Vec2& vector);
		//static Vec2 Normalize(const Vec2& vector);
		//static float Length(const Vec2& vector);
	}
}


