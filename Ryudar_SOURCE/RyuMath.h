#pragma once


namespace Ryu::math
{
	struct Vector2
	{
		static const Vector2 One;
		static const Vector2 Zero;

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}

		Vector2& operator=(const Vector2& v)
		{
			x = v.x;
			y = v.y;

			return *this;
		}
	};
}